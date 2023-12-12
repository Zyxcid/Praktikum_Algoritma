// Created by Syahid Nurhidayatullah (23343056)

#include <stdio.h>

int main() {
	int harga_jam_pertama = 15000;
	int harga_jam_sisa = harga_jam_pertama / 2;
	int durasi = 3;
	int total_harga;

	if (durasi > 1) {
		int durasi_sisa = durasi - 1; // 3 - 1 = 2
		int harga_jam_sisa_total = durasi_sisa * harga_jam_sisa; // 2 * 7500 = 15000
		total_harga = harga_jam_pertama + harga_jam_sisa_total; // 15000 + 15000 = 30000
	} else {
		total_harga = harga_jam_pertama; // 15000
	}

	//
	printf("Untuk durasi 3 jam, total harga adalah: Rp %d\n", total_harga);

	return 0;
}
