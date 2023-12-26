#include<stdio.h>
#define NUM 10

int main(void){
    for(int i = 1; i <= NUM; i++)
        if(i % 3 == 0)
            printf("hoge\n");
        else
            printf("hoge");
        
    return 0;
}