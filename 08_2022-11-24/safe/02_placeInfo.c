#include<stdio.h>

// typedef表記を使うと「struct PlaceInfo」を「PlaceInfo」の1単語で表せれる
typedef struct placeInfo{
    double latitude;
    double longitude;
    char address[256];
}PlaceInfo;

void printInfo(char *name, PlaceInfo l){
    printf("%s: %f, %f, %s\n", name, l.latitude, l.longitude, l.address);
}

int main(void){
    PlaceInfo ait = {35.18357878731865, 137.11305262660434, "〒470-0356 愛知県豊田市八草町八千草１２４７"};
    PlaceInfo meiden = {35.17841226286768, 136.9490077897374, "〒464-0083 愛知県名古屋市千種区若水３丁目２−１２"};

    printInfo("愛好大", ait);
    printInfo("名電", meiden);

    return 0;
}