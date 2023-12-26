#include<stdio.h>

int main(void){
    int n, x;
    int numOfAns = 0, wa;
    scanf("%d %d", &n, &x);

    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
            for(int k = j + 1; k <= n; k++){
                wa = i + j + k;
                if(wa == x){
                    // printf("%d + %d + %d = %d\n", i, j, k, wa);
                    numOfAns++;
                }
            }
    
    printf("%d\n", numOfAns);
    return 0;
}