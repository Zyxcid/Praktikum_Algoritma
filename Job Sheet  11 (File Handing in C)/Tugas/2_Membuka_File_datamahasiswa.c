// Created by Syahid Nurhidayatullah 23343056

#include <stdio.h>

int main() {
    // Membuka file datamahasiswa.txt untuk dibaca
    FILE *file = fopen("datamahasiswa.txt", "r");

    if (file == NULL) {
        printf("Gagal membuka file.");
        return 1;
    }

    char data[100];

    // Membaca dan menampilkan isi file datamahasiswa.txt
    while (fgets(data, sizeof(data), file) != NULL) {
        printf("%s", data);
    }

    // Menutup file
    fclose(file);

    return 0;
}