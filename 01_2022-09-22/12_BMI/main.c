#include<stdio.h>

int main(void){
    float height, weight, bmi;
    printf("Enter height(cm) ");scanf("%f", &height);
    printf("Enter weight(kg) ");scanf("%f", &weight);

    //cmをmに変換
    height /= 100;

    bmi = weight / (height * height);

    //printf("BMI is %.1f\n", bmi);

    if(bmi >= 30)
        printf("高度肥満\n");
    else if(bmi >= 25)
        printf("肥満\n");
    else if(bmi > 18.5)
        printf("標準\n");
    else
        printf("やせ\n");
    
    return 0;
}