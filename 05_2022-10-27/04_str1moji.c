#include<stdio.h>

int main(void){
    char *str="abcd";

    for(;*str != '\0'; str++)
        printf("%c\n", *str);
    
    return 0;
}