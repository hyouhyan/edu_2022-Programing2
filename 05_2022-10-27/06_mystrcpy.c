#include<stdio.h>

void my_strcpy(char *to, char *from);

int main(void){
    char a[128] = "abc";
    char b[128];

    my_strcpy(b, a);

    printf("a = %s\n", a);
    printf("b = %s\n", b);

    return 0;
}

void my_strcpy(char *to, char *from){
    int i;
    for(i = 0; from[i] != '\0'; i++)
        to[i] = from[i];

    to[i] = from[i];
}