#include<stdio.h>

void func(int *a, int *b);

int main(void){
    int a[5] = {10, 20, 30, 40, 50};
    int b[4] = {3, 4, 5, 6};

    for(int i = 0; i < 5; i++)
        printf("a[%d] = %d\n", i, a[i]);
    for(int i = 0; i < 4; i++)
        printf("b[%d] = %d\n", i, b[i]);

    printf("\n");

    func(a, b);

    for(int i = 0; i < 5; i++)
        printf("a[%d] = %d\n", i, a[i]);
    for(int i = 0; i < 4; i++)
        printf("b[%d] = %d\n", i, b[i]);
    
    return 0;
}

void func(int *a, int *b){
    for(int i = 0; i < 5; i++)
        a[i] *= 10;

    for(int i = 0; i < 4; i++)
        b[i] *= 10;
}