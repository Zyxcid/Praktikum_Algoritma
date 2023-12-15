#include <stdio.h> // Library standar yang digunakan untuk input dan output

// Fungsi utama
int main(){
	// Deklarasi variabel
	int usia = 19;
	float berat = 65.3;
	double tinggi = 178.43;
	char jenis_kelamin = 'L';
	
	// Menampilkan output
	printf("Usia: %i tahun\n", usia);
	printf("Tinggi: %.2f cm\n", tinggi);
	printf("Berat: %.2f kg\n", berat);
	printf("Jenis kelamin: %c\n", jenis_kelamin);
	
	return 0;
}