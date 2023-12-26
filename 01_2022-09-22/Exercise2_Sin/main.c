#include<stdio.h>
#include<math.h>
//#define M_PI 3.14159265358979323846264338327950288

int main(void){
    for(int i = 0; i <= 360; i+=10){
        float rad = (float)i / 180 * M_PI;
        printf("%d,%.2f\n", i, sin(rad));
    }
    return 0;
}