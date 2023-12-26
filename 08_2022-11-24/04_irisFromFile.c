#include<stdio.h>

typedef struct iris{
    float sepal_length;
    float sepal_width;
    float petal_length;
    float petal_width;
    char class[64];
}Iris;

int main(void){
    char line[50]="5.7,2.9,4.2,1.3,Iris-versicolor\n";
    Iris p;
    sscanf(line, "%f,%f,%f,%f,%s", &p.sepal_length, &p.sepal_width, &p.petal_length, &p.petal_width, p.class);

    printf("sepal_length:%f\n", p.sepal_length);
    printf("sepal_width:%f\n", p.sepal_width);
    printf("petal_length:%f\n", p.petal_length);
    printf("class:%s\n", p.class);

    return 0;
}