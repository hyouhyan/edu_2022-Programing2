#include<stdio.h>
#include<stdlib.h>
#define MAX 256

typedef struct trial{
    int speed;
    int distance;
}Trial;

void dispTrial(Trial trial){
    printf("speed: %d\n", trial.speed);
    printf("distance: %d\n", trial.distance);
}

int main(void){
    FILE *fp = fopen("./cars.csv", "r");

    if(fp == NULL){
        printf("ファイル開けんかったわ\n");
        exit(1);
    }

     // mallocでメモリ確保
    Trial *p = (Trial*)malloc(sizeof(Trial));
    int elemCount = 0;
    if(p == NULL){
        printf("No enough memory at malloc.\n");
        exit(1);
    }

    // fgets準備
    char line[MAX];

    while(fgets(line, MAX, fp) != NULL){
        p = (Trial*)realloc(p, (elemCount + 1) * sizeof(Trial));
        if(p == NULL){
            printf("No enough memory at realloc.\n");
            exit(1);
        }

        sscanf(line, "%d,%d", &p[elemCount].speed, &p[elemCount].distance);
        
        elemCount++;
    }

    int estim, err;
    float mse = 0;

    for(int i = 0; i < elemCount; i++){
        estim = p[i].speed * 2;
        err = p[i].distance - estim;

        mse += (err * err);
    }

    mse /= elemCount;

    printf("MSE = %.4f\n", mse);

    fclose(fp);
    free(p);
    return 0;
}