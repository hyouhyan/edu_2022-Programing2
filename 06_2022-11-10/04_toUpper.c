#include<stdio.h>
#include<ctype.h>

int main(void){
    char str[100] = {"\0"};

    scanf("%s", str);

    int num;
    for(num = 0; str[num] != '\0'; num++){}

    for(int i = 0; i < num; i++)
        str[i] = toupper(str[i]);

    printf("%s\n", str);

    return 0;
}