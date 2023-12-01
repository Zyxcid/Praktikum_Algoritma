// Program untuk menghitung besarnya diskon
/*
a. Jika belanja dibawah 1 jt, maka tidak mendapatkan diskon
b. Jika belanja diatas 1 jt dan dibawah 3 jt, maka mendapat diskon 20%
c. Jika belanja diatas 3 jt, maka mendapat diskon 35%
*/

#include <stdio.h>

int harga, harga_final, diskon, potongan;

int potong(int harga) {
	if (harga <= 1000000) {
		diskon = 0;
	}
	else if (harga > 1000000 && harga <= 3000000) {
		diskon = 20;
	}
	else {
		diskon = 35;
	}
	//besar potongan harga
	potongan = harga * diskon/100;
	return potongan;
}

int main() {
	printf("- Program Hitung Potongan -\n\n");
	printf("Total Pembelian: Rp.");
	scanf("%d", &harga);
	potong(harga);
	harga_final = harga - potongan;
	
	printf("Besar Diskon: %d\n", potongan);
	printf("Besar Yang Harus Dibayarkan: %d\n", harga_final);
}
