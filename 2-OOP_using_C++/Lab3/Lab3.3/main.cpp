#include <iostream>
using namespace std;
class Stack{
private:
    int tos;
    int stackSize;
    int *st;
    static int counter;
public:
    Stack(){
        tos = 0;
        stackSize = 10;
        st = new int[stackSize];
        counter++;
        cout<<"stack counter = "<<counter<<endl;
    }
    Stack(int n){
        tos = 0;
        stackSize = n;
        st = new int[stackSize];
        counter++;
        cout<<"stack counter = "<<counter<<endl;
    }
    ~Stack(){
        counter--;
        cout<<"stack counter = "<<counter<<endl;
        delete[] st;
    }
    friend void viewContent(Stack &x);
    void push(int);
    int pop();
    void print();
};
int Stack::counter=0;
void Stack::print(){
    for(int i = 0;i<tos;i++){
        cout<<st[i]<<endl;
    }
}
void Stack::push(int n){
    if (tos==stackSize){
        cout<<"Stack is full"<<endl;
    }
    else{
        st[tos]=n;
        tos++;
        //cout<<"tos ++"<<endl;
    }
}
int Stack::pop(){
    int ret;
    if (tos==0){
        cout<<"Stack is empty"<<endl;
        ret=-1;
    }
    else{
        tos--;
        ret=st[tos];
    }
    return ret;
}
void viewContent(Stack &x){
    int t=x.tos;
    while(t!=0)
        cout<<x.st[--t]<<endl;
}
int main(){
    Stack s1(5);
    s1.push(5);
    s1.push(14);
    s1.push(20);
    s1.push(22);
    s1.push(55);
    viewContent(s1);
    return 0;
}
