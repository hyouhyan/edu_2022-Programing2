#include<stdio.h>
#include<stdlib.h>

int main(void){
    char **p;

    p = (char**)malloc(5*sizeof(char));

    *p = "hoge";

    printf("%s\n", *p);

    free(p);
    return 0;
}