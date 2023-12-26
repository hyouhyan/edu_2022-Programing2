#include<stdio.h>
#include<stdlib.h>

#define MAX 256

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
    Elem *next = root;

    Elem *p = (Elem*)malloc(sizeof(Elem));
    p -> num = num;

    if(root == NULL){
        p -> next = root;

        return p;
    }else{
        Elem *back = NULL;
        while(next != NULL && next -> num < num){
            back = next;
            next = next -> next;
        }

        p -> next = next;

        if(back != NULL){
            back -> next = p;
            return root;    
        }
        
        return p;
    }
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

    FILE *fp = fopen("./numlist.txt", "r");

    if(fp == NULL){
        printf("ファイル開けんかったわ\n");
        exit(1);
    }

    char line[MAX];
    int num;

    while(fgets(line, MAX, fp) != NULL){
        sscanf(line, "%d", &num);
        root = add_elem(root, num);
    }

    print_list(root);

    fclose(fp);
    free_list(root);

    return 0;
}