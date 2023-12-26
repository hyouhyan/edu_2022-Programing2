#include<stdio.h>
#include<stdlib.h>
#define MAX 256

int main(void){
    // ファイルを示すポインタを作成
    // FILE構造体
    // 構造体とは→配列の強化版みたいなやつ(Pythonで言うところの辞書的な？)
    // 違った型の値をまとめて扱える
    FILE *fp;

    // readモードで"./meibo.txt"を読み込む
    fp = fopen("./meibo.txt", "r");

    if(fp == NULL){
        printf("Cannot open the file.");
        // stdlibより、強制終了する関数
        exit(0);
    }

    char line[MAX];

    while(fgets(line, MAX, fp) != NULL){
        printf("%s", line);
    }
    printf("\n");

    fclose(fp);
    return 0;
}