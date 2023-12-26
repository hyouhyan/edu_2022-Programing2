#include<stdio.h>

typedef struct trial{
    int speed;
    int distance;
}Trial;

void dispTrial(Trial trial){
    printf("speed: %d\n", trial.speed);
    printf("distance: %d\n", trial.distance);
}

int main(void){
    Trial p;
    char line[]="10,18\n";

    sscanf(line, "%d,%d", &p.speed, &p.distance);

    dispTrial(p);

    return 0;
}