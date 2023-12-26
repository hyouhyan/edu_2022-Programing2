#include<stdio.h>

int main(void){
    int a = 1;
    int *px = &a;

    printf("a:\t%p\n", &a);
    printf("px:\t%p\n", &px);

    return 0;
}