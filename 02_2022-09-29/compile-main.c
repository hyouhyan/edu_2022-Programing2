#include<stdio.h>

extern int sub(int);
int b;

int main(void){
    b = 10;
    printf("%d\n", sub(5));
}