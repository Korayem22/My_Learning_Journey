#include <iostream>
using namespace std;
class Complex{
private:
    float real;
    float img;
public:
    Complex(){
        real=0;
        img=0;
        cout<<"default constructor"<<endl;
    }
    Complex(float n){
        real = img = n;
        cout<<"one argument constructor"<<endl;
    }
    Complex(float r , float i){
        real = r;
        img = i;
        cout<<"two argument constructor"<<endl;
    }
    ~Complex(){
        // delete any reserved memory;
        cout<<"destructor called"<<endl;
    }
    void setReal(float r);
    void setImg(float i);
    void setComplex(float r, float i);
    float getReal();
    float getImg();
    void print();
};
void Complex::setReal(float r){
    real=r;
}
void Complex::setImg(float i){
    img=i;
}
float Complex::getReal(){
    return real;
}
float Complex::getImg(){
    return img;
}
void Complex::print(){
    if(img<0){
        cout<<real<<" - "<<abs(img)<<"i\n"<<endl;
    }
    else{
        cout<<real<<" + "<<img<<"i\n"<<endl;
    }
}
Complex Add(Complex c1,Complex c2){
    Complex c3;
    c3.setReal(c1.getReal()+c2.getReal());
    c3.setImg(c1.getImg()+c2.getImg());
    return c3;
}
Complex Sub(Complex c1,Complex c2){
    Complex c3;
    c3.setReal(c1.getReal()-c2.getReal());
    c3.setImg(c1.getImg()-c2.getImg());
    return c3;
}
int main(){
    Complex mycomp3;
    Complex mycomp4(5);
    Complex mycomp5(9,25);
    mycomp3.print();
    mycomp4.print();
    mycomp5.print();
    float real,img;

    Complex resultComp=Add(mycomp4,mycomp5);
    resultComp.print();
    resultComp=Sub(mycomp4,mycomp5);
    resultComp.print();
    return 0;
}
