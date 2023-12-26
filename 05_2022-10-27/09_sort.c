#include<stdio.h>

void swap_str_ptr(char **a, char **b);
void sort_str_ptr(char **a, char **b);
int my_strlen(char *str);

int main(void){
    char *a = "abcde";
    char *b = "xyz";

    sort_str_ptr(&a, &b);

    printf("a = %s\n", a);
    printf("b = %s\n", b);

    return 0;
}

void swap_str_ptr(char **a, char **b){
    char *tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int my_strlen(char *str){
    int i = 0;

    while(str[i] != '\0')
        i++;
    
    return i;
}

void sort_str_ptr(char **a, char **b){
    int alen = my_strlen(*a);
    int blen = my_strlen(*b);

    if(alen > blen)
        swap_str_ptr(a, b);
}