#include<stdio.h>

int main(void){
    int i1 = 10, i2 = 20;
    int *p = &i1;

    printf("%d\n", *p);

    p = &i2;

    printf("%d\n", *p);

    printf("%d\n", *&i2);



    return 0;
}