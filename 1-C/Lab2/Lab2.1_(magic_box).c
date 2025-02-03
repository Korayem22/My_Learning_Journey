#include <stdio.h>
void magic(int n){
    int magicsq[n][n];
    memset(magicsq, 0,sizeof(magicsq));
    signed int row = 0;
    signed int col = (n/2);
    int mod;
    magicsq[row][col] = 1;
    for(int i=1;i<(n*n);i++){
        mod = i%n;
        if(mod != 0){
            row--;
            col--;
            }
        else{
            row++;
        }
        if (col==-1){
            col=n-1;
        }
        else if (row==n){
            row=0;
        }
        else if (row==-1){
            row = n-1;
        }
        magicsq[row][col]=i+1;
        }

    printf("the magic number (sum of each row,col, or diagonal) for n=%d is m=%d \n\n",n, n*(n*n+1)/2);
    for(row=0;row<n;row++){
        for(col=0;col<n;col++){
            printf("%4d ",magicsq[row][col]);
        }
        printf("\n\n");
    }
        }
int main(){
    int n;
    printf("please enter the size of the square (odd number)");
    scanf("%d",&n);
    magic(n);
    return 0;
}
