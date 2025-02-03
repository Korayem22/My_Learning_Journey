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
        //cout<<"default constructor"<<endl;
    }
    Complex(float n){
        real = img = n;
        //cout<<"one argument constructor"<<endl;
    }
    Complex(float r , float i){
        real = r;
        img = i;
        //cout<<"two argument constructor"<<endl;
    }
    ~Complex(){
        // delete any reserved memory;
        //cout<<"destructor called"<<endl;
    }
    void setReal(float r);
    void setImg(float i);
    void setComplex(float r, float i);
    float getReal();
    float getImg();
    void print();
    Complex operator+(Complex);
    Complex operator-(Complex);
    Complex operator+(float);
    Complex operator-(float);
    friend Complex operator+(float, Complex);
    friend Complex operator-(float, Complex);
    Complex operator +=(Complex);
    int operator==(Complex);
    Complex operator++();
    Complex operator++(int);
    Complex operator--();
    Complex operator--(int);
    operator float();
};
Complex Complex::operator++(){
    real++;
    return *this;
}
Complex Complex::operator--(){
    real--;
    return *this;
}
Complex Complex::operator++(int){
    Complex temp = *this;
    real++;
    return temp;
}
Complex Complex::operator--(int){
    Complex temp = *this;
    real--;
    return temp;
}
Complex::operator float(){
    return real;
}
int Complex::operator==(Complex c){
    if(real==c.real && img==c.img)
        return 1;
    else
        return 0;
}
Complex Complex::operator+=(Complex c){
    this->setReal(this->getReal() + c.real);
    this->setImg(this->getImg() +c.img);
}
Complex Complex::operator+(Complex c){
    Complex b;
    b.real = real + c.real;
    b.img = img + c.img;
    return b;
}
Complex Complex::operator-(Complex c){
    Complex b;
    b.real = real - c.real;
    b.img = img - c.img;
    return b;
}
Complex Complex::operator+(float x){
    Complex b;
    b.real = real + x;
    b.img = img;
    return b;
}
Complex Complex::operator-(float x){
    Complex b;
    b.real = real - x;
    b.img = img;
    return b;
}
Complex operator+(float x, Complex c){
    Complex b;
    b.real = c.real + x;
    b.img = c.img;
    return b;
}
Complex operator-(float x, Complex c){
    Complex b;
    b.real = x-c.real;
    b.img = c.img;
    return b;
}
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
    Complex c1(2);
    Complex c2(3);
    c1.print();
    c2.print();
    Complex c3;
    c3.print();
    c3 = c1+c2;
    c3.print();
    c3 = c1-c2;
    c3.print();
    c3 = c1+5;
    c3.print();
    c3 = c1-5;
    c3.print();
    c3 = 5 + c1;
    c3.print();
    c3 = 5 - c1;
    c3.print();
    cout<<(c1==c2)<<endl;
    c1 += c2;
    c1.print();
    cout<<++c1<<endl;
    c1.print();
    cout<<--c1<<endl;
    c1.print();
    cout<<c1++<<endl;
    c1.print();
    cout<<c1--<<endl;
    c1.print();
    cout<<(float) c1<<endl;
}
