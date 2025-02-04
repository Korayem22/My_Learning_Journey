#include <stdio.h>

int main(){
    int input =0;
    int sum = 0;
    printf("program running insert numbers");
    while(sum<=100){
        scanf("%d",&input);
        sum+=input;
    }
    printf("sum exceeded 100, sum = %d ",sum);
    return 0;
}
