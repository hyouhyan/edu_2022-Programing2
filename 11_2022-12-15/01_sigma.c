#include<stdio.h>
#include<math.h>

int sigma(int a, int n);

int main(void){
    printf("%d\n", sigma(4, 10));
    return 0;
}

int sigma(int a, int n){
    int y = 0;

    for(int i = 0; i <= n; i++)
        y += pow(a, n - i);
    
    return y;
}