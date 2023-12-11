// Created by Syahid Nurhidayatullah 23343056

#include <stdio.h>

// Membuat struktur untuk data mahasiswa
struct mahasiswa {
    int npm;
    char nama[39];
    char tanggalLahir[12];
    char alamat[100];
    int nomorHp;
};

int main() {
    int jumlahMahasiswa = 0;
    struct mahasiswa Mahasiswa[jumlahMahasiswa];
    char input;

    int i = 0;
    while (1) {
        printf("\nMahasiswa ke: %d\n", i + 1);
        printf("NPM: ");
        scanf("%d", &Mahasiswa[i].npm);
        printf("NAMA: ");
        scanf("%s", Mahasiswa[i].nama);
        printf("TANGGAL LAHIR: ");
        scanf("%s", Mahasiswa[i].tanggalLahir);
        printf("ALAMAT: ");
        scanf("%s", Mahasiswa[i].alamat);
        printf("HP: ");
        scanf("%d", &Mahasiswa[i].nomorHp);

        jumlahMahasiswa++;  // Jumlah mahasiswa ditambah 1 untuk dipakai di loop untuk menampilkan output

        printf("Mau memasukkan data lagi [y/t]? ");
        scanf(" %c", &input);
        if (input != 'Y' && input != 'y') {
            break;
        }

        i++; // Supaya data mahasiswa selanjutnya dimasukkan ke array selanjutnya
    }

    // Menampilkan data mahasiswa
    printf("\nJumlah Mahasiswa: %d\n", jumlahMahasiswa);
    printf("NPM\tNAMA\tTANGGAL LAHIR\tALAMAT\tHP\n");
    for (int i = 0; i < jumlahMahasiswa; i++) {
        printf("%d\t%s\t%s\t%s\t%d\n", Mahasiswa[i].npm, Mahasiswa[i].nama, Mahasiswa[i].tanggalLahir, Mahasiswa[i].alamat, Mahasiswa[i].nomorHp);
    }

    return 0;
}