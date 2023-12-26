#include<stdio.h>

void print16(unsigned int x);

int main(void){
    unsigned int num, temp;
    int keta = 0;

    printf("Input Number ");scanf("%d", &num);
    temp = num;

    // 16進数としての桁数(ビット数的な?)を求める
    while(temp >= 16){
        temp /= 16;
        keta++;
    }
    print16(temp);
    
    for(int i = 0; i < keta; i++){
        temp = num;
        for(int j = 0; j < keta - i - 1; j++){
            temp /= 16;
        }
        temp %= 16;
        print16(temp);
    }

    printf("\n");

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