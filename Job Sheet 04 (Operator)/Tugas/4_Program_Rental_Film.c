// Created by Syahid Nurhidayatullah (23343056)

#include <stdio.h>

int main() {
	int harga_jam_pertama = 15000;
	int harga_jam_sisa = harga_jam_pertama / 2; // setelah satu jam pertama harga didiskon 50%
	int durasi = 3;
	int total_harga;

	if (durasi > 1) { // jika durasi lebih dari 1 jam
		int durasi_sisa = durasi - 1; // menghitung durasi selain jam pertama
		int harga_jam_sisa_total = durasi_sisa * harga_jam_sisa; // menghitung harga total selain jam pertama
		total_harga = harga_jam_pertama + harga_jam_sisa_total; // 15000 + 15000 = 30000
	} else {
		total_harga = harga_jam_pertama; // jika durasi hanya 1 jam, maka harga total adalah harga jam pertama
	}

	// menampilkan total harga
	printf("Untuk durasi 3 jam, total harga adalah: Rp %d\n", total_harga);

	return 0;
}
