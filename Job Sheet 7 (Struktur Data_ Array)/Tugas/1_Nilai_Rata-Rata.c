// Created by Syahid Nurhidayatullah (23343056)
// Mencari rata-rata dari nilai dari 20 mahasiswa

#include <stdio.h>

int main(){
	float nilai_mahasiswa[99];
	float nilai_total = 0;
	int jumlah_mahasiswa;
	
	printf("Masukkan jumlah mahasiswa: ");
	scanf("%d", &jumlah_mahasiswa);
	
	// Menginput nilai mahasiswa
	for (int i = 0; i < jumlah_mahasiswa; i++){
		printf("Masukkan nilai mahasiswa ke-%d: ", i + 1);
		scanf("%f", &nilai_mahasiswa[i]);
		nilai_total += nilai_mahasiswa[i];
	}
	
	// Menghitung rata rata
	float rata_rata = nilai_total/jumlah_mahasiswa;
	
	printf("Nilai rata-rata dari %d mahasiswa adalah: %.2f", jumlah_mahasiswa, rata_rata);
	
	
}
