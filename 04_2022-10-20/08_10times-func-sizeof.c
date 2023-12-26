#include<stdio.h>

void func(int *a, int num);

int main(void){
    int a[] = {10, 20, 30, 40, 50};
    int b[] = {3, 4, 5, 6};

    int num_of_a = sizeof a / sizeof (int);
    int num_of_b = sizeof b / sizeof (int);

    for(int i = 0; i < 5; i++)
        printf("a[%d] = %d\n", i, a[i]);
    for(int i = 0; i < 4; i++)
        printf("b[%d] = %d\n", i, b[i]);

    printf("\n");

    func(a, num_of_a);
    func(b, num_of_b);

    for(int i = 0; i < 5; i++)
        printf("a[%d] = %d\n", i, a[i]);
    for(int i = 0; i < 4; i++)
        printf("b[%d] = %d\n", i, b[i]);
    
    return 0;
}

void func(int *a, int num){
    for(int i = 0; i < num; i++)
        a[i] *= 10;
}