#include <stdio.h>
int main(){
    int i,arr[10];
    for (i=0;i<10;i++){
        printf("enter array element %d : ",i);
        scanf("%d",&arr[i]);
    }
    for(i=0;i<10;i++){
        printf("\n%d\n",arr[i]);
    }
    return 0;
}
