// Created by Syahid Nurhidayatullah 23343056

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int tebakan;
    char lanjut;

    do {
        srand(time(NULL));
        int x = rand() % 20;
		
		int jumlah_percobaan = 0;
        while (1) {
			printf("Jumlah percobaan: %d\n", jumlah_percobaan);

            printf("Masukkan tebakan anda: ");
            scanf("%d", &tebakan);
            getchar();

            if (tebakan < x) {
                printf("Nomor saya lebih besar!\n\n");
            } else if (tebakan > x) {
                printf("Nomor saya lebih kecil!\n\n");
            } else {
                printf("~Selamat Anda benar!~\n\n");
                break;
            }
            jumlah_percobaan++;
        }

        printf("Apakah anda ingin berhenti? (y/n) ");
        scanf("%c", &lanjut);

    } while (lanjut != 'y' && lanjut != 'Y');

    return 0;
}

