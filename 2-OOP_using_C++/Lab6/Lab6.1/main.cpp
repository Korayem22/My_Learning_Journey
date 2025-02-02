#include <iostream>

using namespace std;
class Base{
private:
    int a;
    int b;
public:
    Base(){
        a=b=0;
    }
    Base(int n){
        a=b=n;
    }
    Base(int x,int y){
        a=x;
        b=y;
    }
    void setA(int x){
        a=x;
    }
    void SetB(int x){
        b=x;
    }
    int getA(){
        return a;
    }
    int getB(){
        return b;
    }
    int product(){
        return a*b;
    }
};
class Derived : public Base{
protected:
    int c;
public:
    Derived():Base(){
        c=0;
    }
    Derived(int n):Base(n){
        c=n;
    }
    Derived(int x, int y, int z):Base(x,y){
        c=z;
    }
    void setC(int x){
        c=x;
    }
    int getC(){
        return c;
    }
    int product(){
        return getA()*getB()*c;
    }
};
class SecDerived :public Derived{
private:
    int d;
public:
    SecDerived():Derived(){
        d=0;
    }
    SecDerived(int n):Derived(n){
        d=n;
    }
    SecDerived(int x,int y, int z, int i):Derived(x,y,z){
        d=i;
    }
    int product(){
        return Derived::product()*d;
    }
};

int main()
{
    SecDerived child_2(3,4,2,5);
    Derived *p = &child_2;
    cout<<"product from derived using a pointer:"<<p->product()<<endl;
    cout<<"product from 2nd derived :"<<child_2.product()<<endl;
    cout<<"product from derived :"<<child_2.Derived::product()<<endl;
    cout<<"product from Base derived :"<<child_2.Base::product()<<endl;
    return 0;
}
