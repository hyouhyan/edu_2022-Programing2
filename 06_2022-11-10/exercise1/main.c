#include<stdio.h>
#include <time.h>

void swap_str_ptr(char **a, char **b);
void sort_str_ptr(char **a, char **b);
int my_strlen(char *str);
void bubble_str_ptr(char **list, int num);

int main(void){
    char *list[] = {"hoge", "abc", "xy", "fugagaga", "zone", "monster", "redbull", "4goukaantoosugi", "apple", "oni", "google", "elonmask", "twitter", "spacex", "hyouhyan", "macbookpro", "xcodeomoi", "lancable", "typec", "lightning"};

    int num = sizeof(list) / sizeof(list[0]);

    for(int i = 0; i < num; i++)
        printf("%s ", list[i]);
    printf("\n");

    // 時間ぶち込む構造体
    struct timespec start_time, end_time;
    printf("--- bubble sort ---\n");
    // 実行前の時間
    clock_gettime(CLOCK_REALTIME, &start_time);

    bubble_str_ptr(list, num);

    // 実行後の時間
    clock_gettime(CLOCK_REALTIME, &end_time);

    for(int i = 0; i < num; i++)
        printf("%s ", list[i]);
    printf("\n\n");

    int normalSec = end_time.tv_sec - start_time.tv_sec;
    int nanoSec = end_time.tv_nsec - start_time.tv_nsec;

    double sec = (double)normalSec + (double)nanoSec / (1000 * 1000 * 1000);

    // printf("normalsec: %d\n", normalSec);
    // printf("nanoSec: %d\n", nanoSec);

    printf("処理にかかった時間: %f\n", sec);
}

void swap_str_ptr(char **a, char **b){
    char *tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int my_strlen(char *str){
    int i = 0;

    while(str[i] != '\0')
        i++;
    
    return i;
}

void sort_str_ptr(char **a, char **b){
    int alen = my_strlen(*a);
    int blen = my_strlen(*b);

    if(alen > blen)
        swap_str_ptr(a, b);
}

void bubble_str_ptr(char **list, int num){
    for(int i = 0; i < num - 1; i++)
        for(int j = 0; j < num - 1 - i; j++)
            sort_str_ptr(list + j, list + j + 1);
}