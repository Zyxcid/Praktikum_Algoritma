// Created by Syahid Nurhidayatullah (23343056)

#include <stdio.h>

int main () { 
	int harga, diskon, harga_final;

	printf("===========Selamat datang di TOSERBA===========\n\n");	

	printf("Berapa harga total belanjaan Anda?\n-> ");
	scanf("%d", &harga);
	
	if (harga <= 75000){ // Jika harga <= 75000 maka diskon 5%
		diskon = harga * 5/100;
		harga_final = harga - diskon;
		printf("Selamat Anda mendapatkan diskon sebesar 5%%\n");
		printf("Harga total menjadi -> Rp.%d <-", harga_final);
	}
	else if (harga > 75000 && harga <= 125000){ // Jika harga > 75000 dan <= 125000 maka diskon 15%
		diskon = harga * 15/100;
		harga_final = harga - diskon;
		printf("Selamat Anda mendapatkan diskon sebesar 15%%\n");
		printf("Harga total menjadi -> Rp.%d <-", harga_final);
	}
	else if (harga > 125000){ // Jika harga > 125000 maka diskon 25% dan cashback 5000
		int cashback = 5000;
		diskon = harga * 25/100;
		harga_final = harga - diskon + cashback;
		printf("Selamat Anda mendapatkan diskon sebesar 25%% dan cashback sebesar Rp.5.000\n");
		printf("Harga total menjadi -> Rp.%d <-", harga_final);
	}
	return 0;
}