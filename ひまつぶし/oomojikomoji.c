#include<stdio.h>

char upToLow(char moji){
    return moji + 32;
}

char lowToUp(char moji){
    return moji - 32;
}

int main(void){
    char moji[1000];
    int num = 0;

    scanf("%s", moji);

    while(moji[num] != '\0')
        num++;

    for(int i = 0; i < num; i++){
        if(moji[i] >= 'a' && moji[i] <= 'z')
            if(i % 2 == 0)
                moji[i] = lowToUp(moji[i]);

        if(moji[i] >= 'A' && moji[i] <= 'Z')
            if(i % 2 == 1)
                moji[i] = upToLow(moji[i]);
    }

    printf("%s\n", moji);

    return 0;
}