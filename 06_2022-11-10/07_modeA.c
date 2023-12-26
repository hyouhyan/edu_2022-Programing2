#include<stdio.h>
#include<stdlib.h>

int main(void){
    FILE *fp = fopen("./number.txt", "a");

    if(fp == NULL){
        printf("ファイル開けんかったわ\n");
        exit(0);
    }

    int i;
    char temp[10];

    // // 一発改行を入れる

    // fputs("\n", fp);

    for(i = 100; i < 200 - 1; i++){
        sprintf(temp, "\n%d", i);
        fputs(temp, fp);
    }

    // // 最後だけ改行を入れない
    // sprintf(temp, "%d", i);
    // fputs(temp, fp);

    fclose(fp);
    return 0;
}