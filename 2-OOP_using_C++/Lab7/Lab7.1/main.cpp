#include <iostream>
using namespace std;
class GeoShape{
protected:
    float d1;
    float d2;
public:
    virtual float calculateArea()=0;
    GeoShape(){
        d1 = d2 = 0;
        cout<<"GeoShape Const."<<endl;
    }
    GeoShape(float n){
        d1 = d2 = n;
        cout<<"GeoShape Const."<<endl;
    }
    GeoShape(float x, float y){
        d1 = x;
        d2 = y;
        cout<<"GeoShape Const."<<endl;
    }
    ~GeoShape(){
        cout<<"GeoShape DeConst"<<endl;
    }
    void setd1(float x){
        d1 = x;
    }
    void setd2(float x){
        d2 = x;
    }
    float getd1(){
        return d1;
    }
    float getd2(){
        return d2;
    }
};
class Triangle : public GeoShape{
public:
    Triangle():GeoShape(){
        cout<<"Triangle Const."<<endl;
    }
    Triangle(float n):GeoShape(n){
        cout<<"Triangle Const."<<endl;
    }
    Triangle(float x,float y):GeoShape(x,y){
        cout<<"Triangle Const."<<endl;
    }
    float calculateArea(){
        return GeoShape::d1*GeoShape::d2*0.5;
    }
    ~Triangle(){
        cout<<"Triangle DeConst."<<endl;
    }
};
class Rect : public GeoShape{
public:
    Rect():GeoShape(){
        cout<<"Rect Const."<<endl;
    }
    Rect(float x,float y):GeoShape(x,y){
        cout<<"Rect Const."<<endl;
    }
    float calculateArea(){
        return GeoShape::d1*GeoShape::d2;
    }
    ~Rect(){
        cout<<"Rect DeConst."<<endl;
    }
};
class Square : public Rect{
public:
    Square():Rect(){
        cout<<"Square Const."<<endl;
    }
    Square(float x):Rect(x,x){
        cout<<"Square Const."<<endl;
    }
    float calculateArea(){
        return Rect::d1*Rect::d1;
    }
    ~Square(){
        cout<<"Square DeConst."<<endl;
    }
};
class Circle : public GeoShape{
public:
    Circle():GeoShape(){
        cout<<"Circle Const."<<endl;
    }
    Circle(int n):GeoShape(n){
        cout<<"Circle Const."<<endl;
    }
    ~Circle(){
        cout<<"Circle DeConst."<<endl;
    }
    float calculateArea(){
        return 3.14*GeoShape::d1*GeoShape::d1;
    }
};
float sumOfAreas(GeoShape* ptr,GeoShape* ptr2,GeoShape* ptr3){
    return ptr->calculateArea()+ptr2->calculateArea()+ptr3->calculateArea();
}
int main(){
    //GeoShape geo(3,3);
    Circle cr(3);
    Square sq(4);
    Rect re(3,4);
    Triangle tri(3,4);
    GeoShape *tri_ptr = &tri;
    GeoShape *re_ptr = &re;
    GeoShape *sq_ptr = &sq;
    GeoShape *cr_ptr = &cr;
    cout<<"Area of triangle is : "<<tri_ptr->calculateArea()<<endl;
    cout<<"Area of rect is : "<<re_ptr->calculateArea()<<endl;
    cout<<"Area of square is : "<<sq_ptr->calculateArea()<<endl;
    cout<<"Area of circle is : "<<cr_ptr->calculateArea()<<endl;
    cout<<"sum of areas of triangle, square & circle is : "<<sumOfAreas(tri_ptr,sq_ptr,cr_ptr)<<endl;
    return 0;
}
