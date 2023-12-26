#include<stdio.h>

typedef struct elem{
    int num;
    struct elem *next;
}Elem;

int main(void){
    // Elemを指し示すポインター root に対してNULLを割り当てる
    Elem *root = NULL;

    return 0;
}