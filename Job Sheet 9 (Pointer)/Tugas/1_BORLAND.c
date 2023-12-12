// Created by Syahid Nurhidayatullah (23343056)

#include <stdio.h>

int main() {
    char borland[6][8] = {"D", "ND", "AND", "LAND", "ORLAND", "BORLAND"};
    
    char (*ptr_borland)[8] = borland;
    
    for (int i = 0; i < 6; i++) {
        printf("%s\n", ptr_borland[i]);
    }
    return 0;
}