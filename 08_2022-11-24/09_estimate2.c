#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX 256

typedef struct iris{
    float sepal_length;
    float sepal_width;
    float petal_length;
    float petal_width;
    char class[64];
}Iris;

int estimIris(float sepal_length, float sepal_width, float petal_length, float petal_width, Iris *iris, int elemCount);

int main(void){
    // ファイルを開く
    FILE *fp;
    fp = fopen("./iris.data", "r");
    if(fp == NULL){
        printf("ファイル開けんかったわ\n");
        exit(0);
    }

    // mallocでメモリ確保
    Iris *p = (Iris*)malloc(sizeof(Iris));
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

    printf("5.7,4.0,1.2,0.2: ");
    printf("%s\n", (p[estimIris(5.7, 4.0, 1.2, 0.2, p, elemCount)].class));

    printf("5.9,2.9,4.2,1.5: ");
    printf("%s\n", (p[estimIris(5.9, 2.9, 4.2, 1.5, p, elemCount)].class));

    printf("5.6,2.8,4.8,2.0: ");
    printf("%s\n", (p[estimIris(5.6, 2.8, 4.8, 2.0, p, elemCount)].class));



    fclose(fp);
    free(p);
    return 0;
}

int estimIris(float sepal_length, float sepal_width, float petal_length, float petal_width, Iris *iris, int elemCount){
    float temp = 999, best;
    int bestCount = 0;
    for(int i = 0; i < elemCount; i++){
        temp = pow(sepal_length - iris[i].sepal_length, 2) + pow(sepal_width - iris[i].sepal_width, 2) + pow(petal_length - iris[i].petal_length, 2) + pow(petal_width - iris[i].petal_width, 2);
        // 初回処理
        if(i == 0){
            best = temp;
            bestCount = i;
            continue;    
        }

        if(temp < best){
            best = temp;
            bestCount = i;
        }
    }
    
    return bestCount;
}