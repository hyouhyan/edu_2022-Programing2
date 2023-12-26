#include<stdio.h>

int zenka(int n);

int main(void){
    for(int i = 1; i <= 10; i++)    
        printf("n = %dのとき%d\n", i, zenka(i));

    return 0;
}

int zenka(int n){
    int result;
    for(int i = 0; i < n; i++)
        if(i == 0 | i == 1)
            result = 1;
        else
            result = zenka(n - 1) + zenka(n - 2);
    
    return result;
}