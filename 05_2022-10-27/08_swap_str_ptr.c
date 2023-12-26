#include<stdio.h>

void swap_str_ptr(char **a, char **b);

int main(void){
    char *a = "AB";
    char *b = "XY";

    swap_str_ptr(&a, &b);

    printf("a = %s\n", a);
    printf("b = %s\n", b);

    return 0;
}

void swap_str_ptr(char **a, char **b){
    char *tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}