class hist:
    def __init__(self):
        self.my_set = []
        self.unique = []
    def add_number(self,value):
        if value > 10 or value <=0:
            print('you entered value out of range, 1 to 1, try again\n')
        elif len(self.my_set) == 100:
            print('max list size reached can not add extra numbers')
        else:
            self.my_set.append(value)
            if value not in self.unique:
                self.unique.append(value)
    def generate_histogram(self):
        self.my_set.sort()
        self.unique.sort()
        frequs = {}
        for value in self.unique:
            freq = self.my_set.count(value)
            frequs[value]=freq
        line = ''
        for key in frequs.keys():
            line=line+str(key)+':'+('*'*frequs[key])+'\n'
        return line

my_hist = hist()
my_hist.add_number(2)
my_hist.add_number(2)
my_hist.add_number(5)
my_hist.add_number(1)
my_hist.add_number(2)
# my_hist.add_number(0)
# for i in range(100):
#     my_hist.add_number(3)
print(my_hist.generate_histogram())