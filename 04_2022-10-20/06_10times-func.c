#include<stdio.h>

void func(int *a);

int main(void){
    int a[5] = {10, 20, 30, 40, 50};

    for(int i = 0; i < 5; i++)
        printf("a[%d] = %d\n", i, a[i]);
    
    printf("\n");

    func(a);

    for(int i = 0; i < 5; i++)
        printf("a[%d] = %d\n", i, a[i]);

    return 0;
}

void func(int *a){
    for(int i = 0; i < 5; i++)
        a[i] *= 10;
}