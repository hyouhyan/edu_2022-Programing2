#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<math.h>
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

    // array_allのデータ数
    int num = 150;

    // 分割数
    int n = 5;

    // テストデータを何番目にするか(0<k<n)
    int k = 1;

    Iris array_all[num];
    Iris array_learn[num * (n - 1) / n];
    Iris array_test[num / n];

    // fgets準備
    char line[MAX];

    int elemCount = 0;

    while(fgets(line, MAX, fp) != NULL){
        sscanf(line, "%f,%f,%f,%f,%s", &array_all[elemCount].sepal_length, &array_all[elemCount].sepal_width, &array_all[elemCount].petal_length, &array_all[elemCount].petal_width, array_all[elemCount].class);
        elemCount++;
    }

    shuffle(array_all, num);

    for(int i = 0; i < num; i++){
        if((num / n) * k <= i)
            if(i < (num / n) * (k + 1))
                array_test[i - (num / n) * k] = array_all[i];
            else
                array_learn[i - num / n] = array_all[i];
        else
            array_learn[i] = array_all[i];
    }
    
    int bestnum;

    for(int i = 0; i < num / n; i++){
        bestnum = estimIris(array_test[i], array_learn, num * (n - 1) / n);
        printf("array_test[%d]\t%s\n", i, array_learn[bestnum].class);
    }

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