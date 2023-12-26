#include<stdio.h>

#define MAX 50

void reverse(const char a[MAX], const char b[MAX], char c[MAX]);

int main(void){
    char a[MAX], b[MAX], c[MAX];

    scanf("%s", a);
    scanf("%s", b);

    reverse(a, b, c);

    printf("%s\n", c);
    return 0;
}

void reverse(const char a[MAX], const char b[MAX], char c[MAX]){
    int aNum = 0, bNum = 0;

    while(a[aNum] != '\0')
        aNum++;
    
    while(b[bNum] != '\0')
        bNum++;

    int cNum = 0;

    for(int i = aNum - 1; i >= 0; i--){
        c[cNum] = a[i];
        cNum++;
    }

    for(int i = bNum - 1; i >= 0; i--){
        c[cNum] = b[i];
        cNum++;
    }

    c[cNum] = '\0';
}