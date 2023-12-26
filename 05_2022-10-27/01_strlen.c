#include<stdio.h>
#include<string.h>

int main(void){
    char str1[128] = "abc";
    char str2[] = "cde";
    char *str = "fgh";

    printf("str1\tlen = %lu, size = %lu\n", strlen(str1), sizeof(str1));
    printf("str2\tlen = %lu, size = %lu\n", strlen(str2), sizeof(str2));
    printf("str\tlen = %lu, size = %lu\n", strlen(str), sizeof(str));

    return 0;
}