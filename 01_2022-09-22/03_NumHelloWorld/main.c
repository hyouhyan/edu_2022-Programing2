#include<stdio.h>

int main(void){
    int num = 0;
    printf("Enter Num ");scanf("%d", &num);

    for(int i = 0; i < num; i++)
        printf("Hello, world!\n");
    
    return 0;
}