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

    Melem *before = root, *after;

    // もしroot = NULL
    // すなわち、リストの要素が一個もなければ
    if(root == NULL){
        p -> next = root;
        return p;
    }

    // rootよりもnameの方が大きければ
    if(strcmp(root -> name, name) > 0){
        p -> next = root;
        return p;
    }

    // rootと同一名義だった場合
    if(strcmp(root -> name, name) == 0){
            p -> next = root -> next;
            free(root);
            return p;
        }

    after = before -> next;
    while(after != NULL){
        if(strcmp(after -> name, name) < 0){
            before = after;
            after = after -> next;
        }
        else{
            // 同一名義だった場合の処理
            if(strcmp(after -> name, name) == 0){
                before -> next = p;
                p -> next = after -> next;
                free(after);

                return root;
            }
            break;
        }
    }

    p -> next = before -> next;
    before -> next = p;

    return root;
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

    root = add_melem("takagi", 278, 96, root);
    root = add_melem("okada", 191, 107, root);
    root = add_melem("takahashi", 171, 88, root);
    root = add_melem("naito", 180, 102, root);

    print_mlist(root);

    printf("\nI'll replace [takagi]\n\n");
    root = add_melem("takagi", 178, 96, root);

    print_mlist(root);

    free_mlist(root);

    return 0;
}