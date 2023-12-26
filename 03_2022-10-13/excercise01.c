#include<stdio.h>
#include<math.h>

void getAvgSD(int *a, int *b, double *avg, double *sd);

int main(void){
    int a, b;
    double avg, sd;

    getAvgSD(&a, &b, &avg, &sd);

    printf("avg:%.2f, sd:%.2f\n", avg, sd);

    return 0;
}

void getAvgSD(int *a, int *b, double *avg, double *sd){
    scanf("%d,%d", a, b);

    *avg = (*a + *b) / 2.0;
    double variance = (pow((*a - *avg), 2) + pow((*b - *avg), 2)) / 2.0;
    *sd = sqrt(variance);
}