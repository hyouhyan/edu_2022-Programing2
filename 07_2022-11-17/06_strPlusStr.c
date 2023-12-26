#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    char *str1 = "ABCDE";
    char *str2 = "XYZ";
    char *str;

    str = (char*)malloc(sizeof(str1) + sizeof(str2));

    if(str == NULL){
        printf("No enough memory.\n");
        exit(1);
    }

    strcat(str, str1);
    strcat(str, str2);

    printf("%s\n", str);

    free(str);
    return 0;
}