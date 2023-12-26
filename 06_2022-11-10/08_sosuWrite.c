#include<stdio.h>

int main(void){
    FILE *fp = fopen("./prime.txt", "w");
    int isPrimeNum = 1;
    char temp[10];

    for(int i = 2; i < 100; i++){
        for(int j = 2; j < i; j++)
            if(i % j == 0)
                isPrimeNum = 0;
        if(isPrimeNum){
            sprintf(temp, "%d\n", i);
            fputs(temp, fp);
        }
        isPrimeNum = 1;
    }

    fclose(fp);
    return 0;
}