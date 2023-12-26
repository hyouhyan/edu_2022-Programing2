#include<stdio.h>
#include<math.h>

void yomiage(long long n){
    long long temp = n;
    int keta = 0;
    
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
    for(int i = keta; i >= 0; i--){
        temp %= (int)pow(10, i);
        switch(keta % 4 ){
            case 1:printf("")
            case 2:
            case 3:
            case 4:
        }
    }


}