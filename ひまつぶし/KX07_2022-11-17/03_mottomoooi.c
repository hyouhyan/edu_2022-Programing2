#include<stdio.h>

int main(void){
    int aToZ_num[26] = {0};
    char str[100];

    scanf("%s", str);

    int most_n = 0, most = 0, temp;

    for(int i = 0; str[i] != '\0'; i++){
        if('a' <= str[i] && str[i] <= 'z')
            temp = (int)(str[i] - 'a');
        if('A' <= str[i] && str[i] <= 'Z')
            temp = (int)(str[i] - 'A');

        aToZ_num[temp]++;
        
        if(aToZ_num[temp] > most_n){
            most_n = aToZ_num[temp];
            most = temp;
        }
    }
    
    printf("%c\n", (char)most + 'A');

    return 0;
}