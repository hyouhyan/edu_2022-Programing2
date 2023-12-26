#include<stdio.h>

int main(void){
    int a[5] = {10, 20, 30, 40, 50};
    int *p = a;

    for(int i = 0; i < 5; i++)
        printf("a[%d] = %d\n", i, a[i]);

    printf("\n");

    for(int i = 0; i < 5; i++)
        *(p + i) += 1;
    
    for(int i = 0; i < 5; i++)
        printf("a[%d] = %d\n", i, a[i]);
    
    return 0;
}