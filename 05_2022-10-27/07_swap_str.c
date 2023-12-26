#include<stdio.h>

void swap_str(char *s1, char *s2);

int main(void){
    char a[128] = "abcde";
    char b[128] = "xyz";

    swap_str(a, b);

    printf("a = %s\n", a);
    printf("b = %s\n", b);
    
    return 0;
}

void swap_str(char *s1, char *s2){
    char tmp;

    while(*s1 != '\0' | *s2 != '\0'){
        tmp = *s1;
        *s1 = *s2;
        *s2 = tmp;

        s1++;
        s2++;
    }
}