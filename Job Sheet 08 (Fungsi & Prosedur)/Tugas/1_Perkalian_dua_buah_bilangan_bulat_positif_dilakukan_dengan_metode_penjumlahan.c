// Created by Syahid Nurhidayatullah (23343056)

#include <stdio.h>

// Perkalian dua buah bilangan bulat positif dilakukan dengan 
// metode penjumlahan sebagai berikut: 12 x 6 = 12 + 12 + 12 + 12 + 12 + 12 
int perkalian(int a, int b) {
    if (b == 1) {
        return a;
    } else {
        return a + perkalian(a, b - 1); // memanggil dirinya sendiri
    }
}

int main() {
    printf(" %d", perkalian(12, 6));
    return 0;
}
