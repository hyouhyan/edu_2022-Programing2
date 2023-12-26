#include<stdio.h>

int main(void){
    int minus_flg = 0, cos_flg = 0, n;

    scanf("%d", &n);

    if(n % 4 == 3 | n % 4 == 2)
        minus_flg = 1;
    
    if(n % 2 == 1)
        cos_flg = 1;
    
    if(minus_flg)
        printf("-");
    else
        printf("+");
    
    if(cos_flg)
        printf("cos");
    else
        printf("sin");
    
    printf("x\n");
    
    return 0;
}

/*
+ sinx
+ cosx
- sinx
- cosx
+ sinx
+ cosx
*/