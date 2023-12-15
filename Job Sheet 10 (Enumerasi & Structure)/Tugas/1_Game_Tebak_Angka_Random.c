// Created by Syahid Nurhidayatullah 23343056

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int tebakan;
    char lanjut;

    do {

        srand(time(NULL)); // Agar angka yang diacak berbeda setiap kali program dijalankan
        int x = rand() % 20; // Membatasi angka yang diacak hingga 20 (0-19)
		
		int jumlah_percobaan = 0;
        while (1) {
			printf("Jumlah percobaan: %d\n", jumlah_percobaan);

            printf("Masukkan tebakan anda: ");
            scanf("%d", &tebakan);
            getchar();

            if (tebakan < x) { // Jika tebakan lebih kecil dari angka yang diacak
                printf("Nomor saya lebih besar!\n\n");
            } else if (tebakan > x) { // Jika tebakan lebih besar dari angka yang diacak
                printf("Nomor saya lebih kecil!\n\n");
            } else { // Jika tebakan sama dengan angka yang diacak
                printf("~Selamat Anda benar!~\n\n");
                break;
            }
            jumlah_percobaan++; // Kesempatan menebak akan berkurang setiap kali tebakan salah
        }

        // Meminta input untuk mengulang program
        printf("Apakah anda ingin berhenti? (y/n) ");
        scanf("%c", &lanjut);

    } while (lanjut != 'y' && lanjut != 'Y');

    return 0;
}

