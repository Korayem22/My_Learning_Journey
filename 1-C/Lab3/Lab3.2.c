#include <stdio.h>
int main(){
    signed int min,max,i,arr[10];
    for (i=0;i<10;i++){
        printf("enter array element %d : ",i);
        scanf("%d",&arr[i]);
        if(i==1)
            min=max=arr[i];
    }
    for(i=0;i<10;i++){
        if(arr[i]<min)
            min=arr[i];
        else if (arr[i]>max)
            max=arr[i];
    }
    printf("\nmin value is %d and max value is %d \n",min,max);
    return 0;
}
