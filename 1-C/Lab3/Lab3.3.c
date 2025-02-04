#include <stdio.h>
void calc(signed int arr[3][4]){
    int row_sums[3]={0};
    float col_avgs[4]={0};
    for (int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            row_sums[i]+=arr[i][j];
            col_avgs[j]+=arr[i][j];
        }
        printf("row %d sum is : %d \n",i,row_sums[i]);
    }
    for(int i=0;i<4;i++){
        col_avgs[i]/=3;
        printf("col %d average is : %.2f \n",i,col_avgs[i]);
    }
}
int main(){
    signed int arr[3][4];
    for (int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            printf("please enter the element value at pos %d,%d : ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
    calc(arr);
    return 0;
}
