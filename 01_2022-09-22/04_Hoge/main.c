#include<stdio.h>

int main(void){
    for(int i = 1; i <= 10; i++)
        if(i % 3 == 0)
            printf("hoge\n");
        else
            printf("hoge");
        
    return 0;
}