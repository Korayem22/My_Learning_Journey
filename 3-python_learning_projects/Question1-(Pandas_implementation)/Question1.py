from functools import reduce
def read_dtype(path):
    file = open(path)
    lines = file.readlines()
    file.close()
    del lines[0]
    dtype_dict = {}
    for line in lines:
        line = line[:-1]
        arr = line.split(',')
        dtype_dict[arr[0]]=arr[1]
    return dtype_dict
#############################
def read_csv(path,dtype_dict):
    file = open(path)
    data_headers = file.readline()
    data_headers = data_headers[:-1]
    data_headers = data_headers.split(',')
    data_lines = file.readlines()
    file.close()
    lines = []
    data = {}
    for col in data_headers:
        data[col] = []
    for line in data_lines:
        line = line[:-1]
        lines.append(line.split(','))
    for line in lines:
        for idx,key in enumerate(data.keys()):
            type = dtype_dict[key]
            if line[idx] == '':
                line[idx] = None
            elif type == 'int':
                line[idx] = int(line[idx])
            elif type == 'float':
                line[idx] = float(line[idx])
            else:
                line[idx] = str(line[idx])
        for idx,col in enumerate(data_headers):
            data[col].append(line[idx])
    return data
########################################
def count_nulls(data):
    nulls_dict ={}
    for key in data.keys():
        count = data[key].count(None)
        nulls_dict[key]=count
    return nulls_dict
#######################################
def get_col_max(arr):
    arr = list(filter(lambda x:x!=None,arr))
    def func(x,y):
        if x>y:
            return x
        else:
            return y
    return reduce(func,arr)
#######################################
def get_col_min(arr):
    arr = list(filter(lambda x:x!=None,arr))
    def func(x,y):
        if x<y:
            return x
        else:
            return y
    return reduce(func,arr)
#######################################
def get_col_mean(arr):
    arr = list(filter(lambda x:x!=None,arr))
    return reduce(lambda x,y:x+y,arr)/len(arr)
#######################################
def get_col_median(arr):
    arr = list(filter(lambda x:x!=None,arr))
    arr.sort()
    L = len(arr)
    if L%2==0:
        return ((arr[int(L/2)]+arr[int((L/2)-1)])/2)
    else:
        return ((arr[int(L//2)]))
#######################################
def get_col_mode(arr):
    arr = list(filter(lambda x:x!=None,arr))
    arr.sort()
    mode = 0
    count = 1
    max_count = 0
    for i in range(len(arr)):
        if i == 0:
            continue
        else:
            if arr[i] == arr[i-1]:
                count+=1
            else:
                if count>max_count:
                    max_count=count
                    mode = arr[i-1]
                count=1
    return mode
#######################################
def get_stat(data,dtype_dict,func):
    stat_dict={}
    for key in dtype_dict.keys():
        if dtype_dict[key] in ['int','float']:
            stat_dict[key] = func(data[key])
    return stat_dict
#######################################
def write_stats(path,data,dtype_dict):
    file = open(path,'x')
    cols = dtype_dict.keys()
    header = "column,nulls,max,min,mean,median,mode\n"
    file.write(header)
    null_dict= count_nulls(data)
    for col in cols:
        if dtype_dict[col] in ['int','float']:
            line = col+','
            line = line+str(null_dict[col])+','
            line = line+str(get_col_max(data[col]))+','
            line = line+str(get_col_min(data[col]))+','
            line = line+str(get_col_mean(data[col]))+','
            line = line+str(get_col_median(data[col]))+','
            line = line+str(get_col_mode(data[col]))+'\n'
            file.write(line)
        else:
            line = col+','
            line = line+str(null_dict[col])+(',,'*5)+'\n'
            file.write(line)
    file.close()
######################################################
def fillna(data,dtype_dict,num_strategy,cat_startegy):
    for key in data.keys():
        if dtype_dict[key]=='string':
            filler = cat_startegy(data[key])
            for idx,word in enumerate(data[key]):
                if word == None:
                    data[key][idx] = filler
        else:
            filler = num_strategy(data[key])
            for idx,num in enumerate(data[key]):
                if num == None:
                    data[key][idx] = filler
######################################################
def write_file(path,data):
    file = open(path,'x')
    line =''
    key_len = 0
    for key in data.keys():
        line = line+str(key)+','
        key_len = len(data[key])
    line = line[:-1]+'\n'
    file.write(line)
    for i in range(key_len):
        line = ''
        for key in data.keys():
            line = line+str(data[key][i])+','
        line = line[:-1]+'\n'
        file.write(line)
######################################################

dtype_dict = read_dtype('titanic_dtype.csv')
data = (read_csv('titanic.csv',dtype_dict))
write_stats("stats_file.csv",data,dtype_dict)
fillna(data,dtype_dict,get_col_median,get_col_mode)
write_file('out_titanic.csv',data)
