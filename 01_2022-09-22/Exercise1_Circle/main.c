#include<stdio.h>
#include<math.h>
//#define M_PI 3.14159265358979323846264338327950288

int main(void){
    int r;
    printf("Enter r ");scanf("%d", &r);


    printf("円周 = %.2f\n", 2 * M_PI * r);
    printf("面積 = %.2f\n", M_PI * r * r);

    return 0;
}