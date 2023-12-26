#include<stdio.h>

// 2進数としての桁数を求める関数
unsigned int binketa(unsigned int x);

unsigned int rrotate(unsigned int x, int n);
unsigned int lrotate(unsigned int x, int n);



int main(void){
    return 0;
}

unsigned int binketa(unsigned int x){
    int keta = 0;
    while(x != 0){
        keta++;
        x /= 2;
    }

    return x;
}

unsigned int rrotate(unsigned int x, int n){
    int temp = x >>= n;
    temp |= (x <<= (binketa(x)) - n);

    return temp;
}

unsigned int lrotate(unsigned int x, int n){
    int temp = x <<= n;
    temp |= (x >>= (binketa(x)) - n);

    return temp;
}