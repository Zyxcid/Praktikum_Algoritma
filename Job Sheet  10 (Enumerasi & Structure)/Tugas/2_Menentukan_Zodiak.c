// created by Syahid Nurhidayatullah 23343056

#include <stdio.h>

// Mendefinisikan struktur untuk data tanggal
struct Tanggal {
    int tgl;
    int bln;
    int tahun;
};

// Mendefinisikan struktur untuk zodiak
struct Zodiak {
    struct Tanggal awal;
    struct Tanggal akhir;
    const char* nama;
};

// Membuat array zodiak
struct Zodiak zodiak[12] = {
    {{20, 1, 0}, {18, 2, 0}, "CAPRICORN"},
    {{19, 2, 0}, {20, 3, 0}, "PISCES"},
    {{21, 3, 0}, {19, 4, 0}, "ARIES"},
    {{20, 4, 0}, {20, 5, 0}, "TAURUS"},
    {{21, 5, 0}, {20, 6, 0}, "GEMINI"},
    {{21, 6, 0}, {22, 7, 0}, "CANCER"},
    {{23, 7, 0}, {22, 8, 0}, "LEO"},
    {{23, 8, 0}, {22, 9, 0}, "VIRGO"},
    {{23, 9, 0}, {22, 10, 0}, "LIBRA"},
    {{23, 10, 0}, {21, 11, 0}, "SCORPIO"},
    {{22, 11, 0}, {21, 12, 0}, "SAGITTARIUS"},
    {{22, 12, 0}, {19, 1, 0}, "CAPRICORN"}
};

int main() {
    struct Tanggal tanggal_lahir;

    // Memasukkan tanggal lahir
    printf("Tanggal Lahir Anda [tgl-bln-tahun] : ");
    scanf("%d-%d-%d", &tanggal_lahir.tgl, &tanggal_lahir.bln, &tanggal_lahir.tahun);

    // Menentukan zodiak
    int i;
    for (i = 0; i < 12; i++) {
        if ((tanggal_lahir.bln == zodiak[i].awal.bln && tanggal_lahir.tgl >= zodiak[i].awal.tgl) ||
            (tanggal_lahir.bln == zodiak[i].akhir.bln && tanggal_lahir.tgl <= zodiak[i].akhir.tgl)) {
            printf("Zodiak Anda adalah : %s\n", zodiak[i].nama);
            break;
        }
    }

    if (i == 12) {
        printf("Tanggal lahir tidak valid.\n");
    }

    return 0;
}