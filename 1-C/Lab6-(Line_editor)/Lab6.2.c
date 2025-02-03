#include <stdio.h>[
void read (int*arr);
void print (int*arr);
int main(){
    int arr[5]={0};
    int *ptr = &arr;
    read(ptr);
    print(ptr);
    return 0;
}
void read (int*arr){
    for(int i =0;i<5;i++){
        printf("please enter array element %d ",i+1);
        scanf(" %d", &arr[i]);
    }
}
void print (int*arr){
    for(int i =0;i<5;i++){
        printf(" %d ",*arr++);
    }
}
