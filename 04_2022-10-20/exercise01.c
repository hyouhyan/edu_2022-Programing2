#include<stdio.h>

void bubble(int *array, int num);
void swap(int *a, int *b);
void sort(int *a, int *b);

int main(void){
    int array[] = {9, 5, 8, 1, 2, 6, 3, 7, 4, 10};
    int num_of_array = sizeof array / sizeof array[0];

    for(int i = 0; i < num_of_array; i++)
        printf("array[%d] = %d\n", i, array[i]);
    
    printf("\n--- sorting ---\n");
    bubble(array, num_of_array);

    for(int i = 0; i < num_of_array; i++)
        printf("array[%d] = %d\n", i, array[i]);
    
    return 0;
}

void bubble(int *array, int num){
    for(int i = 0; i < num - 1; i++)
        for(int j = 0; j < num - 1 - i; j++)
            sort(&array[j], &array[j + 1]);
}

void sort(int *a, int *b){
    if(*a > *b)
        swap(a, b);
}

void swap(int *a, int *b){
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}