# Praktikum_Algoritma
Dibimbing oleh pak Randi Proska

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int tebakan;
    char lanjut;

    srand(time(NULL));
    int x = rand() % 20;
    printf("%d\n", x);

    do {
        while (1) {
            printf("Masukkan tebakan anda: ");
            scanf("%d", &tebakan);
            getchar();

            if (tebakan < x) {
                printf("Nomor saya lebih besar! ");
            } else if (tebakan > x) {
                printf("Nomor saya lebih kecil! ");
            } else {
                printf("Selamat Anda benar! ");
                break;
            }
        }

        printf("Apakah anda ingin bermain lagi? (y/n) ");
        scanf(" %c", &lanjut);

    } while (lanjut == 'y');

    return 0;
}
