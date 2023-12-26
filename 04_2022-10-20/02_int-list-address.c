#include<stdio.h>

int main(void){
    int list[3];

    for(int i = 0; i < 3; i++)
        printf("list[%d]\t%p\n", i, &list[i]);
    
    return 0;
}