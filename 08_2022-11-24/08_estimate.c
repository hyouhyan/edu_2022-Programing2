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

int estimIris(float sepal_length, float sepal_width, float petal_length, float petal_width, Iris *avg);

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

    Iris avg[3] = {0, 0, 0, 0, ""};
    strcpy(avg[0].class, "Iris-setosa");
    strcpy(avg[1].class, "Iris-versicolor");
    strcpy(avg[2].class, "Iris-virginica");


    int temp, avgCount[3] = {0};

    for(int i = 0; i < elemCount; i++){
        if(strcmp(p[i].class, "Iris-setosa") == 0)
            temp = 0;
        if(strcmp(p[i].class, "Iris-versicolor") == 0)
            temp = 1;
        if(strcmp(p[i].class, "Iris-virginica") == 0)
            temp = 2;

        avgCount[temp]++;
        
        avg[temp].sepal_length += p[i].sepal_length;
        avg[temp].sepal_width += p[i].sepal_width;
        avg[temp].petal_length += p[i].petal_length;
        avg[temp].petal_width += p[i].petal_width;
    }

    for(int i = 0; i < 3; i++){
        avg[i].sepal_length /= avgCount[i];
        avg[i].sepal_width /= avgCount[i];
        avg[i].petal_length /= avgCount[i];
        avg[i].petal_width /= avgCount[i];
    }

    printf("5.7,4.0,1.2,0.2: ");
    printf("%s\n", (avg[estimIris(5.7, 4.0, 1.2, 0.2, avg)].class));

    printf("5.9,2.9,4.2,1.5: ");
    printf("%s\n", (avg[estimIris(5.9, 2.9, 4.2, 1.5, avg)].class));

    printf("5.6,2.8,4.8,2.0: ");
    printf("%s\n", (avg[estimIris(5.6, 2.8, 4.8, 2.0, avg)].class));



    fclose(fp);
    free(p);
    return 0;
}

int estimIris(float sepal_length, float sepal_width, float petal_length, float petal_width, Iris *avg){
    float from[3];
    int best = 0;
    for(int i = 0; i < 3; i++){
        from[i] = pow(sepal_length - avg[i].sepal_length, 2) + pow(sepal_width - avg[i].sepal_width, 2) + pow(petal_length - avg[i].petal_length, 2) + pow(petal_width - avg[i].petal_width, 2);
    }

    // printf("\n");
    // for(int i = 0; i < 3; i++)
    //     printf("from[%d]: %f\n", i, from[i]);

    if(from[0] < from[1])
        best = 0;
    else
        best = 1;
    
    if(from[best] > from[2])
        best = 2;
    
    return best;
}