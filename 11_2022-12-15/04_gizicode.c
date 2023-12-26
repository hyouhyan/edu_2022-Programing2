#include<stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int *x, int n);

int main(void){
    int a[]={1,2,3,4,5,6,7,8,9,10};
    shuffle(a, 10);

    for(int i = 0; i < 10; i++){
        printf("%d ", a[i]);
    }

    printf("\n");
    return 0;
}

void shuffle(int *x, int n){
    int j, temp;
    for(int i = n - 1; i >= 1; i--){
        srand((unsigned int)time(NULL)); //rand関数の初期化
        j = rand() % (i + 1);

        temp = x[j];
        x[j] = x[i];
        x[i] = temp;
    }
}