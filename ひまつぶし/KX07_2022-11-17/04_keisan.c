#include<stdio.h>

int main(void){
    char str[100];
    scanf("%s", str);

    int left = 0, right = 0, minus_flg = 0;

    for(left = 0; str[left] == '1'; left++){}

    if(str[left] == '-')
        minus_flg = 1;
    
    for(right = 0; str[right + left + 1] == '1'; right++){}

    if(minus_flg)
        printf("%d\n", left - right);
    else
        printf("%d\n", left + right);

    return 0;
}