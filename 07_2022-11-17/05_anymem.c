#include<stdio.h>
#include<stdlib.h>

int main(void){
    int num;
    printf("整数の数を入力 ");scanf("%d", &num);

    int *p = (int*)malloc(num * sizeof(int));

    if(p == NULL){
        printf("メモリ確保ができませんでした\n");
        exit(1);
    }

    for(int i = 0; i < num; i++){
        printf("p[%d]? ", i);scanf("%d", p + i);
    }

    for(int i = num - 1; i >= 0; i--)
        printf("%d\n", p[i]);
    
    free(p);

    return 0;
}