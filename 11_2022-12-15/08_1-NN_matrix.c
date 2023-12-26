#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<math.h>
#include<string.h>
#define MAX 256

typedef struct iris{
    float sepal_length;
    float sepal_width;
    float petal_length;
    float petal_width;
    char class[64];
}Iris;

void shuffle(Iris *x, int n);
int estimIris(Iris test, Iris *learn, int elemCount);

int main(void){
    // ファイルを開く
    FILE *fp;
    fp = fopen("./iris.data", "r");
    if(fp == NULL){
        printf("ファイル開けんかったわ\n");
        exit(0);
    }

    int n = 150;
    int for_learn = n * 4 / 5, for_test = n * 1 / 5;
    Iris array_all[n];
    Iris array_learn[for_learn];
    Iris array_test[for_test];

    // fgets準備
    char line[MAX];

    int elemCount = 0;

    while(fgets(line, MAX, fp) != NULL){
        sscanf(line, "%f,%f,%f,%f,%s", &array_all[elemCount].sepal_length, &array_all[elemCount].sepal_width, &array_all[elemCount].petal_length, &array_all[elemCount].petal_width, array_all[elemCount].class);
        elemCount++;
    }

    shuffle(array_all, elemCount);

    for(int i = 0; i < for_learn; i++)
        array_learn[i] = array_all[i];
    
    for(int i = 0; i < for_test; i++)
        array_test[i] = array_all[i + for_learn];
    
    int bestnum, correct = 0;

    float confusion_matrix[3][3] = {0};
    int  a, b;

    for(int i = 0; i < for_test; i++){
        bestnum = estimIris(array_test[i], array_learn, for_learn);
        if(!strcmp(array_learn[bestnum].class, "Iris-setosa"))
            a = 0;
        else if(!strcmp(array_learn[bestnum].class, "Iris-virginica"))
            a = 1;
        else if(!strcmp(array_learn[bestnum].class, "Iris-versicolor"))
            a = 2;
        
        if(!strcmp(array_test[i].class, "Iris-setosa"))
            b = 0;
        else if(!strcmp(array_test[i].class, "Iris-virginica"))
            b = 1;
        else if(!strcmp(array_test[i].class, "Iris-versicolor"))
            b = 2;
        
        confusion_matrix[a][b]++;

        if(strcmp(array_learn[bestnum].class, array_test[i].class) == 0)
            correct++;
    }

    int countOfColumn = 0;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
            countOfColumn += confusion_matrix[i][j];
        for(int j = 0; j < 3; j++)
            confusion_matrix[i][j] /= countOfColumn * 1.0;
        countOfColumn = 0;
    }

    for(int i = 0; i < 3; i++){
        if(i == 0)
            printf("Iris-setosa\t");
        if(i == 1)
            printf("Iris-virginica\t");
        if(i == 2)
            printf("Iris-versicolor\t");
    
        for(int j = 0; j < 3; j++)
            printf("%2.1f\t", confusion_matrix[i][j]);
        
        printf("\n");
    }


    // printf("正答率: %.2f%%\n", correct * 100.0 / for_test );

    fclose(fp);
    return 0;
}

void shuffle(Iris *x, int n){
    int j;
    Iris temp;
    for(int i = n - 1; i >= 1; i--){
        srand((unsigned int)time(NULL)); //rand関数の初期化
        j = rand() % (i + 1);

        temp = x[j];
        x[j] = x[i];
        x[i] = temp;
    }
}

int estimIris(Iris test, Iris *learn, int elemCount){
    float temp = 999, best;
    int bestCount = 0;
    for(int i = 0; i < elemCount; i++){
        temp = pow(test.sepal_length - learn[i].sepal_length, 2) + pow(test.sepal_width - learn[i].sepal_width, 2) + pow(test.petal_length - learn[i].petal_length, 2) + pow(test.petal_width - learn[i].petal_width, 2);
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