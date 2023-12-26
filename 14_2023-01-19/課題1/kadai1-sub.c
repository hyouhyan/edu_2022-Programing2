#include<stdio.h>
#include<math.h>

void printJp(int n){
    switch (n){
    case 1:
        printf("一");
        break;
    case 2:
        printf("二");
        break;
    case 3:
        printf("三");
        break;
    case 4:
        printf("四");
        break;
    case 5:
        printf("五");
        break;
    case 6:
        printf("六");
        break;
    case 7:
        printf("七");
        break;
    case 8:
        printf("八");
        break;
    case 9:
        printf("九");
        break;
    }
}

void yomiage(long long n){
    long long temp = n;
    int keta = 0;

    if(n > 1000000000000){
        printf("読めません\n");
        return;
    }

    
    // まず桁数を求める
    while(temp != 0){
        keta++;
        temp /= 10;
    }

    if(keta == 0)
        printf("零");

    // ここから本番
    // 色々弄るからtempに入れておく
    temp = n;
    long long forPrint;

    for(int i = keta - 1; i >= 0; i--){
        forPrint = temp / pow(10, i);
        temp = temp % (int)pow(10, i);

        if(forPrint != 1)
            printJp(forPrint);

        if(i % 4 == 3)
            printf("千");
        if(i % 4 == 2)
            printf("百");
        if(i % 4 == 1)
            printf("十");

        if(i % 4 == 0){
            if(i / 4 == 1)
                printf("万");
            if(i / 4 == 2)
                printf("億");
        }
            
    }

    printf("\n");
}