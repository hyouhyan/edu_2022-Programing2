#include <stdio.h>

void swap(int *a, int *b);
void sort(int *a, int *b);

int main(void){
    int a = 2, b = 1;
    printf("a = %d, b = %d\n", a, b);

    sort(&a, &b);

    printf("a = %d, b = %d\n", a, b);

    return 0;
}

void swap(int *a, int *b){
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int *a, int *b){
    if(*a > *b)
        swap(a, b);
}