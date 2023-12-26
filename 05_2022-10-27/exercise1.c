#include<stdio.h>

void swap_str_ptr(char **a, char **b);
void sort_str_ptr(char **a, char **b);
int my_strlen(char *str);
void bubble_str_ptr(char **list, int num);

int main(void){
    char *list[] = {"hoge", "abc", "xy", "fugagaga"};

    int num = sizeof(list) / sizeof(list[0]);

    for(int i = 0; i < num; i++)
        printf("%s ", list[i]);
    printf("\n");

    printf("--- bubble sort ---\n");
    bubble_str_ptr(list, num);

    for(int i = 0; i < num; i++)
        printf("%s ", list[i]);
    printf("\n");
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

void bubble_str_ptr(char **list, int num){
    for(int i = 0; i < num - 1; i++)
        for(int j = 0; j < num - 1 - i; j++)
            sort_str_ptr(list + j, list + j + 1);
}