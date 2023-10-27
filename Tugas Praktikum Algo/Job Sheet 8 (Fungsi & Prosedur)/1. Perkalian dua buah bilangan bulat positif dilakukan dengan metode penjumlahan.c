//Perkalian dua buah bilangan bulat positif dilakukan dengan metode penjumlahan sebagai berikut: 12 x 6 = 12 + 12 + 12 + 12 +12 +12 

#include <stdio.h>

int perkalian(int a, int b) {
    if (b == 1) {
        return a;
    } else {
        return a + perkalian(a, b - 1);
    }
}

int main() {
    printf(" %d", perkalian(12, 6));
    return 0;
}
