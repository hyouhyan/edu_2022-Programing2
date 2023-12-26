#include<stdio.h>

int draw_figure(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            printf("*");
        }
        printf("\n");
    }
    
    //戻り値は必要ないけどgccでコンパイルするときにwarningが出たからとりあえず
    return 0;
}