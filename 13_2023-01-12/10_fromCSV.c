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

Melem* delete_melem(char *name, Melem *root){
    Melem *delp = root, *before = NULL;

    if(delp == NULL){
        printf("リストに要素は存在しません\n");
        return root;
    }

    while(strcmp(delp -> name, name) != 0){
        before = delp;
        delp = delp -> next;
        if(delp == NULL){
            printf("該当要素は存在しません\n");
            return root;
        }
    }

    if(before != NULL){
        before -> next = delp -> next;
        free(delp);
        return root;
    }else{
        Melem *nextroot = delp -> next;
        free(delp);
        return nextroot;
    }
}

int main(void){
    Melem *root = NULL;

    char name[MAX];
    int height = 0;
    int weight = 0;


    FILE *fp = fopen("./meibo.csv", "r");
    int flg_file_exist;
    if(fp == NULL){
        printf("ファイル開けんかったわ\n");
        flg_file_exist = 0;
    }else{
        flg_file_exist = 1;
    }

    char line[MAX];
    if(flg_file_exist){
        while(fgets(line, MAX, fp) != NULL){
            char *token = strtok(line, ",");
            strcpy(name, token);

            token = strtok(NULL, ",");
            height = atoi(token);

            token = strtok(NULL, ",");
            weight = atoi(token);
            root = add_melem(name, height, weight, root);
        }
    }

    fclose(fp);

    print_mlist(root);

    free_mlist(root);

    return 0;
}