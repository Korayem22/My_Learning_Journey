#include <dos.h>
#include <dir.h>
#include <stdlib.h>
#include <stdio.h>
#include<windows.h>
#include <time.h>
#define UP 72
#define DOWN 80
#define BACK 27
#define ENTER 13
struct employee{
    int id;
    int salary;
    char name[40];
};
signed int pos =0,menu=0,count=0;
char menus[3][10]={"New","Display","Exit"};
void Display(struct employee * emp,int row);
void new_employee(struct employee * emp_arr,int rows);
void delay(float number_of_seconds);
void SetColor(int ForgC);
void draw(struct employee * emp,int rows);
void gotoxy(int x,int y);
int check_id(struct employee * emp_arr,int id);
int check_id(struct employee * emp_arr,int id){
    int check;
    for(int j=0;j<count;j++){
        if(emp_arr[j].id==id)
            check=1;
        else
            check=0;
    }
    return check;
}
void new_employee(struct employee * emp_arr,int rows){
    int temp_id;
    SetColor(15);
    if(count<rows){
        printf("\n please enter employee's ID: ");
        scanf(" %d",&temp_id);
        while(check_id(emp_arr,temp_id)){
            printf("ID used before try a different id \nplease enter employee's ID: ");
            scanf(" %d",&temp_id);
        }
        emp_arr[count].id=temp_id;
        printf("\n please enter employee's Name: ");
        scanf(" %[^\n]s",emp_arr[count].name);
        printf("\n please enter employee's salary: ");
        scanf(" %d",&emp_arr[count].salary);
        printf("\n\n id = %d \n name = %s \n salary = %d \n New employee added....",emp_arr[count].id,emp_arr[count].name,emp_arr[count].salary);
        delay(1.5);
        system("cls");
        count++;
        menu--;
        draw(emp_arr,rows);
    }
    else{
        printf("\n\nmax employee count reached....");
        delay(1.5);
        system("cls");
        menu--;
        draw(emp_arr,rows);
    }
}
void Display(struct employee * emp,int row){
    system("cls");
    gotoxy(55,5);
    SetColor(5);
    printf("Employee Table");
    gotoxy(5,10);
    SetColor(15);
    for(int j=0;j<count;j++){
        SetColor(4);
        printf("\n***********************Employee %d***********************************\n",j+1);
        SetColor(15);
        printf("\n ID: %d",emp[j].id);
        printf("\n Name: %s",emp[j].name);
        printf("\n Salary: %d",emp[j].salary);

    }
    char back = 1,b=1;
    while(back){
        b = getch();
            if(b==0xFF)
                b = getch();
        if(b==BACK)
            back=0;
    }
    system("cls");
    menu--;
    draw(emp,row);


}
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
void draw(struct employee * emp, int rows){
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
                    new_employee(emp,rows);
                }
                else if (i==1){
                    Display(emp,rows);
                }
                else if (i==2){
                    gotoxy(50,7);
                    printf("program exiting");
                    exit(1);
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
int main(){
    int rows =0;
    printf("please enter the number of employees : ");
    scanf("%d",&rows);
    struct employee *arr=(struct employee *)malloc(rows*sizeof(struct employee));
    char x;
    draw(arr,rows);
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
        draw(arr,rows);
    }
    return 0;
}
