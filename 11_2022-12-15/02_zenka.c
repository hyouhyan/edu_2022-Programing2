#include<stdio.h>

int zenka(int n);

int main(void){
    printf("%d\n", zenka(10));

    return 0;
}

int zenka(int n){
    int temp = 0;
    for(int i = 0; i < n; i++)
        if(i == 0)
            temp = 1;
        else
            temp += 2;
    
    return temp;
}