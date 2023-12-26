// 第11回 課題3

#include<stdio.h>

typedef struct ability{
    int hp;
    int of;
    int df;
    char name[10];
}Ability;

void printResult(Ability winner, int i){
    printf("%dターンで%sの勝利! %s残りHP: %d\n", i, winner.name, winner.name, winner.hp);
}

int main(void){
    Ability sa = {220, 15, 5, "勇者"};
    Ability wa = {400, 20, 7, "魔王"};

    int i;

    for(i = 0; wa.hp > 0 && sa.hp > 0; i++){
        if(i % 2 == 0)
            // この場合は勇者(sa)が攻撃
            wa.hp -= (sa.of - wa.df) / 2;
        else
            // この場合は魔王(wa)が攻撃
            sa.hp -= (wa.of - sa.df) / 2;
    }

    // i++が実行された後にforを抜ける
    // 1ターン目ならfor内ではi = 0だが、抜けた後はi = 1

    if(wa.hp > 0)
        printResult(wa, i);
    if(sa.hp > 0)
        printResult(sa, i);

    return 0;
}