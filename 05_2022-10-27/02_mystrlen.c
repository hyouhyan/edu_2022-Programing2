#include<stdio.h>

int my_strlen(char *str);

int main(void){
    char str1[128] = "abc";
    char str2[] = "cde";
    char *str = "fgh";

    printf("str1\tmy_strlen = %d\n", my_strlen(str1));
    printf("str2\tmy_strlen = %d\n", my_strlen(str2));
    printf("str\tmy_strlen = %d\n", my_strlen(str));

    return 0;
}

int my_strlen(char *str){
    int i = 0;

    while(str[i] != '\0')
        i++;
    
    return i;
}