#include<stdio.h>
#include<stdlib.h>
#define MAX 256

typedef struct iris{
    float sepal_length;
    float sepal_width;
    float petal_length;
    float petal_width;
    char class[64];
}Iris;

int main(void){
    // ファイルを開く
    FILE *fp;
    fp = fopen("./iris.data", "r");
    if(fp == NULL){
        printf("ファイル開けんかったわ\n");
        exit(0);
    }

    Iris p[150];
    int Count = 0;

    // fgets準備
    char line[MAX];

    while(fgets(line, MAX, fp) != NULL){
        sscanf(line, "%f,%f,%f,%f,%s", &p[Count].sepal_length, &p[Count].sepal_width, &p[Count].petal_length, &p[Count].petal_width, p[Count].class);
        Count++;
    }

    for(int i = 0; i < Count; i++){
        printf("iris[%d]:\n", i);
        printf("sepal_length:%f\n", p[i].sepal_length);
        printf("sepal_width:%f\n", p[i].sepal_width);
        printf("petal_length:%f\n", p[i].petal_length);
        printf("petal_width:%f\n", p[i].petal_width);
        printf("class:%s\n", p[i].class);
        printf("\n");
    }

    fclose(fp);
    return 0;
}