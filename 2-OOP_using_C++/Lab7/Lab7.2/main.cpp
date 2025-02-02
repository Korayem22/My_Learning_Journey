#include <iostream>

using namespace std;
template <class T>
class Stack{
private:
    int tos;
    int stackSize;
    T *st;
    static int counter;
public:
    static int getCounter();
    Stack(){
        tos = 0;
        stackSize = 10;
        st = new T[stackSize];
        counter++;
        //cout<<"stack counter = "<<counter<<endl;
    }
    Stack(int n){
        tos = 0;
        stackSize = n;
        st = new T[stackSize];
        counter++;
        //cout<<"stack counter = "<<counter<<endl;
    }
    Stack( Stack &z);
    ~Stack(){
        counter--;
        //cout<<"stack counter = "<<counter<<endl;
        delete[] st;
    }
    void push(T);
    T pop();
    void print();
    Stack& operator = (const Stack &s);
};
template <class T>
int Stack<T>::counter=0;
template <class T>
int Stack<T>::getCounter(){
    return counter;
}
template <class T>
Stack<T>::Stack(Stack &z){
    tos=z.tos;
    stackSize=z.stackSize;
    st = new int[stackSize];
    for(int i=0;i<tos;i++)
        st[i]=z.st[i];
    counter++;
    cout<<"stack counter (in copy) = "<<counter<<endl;
}
template <class T>
void Stack<T>::print(){
    for(int i = 0;i<tos;i++){
        cout<<st[i]<<endl;
    }
}
template <class T>
void Stack<T>::push(T n){
    if (tos==stackSize){
        cout<<"Stack is full"<<endl;
    }
    else{
        st[tos]=n;
        tos++;
        //cout<<"tos ++"<<endl;
    }
}
template <class T>
T Stack<T>::pop(){
    T ret;
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

int main()
{
    Stack<int> s1(5);
    cout<<"number of int stacks is : "<<Stack<int>::getCounter()<<endl;
    Stack<char> ch1(3);
    Stack<char> ch2(4);
    cout<<"number of char stacks is : "<<Stack<char>::getCounter()<<endl;
    s1.push(3);
    s1.push(5);
    s1.print();
    cout<<"1st int is :"<<s1.pop()<<endl;
    ch1.push('o');
    ch1.push('k');
    ch1.print();
    return 0;
}
