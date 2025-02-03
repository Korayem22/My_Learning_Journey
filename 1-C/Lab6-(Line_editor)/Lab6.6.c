#include <dos.h>
#include <dir.h>
#include <stdlib.h>
#include <stdio.h>
#include<windows.h>
#include <time.h>
#define enter 13
#define backspace 8
#define left 75
#define up 72
#define down 80
#define right 77
#define home 71
#define end 79
#define insert 82
#define escape 27
#define del 83
void gotoxy(int x,int y);
void swap(char*,char*);
int main(){
    int x_coord=55;
    int y_coord=15;
    char x;
    char line[25]="";
    char *p_end=line+24;
    char *p_start=line;
    char *p_cursor=line;
    char *p_end_line=line;
    int insert_toggle = 0;
    int run=1;
    int step=0;
    while(run){
        x = getch();
        switch(x){
        default:
            if(insert_toggle==0){
                if(p_cursor!=p_end){
                    *p_cursor=x;
                    if(p_cursor==p_end_line)
                        p_end_line++;
                    p_cursor++;
                    x_coord++;
               }
            }
            else{
                if (p_end_line != p_end) {
                    int steps = p_end_line - p_cursor;
                    p_end_line++;
                    *p_end_line = '\0';
                    for (int i = steps; i >= 0; i--) {
                        swap((p_cursor + i + 1),(p_cursor + i));
                    }
                    *p_cursor = x;
                    p_cursor++;
                    x_coord++;
                }
            }
            break;
        case -32:
            break;
        case home:
        case down:
            p_cursor=p_start;
            x_coord=55;
            break;
        case end:
        case up:
            p_cursor=p_end_line;
            x_coord=55+(p_end_line-p_start);
            break;
        case left:
            if(p_cursor==p_start)
                break;
            else{
                p_cursor--;
                x_coord--;
                break;
            }
        case right:
            if(p_end_line>p_start){
                if(p_cursor==p_end_line)
                    break;
                else{
                    p_cursor++;
                    x_coord++;
                    break;
                }
            }
        case del:
            if(p_cursor>=p_start){
                if(p_cursor==p_end_line){
                    break;
                }
                else{
                    int steps=(p_end_line-p_cursor);
                    *p_cursor='\0';
                    for(int i = 0;i<steps;i++){
                        swap((p_cursor+i),(p_cursor+i+1));
                    }
                    p_end_line--;
                }
            }
            break;
        case backspace:
            if(p_cursor>p_start){
                if(p_cursor==p_end_line){
                    --p_cursor;
                    *p_cursor='\0';
                    p_end_line--;
                    x_coord--;
                }
                else{
                    int steps=(p_end_line-p_cursor);
                    p_cursor--;
                    *p_cursor='\0';
                    for(int i = 0;i<steps;i++){
                        swap((p_cursor+i),(p_cursor+i+1));
                    }
                    x_coord--;
                    p_end_line--;
                }
            }
            break;
        case insert:
            if(insert_toggle==0)
                insert_toggle=1;
            else
                insert_toggle=0;
            break;
        case enter:
            run=0;
            break;
        case escape:
            p_cursor=p_start;
            *p_cursor='\0';
            p_end_line=p_start;
            x_coord=55;
        }
        print(p_start,p_end_line);
        gotoxy(x_coord,y_coord);
    }
    return 0;
}
  void gotoxy(int x,int y){
   COORD coord={0,0};
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void print(char *start,char*end_of_line){
    system("cls");
    gotoxy(55,15);
    char l= end_of_line-start;
    for(int i=0;i<l;i++){
        printf("%c",*(start+i));
    }
}
void swap(char*one,char*two){
    char temp = *one;
    *one=*two;
    *two=temp;
}
