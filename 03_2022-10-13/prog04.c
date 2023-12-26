#include <stdio.h>

void swap(int *a, int *b);

int main(void){
    int a = 1, b = 2;
    printf("a = %d, b = %d\n", a, b);

    swap(&a, &b);

    printf("a = %d, b = %d\n", a, b);

    return 0;
}

void swap(int *a, int *b){
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}