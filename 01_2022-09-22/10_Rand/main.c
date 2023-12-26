#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void){
    //randくん初期化
    srand(time(NULL));
    int num = rand();

    printf("%d\n", num % 3 + 3);
    return 0;
}