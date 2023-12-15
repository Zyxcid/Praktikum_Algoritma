// Created by Syahid Nurhidayatullah (23343056)

#include <stdio.h>

int main () {
    char nama_pembeli[18], nama_barang[18];
    int harga_barang, jumlah_barang, harga_total;

	// Meminta input dari user berupa nama pembeli, nama barang, harga barang, dan jumlah barang
	printf("Masukkan nama Anda: ");
	scanf("%s", &nama_pembeli);
	
	printf("Masukkan nama barang belanjaan Anda: ");
	scanf("%s", &nama_barang);
	
	printf("Masukkan harga barang: ");
	scanf("%d", &harga_barang);

	printf("Masukkan jumlah barang: ");
	scanf("%d", &jumlah_barang);

	// Menghitung harga total berdasarkan harga barang dan jumlah barang
	harga_total = (harga_barang * jumlah_barang);

	// Menampilkan hasil
	printf("\n======================================================================\n");
	printf("Halo %s\nAnda membeli %s\nHarga total belanjaan Anda adalah: Rp.%d", nama_pembeli, nama_barang, harga_total);
	printf("\n======================================================================\n");

	return 0;
}
