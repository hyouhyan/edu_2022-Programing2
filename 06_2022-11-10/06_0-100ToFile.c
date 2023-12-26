#include<stdio.h>

int main(void){
    FILE *fp = fopen("./number.txt", "w");
    char temp[10];

    int i;
    for(i = 0; i < 100 - 1; i++){
        sprintf(temp, "%d\n", i);
        fputs(temp, fp);
    }
    // 最後だけ改行を入れない
    sprintf(temp, "%d", i);
    fputs(temp, fp);
    
    fclose(fp);
    return 0;
}