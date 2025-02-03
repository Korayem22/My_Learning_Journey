#include <iostream>
using namespace std;
class Complex{
private:
    float real;
    float img;
public:
    void setReal(float r);
    void setImg(float i);
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
    Complex myComp1,myComp2,resultComp;
    float real,img;
    cout <<"\nenter the Real part of complex 1 : ";
    cin>>real;
    cout <<"\nenter the Imaginary part of complex 1 : ";
    cin>>img;
    myComp1.setReal(real);
    myComp1.setImg(img);
    cout <<"\nenter the Real part of complex 2 : ";
    cin>>real;
    cout <<"\nenter the Imaginary part of complex 2 : ";
    cin>>img;
    myComp2.setReal(real);
    myComp2.setImg(img);
    myComp1.print();
    myComp2.print();
    resultComp=Add(myComp1,myComp2);
    resultComp.print();
    resultComp=Sub(myComp1,myComp2);
    resultComp.print();
    return 0;
}
