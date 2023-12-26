#include<stdio.h>

int main(void){
    int i1 = 1, i2 = 2;
    int *p1 = &i1, *p2 = &i2;


    printf("i1 = %d\n", i1);
    printf("i2 = %d\n", i2);

    printf("\n");

    *p1 *= 10;
    *p2 *= 10;

    printf("i1 = %d\n", i1);
    printf("i2 = %d\n", i2);

    return 0;
}