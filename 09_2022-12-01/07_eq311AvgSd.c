#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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

    double eqAvg = eqCount / 365.0;
    double eqSd = 0;

    int spcount = 0;
    int  numOfDay = 0;

    for(int i = 0; i <= eqCount; i++){
        if(i != 0){
            // printf("本日:%d, 前日:%d\n", eqInfop[i].day, eqInfop[i - 1].day);
            if(eqInfop[i].day == eqInfop[i - 1].day){
                numOfDay++;
            }else{
                // printf("%d月%d日 %d回\n", eqInfop[i - 1].month, eqInfop[i - 1].day, numOfDay);
                eqSd += pow((numOfDay - eqAvg), 2);
                numOfDay = 1;
            }
        }else{
            numOfDay++;
        }
    }

    eqSd /= 365.0;
    eqSd = sqrt(eqSd);

    printf("平均\t%f\n", eqAvg);
    printf("標準偏差\t%f\n", eqSd);

    return 0;
}

void printEQ(EQ eqInfo){
    printf("Year\t%d\n", eqInfo.year);
    printf("Month\t%d\n", eqInfo.month);
    printf("Day\t%d\n", eqInfo.day);
    printf("Lat\t%f\n", eqInfo.lat);
    printf("Lon\t%f\n", eqInfo.lon);
    printf("Scale\t%d\n", eqInfo.scale);
}