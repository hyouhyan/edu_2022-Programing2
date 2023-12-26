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

    int maxSpeed = 0, maxDistance = 0;

    for(int i = 0; i < elemCount; i++){
        if(p[i].speed > maxSpeed)
            maxSpeed = p[i].speed;
        if(p[i].distance > maxDistance)
            maxDistance = p[i].distance;
    }

    int minSpeed = maxSpeed, minDistance = maxDistance;

    for(int i = 0; i < elemCount; i++){
        if(p[i].speed < minSpeed)
            minSpeed = p[i].speed;
        if(p[i].distance < minDistance)
            minDistance = p[i].distance;
    }

    printf("speedの最小値: %d\n", minSpeed);
    printf("speedの最大値: %d\n", maxSpeed);
    printf("distanceの最小値: %d\n", minDistance);
    printf("distanceの最大値: %d\n", maxDistance);


    fclose(fp);
    free(p);
    return 0;
}