// Created by Syahid Nurhidayatullah (23343056)

#include <stdio.h>

int main(){
	double rupiah, dolar, uang;
	rupiah = 2500000; // 2.500.000
	dolar = rupiah/14250; // mengkonversi rupiah ke dolar
	
	// menampilkan hasil konversi
	printf("berikut adalah konversi dari rupiah ke dolar\n");
	printf("(Rp.2.500.000) (1$ = Rp.14.250)\n");	
	printf("dolar: %.2lf", dolar);

	return 0;
}
