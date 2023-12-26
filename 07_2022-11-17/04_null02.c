#include<stdio.h>
#include<stdlib.h>

int main(void){
    char **p;

    p = (char**)malloc(5*sizeof(char));

    if(p == NULL){
        printf("メモリ確保ができませんでした\n");
        exit(1);
    }

    *p = "hoge";

    printf("%s\n", *p);

    free(p);
    return 0;
}