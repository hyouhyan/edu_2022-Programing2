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

    // mallocでメモリ確保
    Iris *p;
    p = (Iris*)malloc(sizeof(Iris));
    int elemCount = 0;

    if(p == NULL){
        printf("No enough memory at malloc.\n");
        exit(1);
    }

    // fgets準備
    char line[MAX];

    while(fgets(line, MAX, fp) != NULL){
        p = (Iris*)realloc(p, (elemCount + 1) * sizeof(Iris));

        sscanf(line, "%f,%f,%f,%f,%s", &p[elemCount].sepal_length, &p[elemCount].sepal_width, &p[elemCount].petal_length, &p[elemCount].petal_width, p[elemCount].class);

        if(p == NULL){
            printf("No enough memory at realloc.\n");
            exit(1);
        }
        elemCount++;
    }

    for(int i = 0; i < elemCount; i++){
        printf("iris[%d]:\n", i);
        printf("sepal_length:%f\n", p[i].sepal_length);
        printf("sepal_width:%f\n", p[i].sepal_width);
        printf("petal_length:%f\n", p[i].petal_length);
        printf("petal_width:%f\n", p[i].petal_width);
        printf("class:%s\n", p[i].class);
        printf("\n");
    }

    fclose(fp);
    free(p);
    return 0;
}