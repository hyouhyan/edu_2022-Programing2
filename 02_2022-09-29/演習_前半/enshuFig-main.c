#include<stdio.h>

extern int draw_figure(int n);

int main(void){
    int size;

    printf("Size of figure? ");scanf("%d", &size);

    draw_figure(size);

    return 0;
}