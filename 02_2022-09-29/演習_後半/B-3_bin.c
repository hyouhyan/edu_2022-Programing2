#include<stdio.h>

void printbin(unsigned int x);

int main(void){
    unsigned int num;
    printf("Input Number ");scanf("%d", &num);

    printbin(num);

    return 0;
}

void printbin(unsigned int x){
    unsigned int temp = x, shifedX;
    int keta = 0;

    while(temp != 0){
        temp /= 2;
        keta++;
    }
    
    for(int i = 0; i < keta; i++){
        shifedX = x >> (keta - i - 1);
        printf("%d", shifedX & 1);
    }

    printf("\n");
}