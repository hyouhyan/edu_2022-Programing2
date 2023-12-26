#include<stdio.h>

extern void yomiage(long long n);

int main(void){
    long long num;
    printf("Number? ");scanf("%lld", &num);

    printf("%lld = ", num);
    yomiage(num);
    printf("\n");

    return 0;
}

