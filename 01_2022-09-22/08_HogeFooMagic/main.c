#include<stdio.h>
#define NUM 100

int main(void){
    for(int i = 1; i <= NUM; i++){
        printf("hoge");
        if(i % 2 == 0)
            printf("foo");
        if(i % 3 == 0)
            printf("bar");
        printf("\n");
    }
    return 0;
}