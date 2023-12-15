// Created by Syahid Nurhidayatullah (23343056)
// Membuat program sesuai algoritma yang diberikan

#include <stdio.h>

int main(){
	char nama[20], prodi[20], fakultas[20]; // Deklarasi variabel nama, prodi, dan fakultas bertipe data char
	int nim, nilai_praktikum, nilai_uts, nilai_uas, nilai_akhir; // Deklarasi variabel nim, nilai_praktikum, nilai_uts, nilai_uas, dan nilai_akhir bertipe data integer
	
	// Input data diri mahasiswa
	printf("Nama: ");
	scanf("%s", &nama);
	
	printf("NIM: ");
	scanf("%d", &nim);

	printf("Prodi: ");
	scanf("%s", &prodi);

	printf("Fakultas: ");
	scanf("%s", &fakultas);

	// Input nilai mahasiswa
	printf("Nilai Praktikum: ");
	scanf("%d", &nilai_praktikum);

	printf("Nilai UTS: ");
	scanf("%d", &nilai_uts);

	printf("Nilai UAS: ");
	scanf("%d", &nilai_uas);

	// Menghitung nilai akhir
	nilai_akhir = (nilai_praktikum * 30/100) + (nilai_uts * 30/100) + (nilai_uas * 40/100);

	// Menampilkan data diri mahasiswa dan nilai akhir
	printf("\n=============================================\n");
	printf("Nama: %s\n", nama);
	printf("NIM: %d\n", nim);
	printf("Prodi: %s\n", prodi);
	printf("Fakultas: %s\n", fakultas);
	printf("Nilai Praktikum: %d\n", nilai_praktikum);
	printf("Nilai UTS: %d\n", nilai_uts);
	printf("Nilai UAS: %d\n", nilai_uas);
	printf("Nilai Akhir: %d\n", nilai_akhir);
	printf("=============================================\n");

	return 0;
}
