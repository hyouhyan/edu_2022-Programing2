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

    double max_lat = 0;

    for(int i = 0; i < eqCount; i++)
        if(eqInfop[i].lat > max_lat)
            max_lat = eqInfop[i].lat;
    
    double min_lat = max_lat;

    for(int i = 0; i < eqCount; i++)
        if(eqInfop[i].lat < min_lat)
            min_lat = eqInfop[i].lat;
    
    int temp_latC;
    int temp = 0;

    // minはそのまま変換で小数点以下切り捨て
    // max+0.9して小数点以下繰り上げ
    for(int i = (int)min_lat; i < (int)(max_lat + 0.9); i += 2){
        temp_latC = 0;
        for(int j = 0; j < eqCount; j++)
            if(eqInfop[j].lat < i + 2 && eqInfop[j].lat >= i)
                temp_latC++;
        
        printf("緯度%d ~ %d: %d\n", i, i + 2, temp_latC);
        temp += temp_latC;
    }

    return 0;
}
