#include<stdio.h>
#include<stdlib.h>

typedef struct melem{
    char *name;
    int height;
    int weight;
    struct melem *next;
}Melem;

void print_list(Melem *root){
    while(root != NULL){
        printf("name\t%s\n", root -> name);
        printf("height\t%d\n", root -> height);
        printf("weight\t%d\n", root -> weight);
        root = root -> next;
        if(root != NULL)
            printf("\n");
    }
}

int main(void){
    Melem *root = NULL;
    
    Melem l1 = {"okada", 191, 107, root};
    root = &l1;
    Melem l2 = {"takahashi", 171, 88, root};
    root = &l2;
    Melem l3 = {"naito", 180, 102, root};
    root = &l3;

    print_list(root);

    return 0;
}