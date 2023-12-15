// Created by Syahid Nurhidayatullah (23343056)
// Program halaman login yang meminta pengguna untuk menginput username dan password

#include <stdio.h>
#include <string.h>

int main() {
    char password[] = "pass"; // Password yang benar
    char input[50];
    int attempts = 3; // Jumlah kesempatan login
    
    // Looping selama kesempatan login masih ada
    while (attempts > 0) {
        printf("Masukkan password: ");
        gets(input);
        attempts--;

        // Jika password benar, keluar dari loop
        if (strcmp(input, password) == 0) {
            printf("berhasil login\n");
            break;
        } else {
            printf("Password salah\n");
        }
    }

    return 0;
}
