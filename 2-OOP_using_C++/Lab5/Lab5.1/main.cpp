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
class Line{
private:
    Point start;
    Point end_;
public:
    Line():start(),end_(){
        cout<<"in Line const."<<endl;
    }
    Line(int x1, int y1, int x2,int y2): start(x1,y1),end_(x2,y2){
        cout<<"in Line const."<<endl;
    }
    Line(Point p1,Point p2){
        start = p1;
        end_ = p2;
        cout<<"in Line const."<<endl;
    }
    ~Line(){
        cout<<"in Line deconst."<<endl;
    }
    void draw(){
        cout<<"this line runs from point ("<<start.getX()<<","<<start.getY()<<") to point ("<<end_.getX()<<","<<end_.getY()<<")"<<endl;
    }
};
class Rect{
private:
    Point ul;
    Point lr;
public:
    Rect():ul(),lr(){
        cout<<"in Rect const."<<endl;
    }
    Rect(int x1,int y1, int x2,int y2):ul(x1,y1),lr(x2,y2){
        cout<<"in Rect const."<<endl;
    }
    Rect(Point &p1,Point &p2){
        ul = p1;
        lr = p2;
        cout<<"in Rect const."<<endl;
    }
    ~Rect(){
        cout<<"in Rect deconst."<<endl;
    }
    void draw(){
        cout<<"this rect hast two edges at point ("<<ul.getX()<<","<<ul.getY()<<") and point ("<<lr.getX()<<","<<lr.getY()<<")"<<endl;
    }
};
class Circle{
private:
    Point center;
    int radius;
public:
    Circle():center(){
        cout<<"in circle const."<<endl;
    }
    Circle(int m,int n,int r):center(m,n){
        radius = r;
        cout<<"in circle cons. "<<endl;
    }
    ~Circle(){
        cout<<"in circle deconst."<<endl;
    }
    void draw(){
        cout<<"this circle has a center at point ("<<center.getX()<<","<<center.getY()<<") and a radius of "<<radius<<endl;
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
            pCircles[i].draw();
        }
        for(i=0;i<rNum;i++){
            pRects[i].draw();
        }
        for(i=0;i<lNum;i++){
            pLines[i].draw();
        }
    }
};
int main(){

    Picture myPic;
    Circle cArr[3]={Circle(50,50,50),Circle(200,100,100),Circle(420,50,30)};
    Rect rArr[2]={Rect(30,40,170,100),Rect(420,50,500,300)};
    Line lArr[2]={Line(420,50,300,300),Line(40,500,500,400)};

    myPic.setCircles(3,cArr);
    myPic.setRects(2,rArr);
    myPic.setLines(2,lArr);
    myPic.paint();
    cout<<"****************************************"<<endl;


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
    */
    /*
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

