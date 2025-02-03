#include <iostream>
using namespace std;
void swap_val(int x,int y);
void swap_ref(int &x,int &y);
void swap_add(int *x,int*y);
int main(){
    int x=15,y=10;
    cout<<" before swapping x = "<<x<<" and y = "<<y<<endl;
    swap_val(x,y);
    cout<<" after swapping by value x = "<<x<<" and y = "<<y<<endl;
    swap_ref(x,y);
    cout<<" after swapping by reference x = "<<x<<" and y = "<<y<<endl;
    swap_add(&x,&y);
    cout<<" after swapping by address x = "<<x<<" and y = "<<y<<endl;

    return 0;
}
void swap_val(int x,int y){
    int temp = x;
    x=y;
    y=temp;
}
void swap_ref(int &x,int &y){
    int temp = x;
    x=y;
    y=temp;
}
void swap_add(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
