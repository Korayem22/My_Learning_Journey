import pandas as pd
import random
import math
import matplotlib.pyplot as plt
class my_city:
    def __init__(self,name,x,y):
        self.name=name
        self.x = x
        self.y = y
        self.visited = False
    def visit(self):
        self.visited = True
########################
def read_data(path):
    cities_df=pd.read_csv(path)
    city_list=cities_df.values.tolist()
    return_list = []
    for city in city_list:
        new_city = my_city(city[0],city[1],city[2])
        return_list.append(new_city)
    return return_list
########################
def select_start_city(cities_list,index=-1): #returns index of start city
    random.seed(123)
    if index == -1: #random selection
        i = random.randint(0,len(cities_list)-1)
        return i
    else:
        return index%(len(cities_list)-1)
    # returns index of start city
#########################
def get_next_city(current_city_index,cities_list,start_point):
    min_distance = math.inf
    next_index = -1
    current_city = cities_list[current_city_index]
    start_city = cities_list[start_point]
    for index,city in enumerate(cities_list):
        if current_city_index == index or city.visited :
            continue
        else:
            distance = math.sqrt(((current_city.x -city.x)**2)+((current_city.y - city.y)**2))
        if distance < min_distance:
            min_distance=distance
            next_index = index
    if next_index == -1:
        min_distance = math.sqrt(((current_city.x -start_city.x)**2)+((current_city.y - start_city.y)**2))
        next_index = start_point
    return next_index,min_distance
    # returns index of next city and distance taken
########################
def plot_path(path,citis_list):
    x_points=[]
    y_points=[]
    for city in path:
        x_points.append(citis_list[int(city-1)].x)
        y_points.append(citis_list[int(city-1)].y)
    x_points.append(x_points[0])
    y_points.append(y_points[0])
    plt.plot(x_points,y_points,marker="o",color="r")
    plt.grid(True)
    plt.show()
######################
def tsp(file_path):
    cities_list = read_data(file_path)
    start=index = select_start_city(cities_list)
    cities_list[index].visit()
    distances=[]
    path = [cities_list[index].name]
    runs = len(cities_list)-1
    while runs>=0:
        index,distance=get_next_city(index,cities_list,start)
        path.append(cities_list[index].name)
        distances.append(distance)
        cities_list[index].visit()
        runs-=1
    print(path)
    print(sum(distances))
    plot_path(path,cities_list)
######################### 
tsp("13.Random_search/Labs/Lab1/Data_set.csv")