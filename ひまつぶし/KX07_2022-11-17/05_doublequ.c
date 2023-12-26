#include<stdio.h>
#include<string.h>

int main(void){
    char str[100], dq_str[100] = {'\0'};
    int dq_flg = 0, dq_count = 0;
    scanf("%s", str);

    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == '"'){
            dq_flg++;
            i++;
        }
        
        if(dq_flg == 1){
            dq_str[dq_count] = str[i];
            dq_count++;
        }
        
        if(dq_flg == 2){
            dq_str[dq_count] = '\0';
            printf("%s\n", dq_str);
            dq_flg = 0;
            dq_count = 0;
        }
    }

    return 0;
}

// ('"')
//   ↑なんか顔文字みたいでかわいい