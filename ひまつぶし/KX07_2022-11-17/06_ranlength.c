#include<stdio.h>

int main(void){
    char str[100], comped_str[100] = {'\0'};
    int comped_str_count = 0;
    scanf("%s", str);

    for(int i = 0; str[i] != '\0'; i += 3){
        for(int j = 0; j < str[i + 1] - '0'; j++){
            comped_str[comped_str_count] = str[i];
            comped_str_count++;
        }
        if(str[i + 2] == '*'){
            comped_str[comped_str_count] = '\n';
            comped_str_count++;
        }
    }

    printf("%s", comped_str);
    return 0;
}