#include<stdio.h>

struct student{
    char name[64];
    int age;
    char number[7];
    int grade;
};

int main(void){
    struct student st[3] = {
        {"Kimura", 18, "K22047", 1},
        {"Tanaka", 20, "H80800", 3},
        {"Suzuki", 19, "H39800", 2}
    };

    for(int i = 0; i < 3; i++){
        printf("--- st%d ---\n", i);
        printf("Name\t%s\n", st[i].name);
        printf("Age\t%d\n", st[i].age);
        printf("Number\t%s\n", st[i].number);
        printf("Grade\t%d\n", st[i].grade);
    }

    return 0;
}