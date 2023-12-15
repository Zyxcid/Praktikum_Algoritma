// Created by Syahid Nurhidayatullah (23343056)

#include <stdio.h>

int main() {
    // Deklarasi array 2 dimensi
    char borland[6][8] = {"D", "ND", "AND", "LAND", "ORLAND", "BORLAND"};
    
    // Deklarasi pointer
    char (*ptr_borland)[8] = borland;
    
    // Menampilkan isi array 2 dimensi menggunakan pointer
    for (int i = 0; i < 6; i++) {
        printf("%s\n", ptr_borland[i]);
    }
    return 0;
}