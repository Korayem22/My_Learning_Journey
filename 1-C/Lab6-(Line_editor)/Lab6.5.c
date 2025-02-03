#include <stdio.h>
#include <stdlib.h>
int main(){
    int rows =0;
    int len=0;
    printf("please enter the number of strings : ");
    scanf("%d",&rows);
    char **arr=(char **)malloc(rows*sizeof(char*));
    for(int i = 0;i<rows;i++){
        printf("\n please enter the length of string #%d : ",i+1);
        scanf("%d",&len);
        arr[i]=(char *)malloc((len+1)*sizeof(char));
    }
    for (int i=0;i<rows;i++){
        printf("\n please enter string #%d : ",i+1);
        scanf(" %[^\n]s",(arr[i]));
    }
    for (int i=0;i<rows;i++){
        printf("\n%s",arr[i]);
        free(arr[i]);
    }
    free(arr);
    return 0;
}
