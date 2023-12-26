#include<stdio.h>

void print16(unsigned int x);

int main(void){
    unsigned int num;

    printf("Input Number ");scanf("%d", &num);

    if(num > 255)printf("overflow\n");
    else{
        print16(num / 16);
        print16(num % 16);
        printf("\n");
    }
    return 0;
}

void print16(unsigned int x){
    if(x <= 9) {
        printf("%d", x);
    }else{
        switch(x){
            case 10: printf("A"); break;
            case 11: printf("B"); break;
            case 12: printf("C"); break;
            case 13: printf("D"); break;
            case 14: printf("E"); break;
            case 15: printf("F"); break;
        }
    }
}