#include <stdio.h>
void copy(char *des,char *src){
    int i = 0;
    while(*(src+i)!='\0'){
        *(des+i)=*(src+i);
        i++;
    }
    des[i]='\0';
}
int main(){
    char arr1[12]="source";
    char arr2[12]="dest";
    printf ("%s ***** %s\n",arr1,arr2);
    copy(arr2,arr1);
    printf ("%s ***** %s\n",arr1,arr2);
    return 0;
}
