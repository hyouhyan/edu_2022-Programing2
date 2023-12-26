#include<stdio.h>
#include<string.h>
#define FILE_PATH "./meibo.txt"
#define MAX 100


int main(void){
    FILE *fp = fopen(FILE_PATH, "a");
    char input[MAX];
    char temp[MAX];

    printf("「end」と入力すると終了します\n");

    while(1){
        scanf("%s", input);
        sprintf(temp, "\n%s", input);

        if(strcmp(input, "end") == 0)
            break;
        
        fputs(temp, fp);
    }

    fclose(fp);
    return 0;
}