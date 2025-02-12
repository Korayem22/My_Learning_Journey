import pandas as pd
import numpy as np
import random
import math
import matplotlib.pyplot as plt

class Gene:
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
        new_Gene = Gene(city[0],city[1],city[2])
        return_list.append(new_Gene)
    return return_list
###########################

def create_cost_matrix(gene_list):
    rows, cols = (15, 15)
    cost_mat = [[0 for i in range(cols)] for j in range(rows)]
    for i,gene_i in enumerate(gene_list):
        for j,gene_j in enumerate(gene_list):
            cost_mat[i][j]= math.sqrt(((gene_i.x -gene_j.x)**2)+((gene_i.y - gene_j.y)**2))
    return cost_mat
    
genes = read_data("Data_set.csv")
cost_mat= create_cost_matrix(genes)

############################
class chromosome:
    def __init__(self,gene_list):
        self.my_genes = gene_list.copy()
        self.update_cost()

    def update_cost(self):
        cost = 0
        for idx,gene in enumerate(self.my_genes):
            if idx == len(self.my_genes)-1:
                cost += cost_mat[int(gene.name-1)][int(self.my_genes[0].name-1)]
            else:
                cost += cost_mat[int(gene.name-1)][int(self.my_genes[idx+1].name-1)]
        self.cost = cost
        self.fitness = 1/self.cost
    
    def shuffle(self):
        self.my_genes = list(np.random.permutation(self.my_genes))
        self.update_cost()
    
    def mutate(self):
        index1 = random.randint(0,len(self.my_genes)-1)
        index2 = random.randint(0,len(self.my_genes)-1)
        self.my_genes[index1], self.my_genes[index2] = self.my_genes[index2], self.my_genes[index1]
        self.update_cost()
###################################### 
class population:
    def __init__(self,size):
        self.init_pop =[]
        self.new_pop = []
        self.size = size
        for i in range(size):
            new_chromosome = chromosome(genes)
            new_chromosome.shuffle()
            self.init_pop.append(new_chromosome)
    def crossover(self,parent1,parent2):
        index1=random.randint(0,14)
        index2=random.randint(0,14)
        if index1>index2:
            index2,index1 = index1,index2
        child_list_1 = parent1.my_genes.copy()
        child_list_2 = parent2.my_genes.copy()
        for i in range(index1,index2+1):
            child_list_1[child_list_1.index(parent2.my_genes[i])]=child_list_1[i]
            child_list_1[i]=parent2.my_genes[i]
        for i in range(index1,index2+1):
            child_list_2[child_list_2.index(parent1.my_genes[i])]=child_list_2[i]
            child_list_2[i]=parent1.my_genes[i]
        child1 = chromosome(genes)
        child2 = chromosome(genes)
        child1.my_genes=child_list_1.copy()
        child2.my_genes=child_list_2.copy()
        child1.update_cost()
        child2.update_cost()
        return child1,child2
    def solve(self,generarions_size,mutation_rate,crossover_rate,elitism_rate):
        elitism_size = round(elitism_rate*self.size)
        mutation_size = round(mutation_rate*self.size)
        for i in range(generarions_size):
            self.init_pop.sort(key=lambda x:x.cost)
            for i in range(elitism_size):
                self.new_pop.append(self.init_pop[i])
            #print(self.new_pop[0].cost)
            while len(self.new_pop)<100:
                set1=random.sample(self.init_pop,5)
                set2=random.sample(self.init_pop,5)
                set1.sort(key=lambda x:x.cost)
                set2.sort(key=lambda x:x.cost)
                #print(list(map(lambda x:x.cost,set1)))
                child1,child2=self.crossover(set1[0],set2[0])
                prop = random.random()
                if prop < crossover_rate:
                    self.new_pop.append(child1)
                    self.new_pop.append(child2)
                else:
                    self.new_pop.append(set1[0])
                    self.new_pop.append(set2[0])
            for i in range(mutation_size):
                index=random.randint(elitism_size,self.size-1)
                self.new_pop[index].mutate()
            del self.init_pop
            self.init_pop=self.new_pop.copy()
            self.new_pop.clear()
        self.init_pop.sort(key=lambda x:x.cost)
        return self.init_pop[0]
    
###########################################################


pop = population(100)
res = pop.solve(5000,0.2,0.8,0.05)
print(list(map(lambda x:x.name,res.my_genes)),res.cost)