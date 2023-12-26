#include<stdio.h>

int main(void){
    char str[1000];
    scanf("%s", str);

    int loopnum = 0;
    
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == '@'){
            i++;
            loopnum = (int)str[i] - '0';

            i++;
            for(int j = 0; j < loopnum; j++)
                printf("%c", str[i]);
        }
        else{
            printf("%c", str[i]);
        }   
    }
    printf("\n");

    return 0;
}