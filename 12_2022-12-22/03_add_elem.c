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

int main(void){
    Elem *root = NULL;

    root = add_elem(root, 10);
    root = add_elem(root, 7);
    root = add_elem(root, 4);

    print_list(root);

    return 0;
}

// mallocを利用する理由
// 関数内で宣言した変数はどんな形式であれ消失してしまう
// mallocで確保したメモリはfreeを実行するまで消失しない
// それがたとえ関数内であっても