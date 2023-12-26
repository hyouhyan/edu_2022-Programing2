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
void sort_eq_lat(EQ *eqInfo1, EQ *eqInfo2);
void swap_eq(EQ *eqInfo1, EQ *eqInfo2);

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

    // 一度だけなのでmain関数内にアルゴを記入
    for(int i = 0; i < eqCount - 1; i++)
        for(int j = 0; j < eqCount - 1 - j; j++){
            sort_eq_lat(eqInfop + j, eqInfop + j + 1);
        }
    
    FILE *newfp = fopen("./h2011_eq_sorted.csv", "w");

    for(int i = 0; i < eqCount; i++)
        fprintf(newfp, "%d,%d,%d,%lf,%lf,%c\n", eqInfop[i].year, eqInfop[i].month, eqInfop[i].day, eqInfop[i].lat, eqInfop[i].lon, eqInfop[i].scale);
    
    fclose(newfp);
    printf("書き出し完了\n");

    return 0;
}

void printEQ(EQ eqInfo){
    printf("Year\t%d\n", eqInfo.year);
    printf("Month\t%d\n", eqInfo.month);
    printf("Day\t%d\n", eqInfo.day);
    printf("Lat\t%f\n", eqInfo.lat);
    printf("Lon\t%f\n", eqInfo.lon);
    printf("Scale\t%c\n", eqInfo.scale);
}

void sort_eq_lat(EQ *eqInfo1, EQ *eqInfo2){
    if(eqInfo1->lat > eqInfo2->lat)
        swap_eq(eqInfo1, eqInfo2);
}

void swap_eq(EQ *eqInfo1, EQ *eqInfo2){
    EQ eqTemp;

    eqTemp = *eqInfo1;
    *eqInfo1 = *eqInfo2;
    *eqInfo2 = eqTemp;
}