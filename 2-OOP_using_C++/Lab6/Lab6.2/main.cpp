#include <iostream>
using namespace std;
class Point{
private:
    int x;
    int y;
public:
    Point(){
        cout<<" in point const."<<endl;
        x=0;
        y=0;
    }
    Point(int m, int n){
        cout<<" in point const."<<endl;
        x=m;
        y=n;
    }
    ~Point(){
    cout<<" in point deconst."<<endl;
    }
    void setX(int m){
        x=m;
    }
    void setY(int n){
        y=n;
    }
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }

};
class Shape{
protected:
    int color;
public:
    Shape(){
        color =0;
        cout<<"Shape Const."<<endl;
    }
    Shape(int n){
        cout<<"Shape Const."<<endl;
        color = n;
    }
    void print(){
        cout<<"printing shape class"<<endl;
    }
    ~Shape(){
        cout<<"Shape deconst."<<endl;
    }
    void setColor(int x){
        color = x;
    }
    int getColor(){
        return color;
    }
};
class Line: public Shape{
private:
    Point start;
    Point end_;
public:
    Line():start(),end_(),Shape(){
        cout<<"in Line const."<<endl;
    }
    Line(int c,int x1, int y1, int x2,int y2): start(x1,y1),end_(x2,y2),Shape(c){
        cout<<"in Line const."<<endl;
    }
    ~Line(){
        cout<<"in Line deconst."<<endl;
    }
    void print(){
        cout<<"this line runs from point ("<<start.getX()<<","<<start.getY()<<") to point ("<<end_.getX()<<","<<end_.getY()<<")"<<" and its color is"<<Shape::getColor()<<endl;
    }
};
class Rect: public Shape{
private:
    Point ul;
    Point lr;
public:
    Rect():Shape(),ul(),lr(){
        cout<<"in Rect const."<<endl;
    }
    Rect(int c,int x1,int y1, int x2,int y2):Shape(c),ul(x1,y1),lr(x2,y2){
        cout<<"in Rect const."<<endl;
    }
    ~Rect(){
        cout<<"in Rect deconst."<<endl;
    }
    void print(){
        cout<<"this rect hast two edges at point ("<<ul.getX()<<","<<ul.getY()<<") and point ("<<lr.getX()<<","<<lr.getY()<<")"<<"and its color is "<<Shape::getColor()<<endl;
    }
};
class Circle:public Shape{
private:
    Point center;
    int radius;
public:
    Circle():center(),Shape(){
        cout<<"in circle const."<<endl;
    }
    Circle(int c,int m,int n,int r):center(m,n),Shape(c){
        radius = r;
        cout<<"in circle cons. "<<endl;
    }
    ~Circle(){
        cout<<"in circle deconst."<<endl;
    }
    void print(){
        cout<<"this circle has a center at point ("<<center.getX()<<","<<center.getY()<<") and a radius of "<<radius<<"and its color is"<<Shape::getColor()<<endl;
    }
};
class Picture{
private:
    int cNum;
    int rNum;
    int lNum;
    Circle *pCircles;
    Rect *pRects;
    Line *pLines;
public:
    Picture(){
        cNum=0;
        rNum=0;
        lNum=0;
        pCircles=NULL;
        pRects=NULL;
        pLines=NULL;
        cout<<"in picture const."<<endl;
    }
    Picture(int cn,int rn, int ln,Circle *pC, Rect *pR, Line *pL){
        cNum=cn;
        rNum=rn;
        lNum=ln;
        pCircles=pC;
        pRects=pR;
        pLines=pL;
        cout<<"in picture const."<<endl;
    }
    ~Picture(){
        cout<<"in picture deconst."<<endl;
    }
    void setCircles(int cn,Circle *pC){
        cNum = cn;
        pCircles = pC;
    }
    void setRects(int rn,Rect *pR){
        rNum = rn;
        pRects = pR;
    }
    void setLines(int ln,Line *pL){
        lNum = ln;
        pLines = pL;
    }
    void paint(){
        int i;
        for(i=0;i<cNum;i++){
            pCircles[i].print();
        }
        for(i=0;i<rNum;i++){
            pRects[i].print();
        }
        for(i=0;i<lNum;i++){
            pLines[i].print();
        }
    }
};
int main(){

    Picture myPic;
    Circle cArr[3]={Circle(1,50,50,50),Circle(2,200,100,100),Circle(3,420,50,30)};
    Rect rArr[2]={Rect(3,30,40,170,100),Rect(1,420,50,500,300)};
    Line lArr[2]={Line(2,420,50,300,300),Line(1,40,500,500,400)};
    myPic.setCircles(3,cArr);
    myPic.setRects(2,rArr);
    myPic.setLines(2,lArr);
    lArr[1].Shape::print();
    myPic.paint();
    cout<<"****************************************"<<endl;
    /*
    Picture myPic2;
    Circle cArr2[3]={Circle(50,50,50), Circle(200,100,100), Circle(420,50,30)};
     Rect rArr2[2] ;
    rArr2[0] = Rect(30,40,170,100) ;
    Point myP1(420,50) ;
    Point myP2(500,300) ;
    rArr2[1] = Rect(myP1, myP2);
    myPic2.setCircles(3,cArr2);
    myPic2.setRects(2,rArr2);
    myPic2.paint();
    cout<<"****************************************"<<endl;

    Picture myPic3;
    Line * lArr3 ;
    lArr3 = new Line[2] ;
    lArr3[0] = Line(Point(420,50),Point(300,300)) ;
    lArr3[1] = Line(40,500,500,400) ;
    //myPic3.setCircles(3,cArr) ;
    //myPic3.setRects(2,rArr) ;
    myPic3.setLines(2,lArr3) ;
    myPic3.paint() ;
    delete[] lArr3;
    */
    return 0;
}

