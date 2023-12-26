#include<stdio.h>
#include<stdlib.h>
#define MAX 256

int main(void){
    FILE *fp = fopen("./cars.csv", "r");

    if(fp == NULL){
        printf("ファイル開けんかったわ\n");
        // stdlibより、強制終了する関数
        exit(0);
    }

    char line[MAX];

    while(fgets(line, MAX, fp) != NULL){
        printf("%s", line);
    }

    fclose(fp);
    return 0;
}