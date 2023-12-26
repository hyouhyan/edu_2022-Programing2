#include<stdio.h>
#include<stdlib.h>

int main(void){
    int *p;
    p = (int*)malloc(4*sizeof(int));

    if(p == NULL){
        printf("メモリ確保ができませんでした\n");
        exit(1);
    }

    for(int i = 0; i < 4; i++)
        p[i] = i;
    
    for(int i = 0; i < 4; i++)
        printf("p[%d] = %d\n", i, p[i]);
    
    free(p);
    
    return 0;
}