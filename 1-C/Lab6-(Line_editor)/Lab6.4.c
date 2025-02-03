#include <stdio.h>
#include <stdlib.h>
typedef struct employee{
    int id;
    int salary;
    char name[20];
}employee;
void add_employee_arr(employee *e,int*size);
void print_employee(employee *e,int*size);
int main(){
    int size;
    employee *e_arr;
    printf("please enter number of employees : ");
    scanf("%d",&size);
    e_arr =(employee*)malloc(size*(sizeof(employee)));
    add_employee_arr(e_arr,&size);
    print_employee(e_arr,&size);
    free(e_arr);
    return 0;
}
void add_employee_arr(employee *e,int*size){
    for(int i =0;i<*size;i++){
        printf("\nplease enter employee%d's id : ",i+1);
        scanf(" %d",&(e[i].id));
        printf("\nplease enter employee%d's salary : ",i+1);
        scanf(" %d",&(e[i].salary));
        printf("\nplease enter employee%d's name : ",i+1);
        scanf(" %s",(e[i].name));
    }
}
void print_employee(employee *e,int*size){
    printf("*********************************");
    for(int i =0;i<*size;i++){
        printf("\nemployee%d's id : %d",i+1,e[i].id);
        printf("\nemployee%d's salary : %d",i+1,e[i].salary);
        printf("\nenter employee%d's name : %s",i+1,e[i].name);
    }
}
