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

    int scale[9] = {0};

    for(int i = 0; i < eqCount; i++)
        switch(eqInfop[i].scale){
            case '1':
                scale[0]++;
                break;
            case '2':
                scale[1]++;
                break;
            case '3':
                scale[2]++;
                break;
            case '4':
                scale[3]++;
                break;
            case 'A':
                scale[4]++;
                break;
            case 'B':
                scale[5]++;
                break;
            case 'C':
                scale[6]++;
                break;
            case 'D':
                scale[7]++;
                break;
            case '7':
                scale[8]++;
                break;
        }
    
    for(int i = 0; i < 4; i++){
        printf("震度%d: %d\n", i + 1, scale[i]);
    }
    printf("震度5弱: %d\n", scale[4]);
    printf("震度5強: %d\n", scale[5]);
    printf("震度6弱: %d\n", scale[6]);
    printf("震度6強: %d\n", scale[7]);
    printf("震度7: %d\n", scale[8]);
    
    return 0;
}