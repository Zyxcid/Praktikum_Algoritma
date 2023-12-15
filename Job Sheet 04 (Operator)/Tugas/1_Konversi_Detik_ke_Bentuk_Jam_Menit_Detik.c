// Created by Syahid Nurhidayatullah (23343056)

#include <stdio.h>

int main () {
    int jam, menit, detik, detik_total;
    
	// Judul
	printf("\n===== Alat Detik ke Bentuk Jam, Menit, Detik =====\n\n");
	// Meminta input detik
	printf("Masukkan nilai detik: ");
	scanf("%d", &detik_total);
    
	// Konversi detik ke jam, menit, detik
	jam = detik_total/3600;
	menit = (detik_total%3600) / 60;
	detik = (detik_total%60);
	
	// Menampilkan hasil
	printf("%d:%d:%d\n", jam, menit, detik);
	
	return 0;
}
