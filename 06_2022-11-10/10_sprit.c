#include<stdio.h>
#include<string.h>

int main(void){
    char str[128]="foo,bar,hoge,fuga";
    char *ptr;

    ptr = strtok(str, ",");
    printf("%s\n", ptr);

    while(ptr != NULL) {
        // strtok内部でポインタ情報を保持しているため、NULLを指定する
        ptr = strtok(NULL, ",");

        if(ptr != NULL) {
            printf("%s\n", ptr);
        }
    }

    return 0;
}