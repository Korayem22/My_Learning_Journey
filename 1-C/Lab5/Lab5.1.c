#include <stdio.h>
struct employee{
    int id;
    int salary;
    char name[40];
};
struct employee new_employee();
void print_employee(struct employee);
int main(){
    struct employee e1=new_employee();
    print_employee(e1);
    return 0;
}
struct employee new_employee(){
    struct employee employee1;
    printf("\n please enter employee's ID: ");
    scanf(" %d",&employee1.id);
    printf("\n please enter employee's Name: ");
    scanf(" %[^\n]s",employee1.name);
    printf("\n please enter employee's salary: ");
    scanf(" %d",&employee1.salary);
    return employee1;
}
void print_employee(struct employee employee1){
    printf("\n\nEmployee's name is %s and his net salary is %d\n\n",employee1.name,employee1.salary);
}
