#include<stdio.h>
#include<math.h>

int main(void){
    int x1 = 100;
    int y1 = 10;
    int x2 = 200;
    int y2 = 50;

    float euclid = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

    printf("ユークリッド距離 = %.2f\n", euclid);

    return 0;
}