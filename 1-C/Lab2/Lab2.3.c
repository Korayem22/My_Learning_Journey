#include <stdio.h>
int main(){
    int input = 0;
    char done = 1;
    printf(" please choose from the following using the corresponding integer.\n\n");
    printf(" 1. beef \n 2. chicken \n 3. vegetables\n ");
    while(done){
        scanf("%d",&input);
        switch(input){
            case 1:
                printf("beef");
                done=0;
                break;
            case 2:
                printf("chicken");
                done=0;
                break;
            case 3:
                printf("vegetables");
                done=0;
                break;
            default:
                printf("please enter a valid choice\n\n");
                printf(" 1. beef \n 2. chicken \n 3. vegetables\n ");
                break;
    }
    }
    return 0;
}
