#include<stdio.h>
#include<string.h>

int main(void){
    char a[128] = "abc";
    char b[128];

    // printf("a = %s\n", a);
    // printf("b = %s\n", b);

    strcpy(b, a);

    printf("a = %s\n", a);
    printf("b = %s\n", b);

    return 0;
}