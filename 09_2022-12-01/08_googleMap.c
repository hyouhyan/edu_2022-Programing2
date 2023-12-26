#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct earthquake{
    int year;
    int month;
    int day;
    double lat;
    double lon;
    char scale;
}EQ;

void printEQ(EQ eqInfo);

int main(void){
    // まずファイルを開く
    FILE *fp;
    fp = fopen("./h2011_eq.csv", "r");
    if(fp == NULL){
        printf("ファイル開けんかったわ\n");
        exit(0);
    }

    // mallocでメモリ確保
    EQ *eqInfop = (EQ*)malloc(sizeof(EQ));
    int eqCount = 0;
    if(eqInfop == NULL){
        printf("malloc時にメモリが足りなかった\n");
        exit(1);
    }

    // 1行分を打ち込む配列 line
    char line[MAX];
    while(fgets(line, MAX, fp) != NULL){
        // 要素数 + 1分の配列を確保
        eqInfop = (EQ*)realloc(eqInfop, (eqCount + 1) * sizeof(EQ));
        if(eqInfop == NULL){
            printf("realloc時にメモリが足りなかった\n");
            exit(1);
        }
        sscanf(line, "%d,%d,%d,%lf,%lf,%c", &eqInfop[eqCount].year, &eqInfop[eqCount].month, &eqInfop[eqCount].day, &eqInfop[eqCount].lat, &eqInfop[eqCount].lon, &eqInfop[eqCount].scale);
        eqCount++;
    }

    FILE *newfp = fopen("./h2011_eq_0311.csv", "w");

    for(int i = 0; i < eqCount; i++)
        if(eqInfop[i].month == 3 && eqInfop[i].day == 11 && eqInfop[i].scale >= '4')
            fprintf(newfp, "%d,%d,%d,%lf,%lf,%c\n", eqInfop[i].year, eqInfop[i].month, eqInfop[i].day, eqInfop[i].lat, eqInfop[i].lon, eqInfop[i].scale);
    
    fclose(newfp);
    printf("書き出し完了\n");

    return 0;
}