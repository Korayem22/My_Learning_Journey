#include <dos.h>
#include <dir.h>
#include<windows.h>
#include <time.h>
#define UP 72
#define DOWN 80
#define BACK 27
#define ENTER 13
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
void draw(int pos,int menu){
    system("cls");
    for(int i = 0;i<3;i++){
        if(menu==1){
            if(i!=pos)
                continue;
            else{
                gotoxy(55,5+(i*10));
                SetColor(3);
                printf("Option %d",i+1);
            }
        }
        else{
            if(i!=pos){
                gotoxy(55,5+(i*10));
                SetColor(15);
                printf("Option %d",i+1);
            }
            else{
                gotoxy(55,5+(i*10));
                SetColor(2);
                printf("Option %d",i+1);
            }
        }
    }
}
int main(){
    char x;
    signed int pos = 0, menu = 0;
    draw(pos,menu);
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
        draw(pos,menu);
    }
    return 0;
}
