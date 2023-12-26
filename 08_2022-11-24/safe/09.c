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

    Iris p[150];
    int Count = 0;

    // fgets準備
    char line[MAX];

    while(fgets(line, MAX, fp) != NULL){
        sscanf(line, "%f,%f,%f,%f,%s", &p[Count].sepal_length, &p[Count].sepal_width, &p[Count].petal_length, &p[Count].petal_width, p[Count].class);
        Count++;
    }

    // Iris avg[3] = {0, 0, 0, 0, ""};
    // strcpy(avg[0].class, "Iris-setosa");
    // strcpy(avg[1].class, "Iris-versicolor");
    // strcpy(avg[2].class, "Iris-virginica");


    // int temp, avgCount[3] = {0};

    // for(int i = 0; i < elemCount; i++){
    //     if(strcmp(p[i].class, "Iris-setosa") == 0)
    //         temp = 0;
    //     if(strcmp(p[i].class, "Iris-versicolor") == 0)
    //         temp = 1;
    //     if(strcmp(p[i].class, "Iris-virginica") == 0)
    //         temp = 2;

    //     avgCount[temp]++;
        
    //     avg[temp].sepal_length += p[i].sepal_length;
    //     avg[temp].sepal_width += p[i].sepal_width;
    //     avg[temp].petal_length += p[i].petal_length;
    //     avg[temp].petal_width += p[i].petal_width;
    // }

    // for(int i = 0; i < 3; i++){
    //     avg[i].sepal_length /= avgCount[i];
    //     avg[i].sepal_width /= avgCount[i];
    //     avg[i].petal_length /= avgCount[i];
    //     avg[i].petal_width /= avgCount[i];
    // }

    printf("5.7,4.0,1.2,0.2: ");
    printf("%s\n", (p[estimIris(5.7, 4.0, 1.2, 0.2, p, Count)].class));

    printf("5.9,2.9,4.2,1.5: ");
    printf("%s\n", (p[estimIris(5.9, 2.9, 4.2, 1.5, p, Count)].class));

    printf("5.6,2.8,4.8,2.0: ");
    printf("%s\n", (p[estimIris(5.6, 2.8, 4.8, 2.0, p, Count)].class));



    fclose(fp);
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