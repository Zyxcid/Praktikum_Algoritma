// Created by Syahid Nurhidayatullah (23343056)
// Program Array Untuk Menampung Input Nama Mahasiswa dari Keyboard.

#include <stdio.h>

int jumlah_mahasiswa;
char nama [99][50];
int i;

int main() {
	printf("Input banyak siswa: ");
	scanf("%d", &jumlah_mahasiswa);
	
	// Input nama mahasiswa ke dalam array dengan perulangan for
	for(i = 0; i < jumlah_mahasiswa; i++) {
		printf("Input nama peserta ke-%d: ", i + 1); // i + 1 karena array dimulai dari 0
		scanf("%s", &nama[i]); // Memasukkan nama mahasiswa ke dalam array
	}
	
	printf("\n");
	
	// Menampilkan nama mahasiswa dengan perulangan for
	for(i = 0; i < jumlah_mahasiswa; i++) {
		printf("Nama mahasiswa ke-%d:\n-> %s\n", i + 1, &nama[i]);
	}
}
