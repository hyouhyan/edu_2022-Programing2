#include<stdio.h>

int main(void){
    int a[5];
    int *pa = a;

    for(int i = 0; i < 5; i++)
        printf("pa + %d\t%p\n", i, pa + i);
    
    printf("\n");

    for(int i = 0; i < 5; i++)
        printf("a[%d]\t%p\n", i, &a[i]);
    
    return 0;
}