// 第11回 課題1

#include<stdio.h>
#include<stdlib.h>

#define MAX 256

typedef struct point{
    int x;
    int y;
}Point;

Point calculatePoint(Point pt, Point v_pt){
    pt.x += v_pt.x;
    pt.y += v_pt.y;

    return pt;
}

int main(void){
    FILE *fp = fopen("./movement_data.txt", "r");

    if(fp == NULL){
        printf("ファイル開けんかったわ\n");
        exit(0);
    }

    char line[MAX];
    Point final, input;
    final.x = 0;
    final.y = 0;

    // while(fgets(line, MAX, fp) != NULL){
    //     sscanf(line, "%d,%d", &input.x, &input.y);
    //     final = calculatePoint(final, input);
    // }

    while(fscanf(fp, "%d,%d", &input.x, &input.y) == 2)
        final = calculatePoint(final, input);
    

    printf("%d,%d\n", final.x, final.y);

    return 0;
}