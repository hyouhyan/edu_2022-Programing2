#include<stdio.h>

typedef struct earthquake{
    int year;
    int month;
    int day;
    double lat;
    double lon;
    int scale;
}EQ;

void printEQ(EQ eqInfo);

int main(void){
    EQ eqInfo;
    char line[] = "2011,1,3,38.573833,139.262500,4";
    sscanf(line, "%d,%d,%d,%lf,%lf,%d", &eqInfo.year, &eqInfo.month, &eqInfo.day, &eqInfo.lat, &eqInfo.lon, &eqInfo.scale);

    printEQ(eqInfo);

    return 0;
}

void printEQ(EQ eqInfo){
    printf("Year\t%d\n", eqInfo.year);
    printf("Month\t%d\n", eqInfo.month);
    printf("Day\t%d\n", eqInfo.day);
    printf("Lat\t%f\n", eqInfo.lat);
    printf("Lon\t%f\n", eqInfo.lon);
    printf("Scale\t%d\n", eqInfo.scale);
}