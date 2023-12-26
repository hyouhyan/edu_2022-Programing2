#include<stdio.h>

int main(void){
    int num, shukaku = 0, input;
    scanf("%d", &num);

    for(int i = 0; i < num; i++){
        scanf("%d", &input);
        if(input > 5)
            shukaku += (input - 5);
    }

    printf("%d\n", shukaku);
    return 0;
}