#include<stdio.h>
#include<stdlib.h>

int main(void){
    int *p = (int*)malloc(sizeof(int)), num = 0;
    int input = 0;

    if(p == NULL){
        printf("No enough memory at malloc.\n");
        exit(1);
    }

    while(1){
        printf("p[%d]? ", num);scanf("%d", &input);
        if(input < 0)
            break;
        
        p = (int*)realloc(p, (num + 1) * sizeof(int));

        if(p == NULL){
            printf("No enough memory at realloc.\n");
            exit(1);
        }

        p[num] = input;
        num++;
    }

    for(int i = 0; i < num; i++)
        printf("%d\n", p[i]);
    
    free(p);
    return 0;
}