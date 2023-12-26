#include<stdio.h>

typedef struct elem{
    int num;
    struct elem *next;
}Elem;

void print_list(Elem *root){
    while(root != NULL){
        printf("%d\n", root -> num);
        root = root -> next;
    }
}

int main(void){
    Elem *root = NULL;

    Elem l1 = {10, root};
    root = &l1;
    Elem l2 = {7, root};
    root = &l2;
    Elem l3 = {4, root};
    root = &l3;

    print_list(root);

    return 0;
}