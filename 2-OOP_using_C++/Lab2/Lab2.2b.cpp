#include <iostream>
#include <dos.h>
#include <dir.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#define UP 72
#define DOWN 80
#define BACK 27
#define ENTER 13
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
signed int pos =0,menu=0,c=0;
char menus[3][10]={"Push","Pop","Print"};
void SetColor(int ForgC);
void draw(Stack &s);
void gotoxy(int x,int y);
void push(Stack &s);
void pop(Stack &s);
void print(Stack &s);
void delay(float number_of_seconds);
void delay(float number_of_seconds){
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}
void SetColor(int ForgC){
     WORD wColor;

      HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
      CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
                 //Mask out all but the background attribute, and add in the forgournd     color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
 }
  void gotoxy(int x,int y){
   COORD coord={0,0};
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void draw(Stack &s){
    system("cls");
    for(int i = 0;i<3;i++){
        if(menu==1){
            if(i!=pos)
                continue;
            else{
                gotoxy(55,5);
                SetColor(3);
                printf("%s",menus[i]);
                if(i==0){
                    push(s);
                }
                else if (i==1){
                    pop(s);
                }
                else if (i==2){
                    print(s);
                }
            }
        }
        else{
            if(i!=pos){
                gotoxy(55,5+(i*10));
                SetColor(15);
                printf("%s",menus[i]);
            }
            else{
                gotoxy(55,5+(i*10));
                SetColor(2);
                printf("%s",menus[i]);
            }
        }
    }
}
void push(Stack &s){
    system("cls");
    cout<<" please enter the integer you want to push : "<<endl;
    int x;
    cin>>x;
    s.push(x);
    menu--;
    delay(1.5);
    draw(s);
}
void pop(Stack &s){
    system("cls");
    cout<<"the element you popped is : "<<s.pop()<<endl;
    menu--;
    delay(1.5);
    draw(s);
}
void print(Stack &s){
    system("cls");
    cout<<"Stack elements are : "<<endl;
    s.print();
    menu--;
    delay(5);
    draw(s);
}
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
        cout<<"Element added"<<endl;
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
    int n =0;
    printf("please enter the size of the stack : ");
    scanf("%d",&n);
    Stack s(n);
    char x;
    draw(s);
    while(1){
        x = getch();
        if(x==0xFF)
            x = getch();
        switch(x){
            case DOWN:
                pos++;
                if(pos>2)
                    pos=0;
                break;
            case UP:
                pos--;
                if(pos<0)
                    pos=2;
                break;
            case BACK:
                if(menu==1)
                    menu--;
                break;
            case ENTER:
                if(menu==0)
                    menu++;
                break;
        }
        draw(s);
    }
    return 0;
}
