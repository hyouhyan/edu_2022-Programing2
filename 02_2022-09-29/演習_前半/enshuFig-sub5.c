#include<stdio.h>

int draw_figure(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - (i + 1); j++)
            printf(" ");
        printf("*\n");
    }

    //戻り値は必要ないけどgccでコンパイルするときにwarningが出たからとりあえず
    return 0;
}