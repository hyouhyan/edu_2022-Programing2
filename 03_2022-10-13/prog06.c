#include <stdio.h>

void swap(int *a, int *b);
void sort(int *a, int *b);
void sort3(int *a, int *b, int *c);

int main(void){
    int a = 2, b = 3, c = 1;
    printf("a = %d, b = %d, c = %d\n", a, b, c);

    sort3(&a, &b, &c);

    printf("a = %d, b = %d, c = %d\n", a, b, c);

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

void sort3(int *a, int *b, int *c){
    sort(a, b);
    sort(b, c);
    sort(a, b);
}