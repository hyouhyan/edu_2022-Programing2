#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void){
    int num, *score;

    printf("人数を入力 ");scanf("%d", &num);

    score = (int*)malloc(num * sizeof(int));
    if(score == NULL){
        printf("No enough memory.\n");
        exit(1);
    }

    for(int i = 0; i < num; i++){
        printf("%d人目の点数を入力 ", i + 1);scanf("%d", score + i);
    }

    double avg = 0, stdev = 0, variance = 0;

    // まず平均
    for(int i = 0; i < num; i++)
        avg += score[i];
    avg /= num;

    // 分散を求める
    for(int i = 0; i < num; i++)
        variance += pow(score[i] - avg, 2);
    variance /= num;

    // sqrtで標準偏差
    stdev = sqrt(variance);


    printf("平均: %lf\n", avg);
    printf("標準偏差: %lf\n", stdev);

    free(score);
    return 0;
}