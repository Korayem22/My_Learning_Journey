#include <stdio.h>
float power(signed int x,signed int y);
int main(){
    signed int x=2;
    signed int y=3;
    float res = 0;
    printf("please enter the base :");
    scanf("%d",&x);
    printf("please enter the exponent :");
    scanf("%d",&y);
    res = power(x,y);
    printf("%f",res);
    return 0;
}
float power(signed int x,signed int y){
    if(y==0){
        return 1;
    }
    else if(y>0){
        return x*power(x,--y);
    }
    else{
        float pow = power(x,-y);
        return 1/pow;
    }
}
