#include<stdio.h>
#define DEBUG

int main(void){
    printf("Hello World!\n");

    #ifdef DEBUG
        printf("Hello Debug!\n");
    #endif

    return 0;
}