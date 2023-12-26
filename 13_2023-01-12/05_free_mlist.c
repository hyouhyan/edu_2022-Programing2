#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 256

typedef struct melem{
    char name[MAX];
    int height;
    int weight;
    struct melem *next;
}Melem;

void print_mlist(Melem *root){
    while(root != NULL){
        printf("name\t%s\n", root -> name);
        printf("height\t%d\n", root -> height);
        printf("weight\t%d\n", root -> weight);
        root = root -> next;
        if(root != NULL)
            printf("\n");
    }
}

Melem* add_melem(char *name, int height, int weight, Melem *root){
    Melem *p = (Melem*)malloc(sizeof(Melem));

    strcpy(p -> name, name);
    p -> height = height;
    p -> weight = weight;
    p -> next = root;

    return p;
}

void free_mlist(Melem *root){
    Melem *nextp;
    while(root != NULL){
        nextp = root -> next;
        free(root);
        root = nextp;
    }
}

int main(void){
    Melem *root = NULL;

    root = add_melem("okada", 191, 107, root);
    root = add_melem("takahashi", 171, 88, root);
    root = add_melem("naito", 180, 102, root);

    print_mlist(root);

    free_mlist(root);

    return 0;
}