#include <stdio.h>
void swap(int *x,int *y);
void swap_2(int *x, int *y);
int main(){
    int x =15 ;
    int y =10;
    printf("x = %d y = %d",x,y);
    swap(&x,&y);
    printf("\n x = %d y = %d",x,y);
    swap_2(&x,&y);
    printf("\n x = %d y = %d",x,y);
    return 0;
}
void swap(int*x,int*y){
    int t=*x;
    *x=*y;
    *y=t;
}
void swap_2(int *x, int *y){
    *x=*x+*y;
    *y=*x-*y;
    *x=*x-*y;
}
