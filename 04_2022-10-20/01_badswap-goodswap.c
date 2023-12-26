#include<stdio.h>

void bad_swap(int n1, int n2);
void good_swap(int *n1, int *n2);

int main(void){
    int n1 = 10, n2 = 20;

    printf("n1 = %d, n2 = %d\n", n1, n2);

    printf("\n--- bad swap ---\n");
    bad_swap(n1, n2);
    printf("n1 = %d, n2 = %d\n", n1, n2);

    printf("\n--- good swap ---\n");
    good_swap(&n1, &n2);
    printf("n1 = %d, n2 = %d\n", n1, n2);

    return 0;
}


void bad_swap(int n1, int n2){
    int temp = n2;

    n2 = n1;
    n1 = temp;
}

void good_swap(int *n1, int *n2){
    int temp = *n2;

    *n2 = *n1;
    *n1 = temp; 
}