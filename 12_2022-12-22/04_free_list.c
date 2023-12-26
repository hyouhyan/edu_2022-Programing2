#include<stdio.h>
#include<stdlib.h>

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

Elem* add_elem(Elem *root, int num){
    Elem *p = (Elem*)malloc(sizeof(Elem));
    p -> num = num;
    p -> next = root;

    return p;
}

void free_list(Elem *root){
    Elem *nextp;
    while(root != NULL){
        nextp = root -> next;
        free(root);
        root = nextp;
    }
}

int main(void){
    Elem *root = NULL;

    root = add_elem(root, 10);
    root = add_elem(root, 70);
    root = add_elem(root, 4);

    print_list(root);

    free_list(root);

    return 0;
}