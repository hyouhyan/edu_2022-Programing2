#include<stdio.h>
#include<math.h>

int main(void){
    int r = 10;

    double s = M_PI * pow(r, 2);
    double l = 2 * M_PI * r;

    printf("面積 = %.4lf\n", s);
    printf("円周 = %.4lf\n", l);

    return 0;
}