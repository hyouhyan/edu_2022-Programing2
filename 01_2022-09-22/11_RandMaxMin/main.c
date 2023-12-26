#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main(void){
    int max, min;
    printf("Enter MIN ");scanf("%d", &min);
    printf("Enter MAX ");scanf("%d", &max);
    
    //randくん初期化
    srand(time(NULL));
    int num = rand();

    //difference、maxとminの差を代入
    int diff = max - min ;
    //桁数なので+1
    diff++;

    num = num % diff + min;
    printf("%d\n", num);

    return 0;
}