#include <iostream>
using namespace std;
class Stack{
private:
    int tos;
    int stackSize;
    int *st;
public:
    Stack(){
        tos = 0;
        stackSize = 10;
        st = new int[stackSize];
    }
    Stack(int n){
        tos = 0;
        stackSize = n;
        st = new int[stackSize];
    }
    ~Stack(){
        delete[] st;
    }
    void push(int);
    int pop();
    void print();
};
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
int main(){
    Stack s1(2);
    s1.push(5);
    s1.push(14);
    s1.push(20);
    s1.print();
    cout<<"pop result = "<<s1.pop()<<endl;
    Stack s2;
    s2.push(13);
    s2.push(146);
    s2.push(349);
    s2.print();

    return 0;
}
