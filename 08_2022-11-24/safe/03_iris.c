#include<stdio.h>

typedef struct iris{
    float sepal_length;
    float sepal_width;
    float petal_length;
    float petal_width;
    char class[128];
}Iris;

int main(void){
    Iris iris[2] = {
        {6.7, 3.0, 5.2, 2.3, "Iris-virginica"},
        {7.0, 3.2, 4.7, 1.4, "Iris-versicolor"}
    };

    for(int i = 0; i < sizeof(iris) / sizeof(iris[0]); i++){
        printf("iris[%d]:\n", i);
        printf("sepal_length:%f\n", iris[i].sepal_length);
        printf("sepal_width:%f\n", iris[i].sepal_width);
        printf("petal_length:%f\n", iris[i].petal_length);
        printf("class:%s\n", iris[i].class);
        printf("\n");
    }

    return 0;
}