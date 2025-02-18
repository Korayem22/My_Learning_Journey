import pandas as pd
import numpy as np
import random
import math
import matplotlib.pyplot as plt

class City:
    def __init__(self,name,x,y):
        self.name=name
        self.x = x
        self.y = y
########################

def read_data(path):
    cities_df=pd.read_csv(path)
    city_list=cities_df.values.tolist()
    return_list = []
    for city in city_list:
        new_city = City(city[0],city[1],city[2])
        return_list.append(new_city)
    return return_list
###########################

def create_cost_matrix(gene_list):
    rows, cols = (15, 15)
    cost_mat = [[0 for i in range(cols)] for j in range(rows)]
    for i,gene_i in enumerate(gene_list):
        for j,gene_j in enumerate(gene_list):
            cost_mat[i][j]= math.sqrt(((gene_i.x -gene_j.x)**2)+((gene_i.y - gene_j.y)**2))
    return cost_mat
###########################
def create_pheromone_matrix(cost_mat):
    rows, cols = (15, 15)
    L = np.mean(cost_mat) * rows 
    tau_0 = 1 / (rows * L)
    pheromone_mat = [[0 for i in range(cols)] for j in range(rows)]
    for i in range(rows):
        for j in range(cols):
            if i==j:
                pheromone_mat[i][j]=0
            else:
                pheromone_mat[i][j]=tau_0
    return pheromone_mat
############################
def create_quali_mat(cost_mat):
    quali_mat = np.zeros((15,15))
    for i in range(15):
        for j in range(15):
            if i==j:
                pass
            else:
                quali_mat[i][j]=1/cost_mat[i][j]
    return quali_mat
############################
class Ant:
    def __init__(self,city_list):
        self.my_cities = city_list.copy()
        self.options = self.my_cities.copy()
        self.tour=[]
        self.Tour(alpha,beta)
        self.update_cost()
    def Tour(self,alpha,beta):
        self.tour = [] 
        start = np.random.randint(0,15)
        self.tour.append(self.options.pop(start))
        for i in range(14):
            probs=[]
            prob_full_row = pheromone_mat[int(self.tour[-1].name)-1]
            denom = 0
            for city in self.options:
                denom+=(prob_full_row[int(city.name)-1]**alpha)*(quali_mat[int(self.tour[-1].name)-1][int(city.name)-1]**beta)
            for city in self.options:
                probs.append(((prob_full_row[int(city.name)-1]**alpha)*(quali_mat[int(self.tour[-1].name)-1][int(city.name)-1])**beta)/denom)
            choice = np.random.choice(self.options,p=probs)
            self.tour.append(choice)
            self.options.remove(choice)
            probs.clear()
        self.options=self.my_cities.copy()
        self.update_cost()
    def update_cost(self):
        cost = 0
        for idx,city in enumerate(self.tour):
            if idx == len(self.tour)-1:
                cost += cost_mat[int(city.name)-1][int(self.tour[0].name-1)]
            else:
                cost += cost_mat[int(city.name)-1][int(self.tour[idx+1].name-1)]
        self.cost = cost
        self.fitness = 1/self.cost
##########################################
class Population:
    def __init__(self,size):
        self.ants=[]
        for i in range(size):
            ant = Ant(Cities)
            self.ants.append(ant)
        #print(self.ants)
    def update_phermone_mat(self,pheromone_mat,p):
        update_mat=np.zeros((15,15))
        for ant in self.ants:
            for idx,city in enumerate(ant.tour):
                if idx < 14:
                    current = int(city.name)-1
                    next = int(ant.tour[idx+1].name-1)
                    update_mat[current][next]+=1/ant.cost
                else:
                    current = int(city.name)-1
                    next = int(ant.tour[0].name-1)
                    update_mat[current][next]+=1/ant.cost
        pheromone_mat = (1-p)*pheromone_mat + update_mat
    def solve(self,max_iters):
        i=0
        while i <= max_iters:
            for ant in self.ants:
                ant.Tour(alpha,beta)
            self.update_phermone_mat(pheromone_mat,p)
            i+=1
        self.ants.sort(key=lambda x:x.cost)
        return self.ants[0]
        
                    
###########################################
Cities = read_data("Data_set.csv")
cost_mat= np.array(create_cost_matrix(Cities))
quali_mat = create_quali_mat(cost_mat)
pheromone_mat = np.array(create_pheromone_matrix(cost_mat))
alpha = 1
beta = 3
p=0.3
my_colony = Population(100)
sol = my_colony.solve(1000)
final_tour = list(map(lambda x:x.name,sol.tour))
print(final_tour,sol.cost)