#include<stdio.h>

int main(void){
    int array[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int num = sizeof array / sizeof array[0];

    printf("num = %d\n", num);

    return 0;
}