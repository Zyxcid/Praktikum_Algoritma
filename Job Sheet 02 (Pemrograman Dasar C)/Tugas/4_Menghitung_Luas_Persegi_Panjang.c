// Created by Syahid Nurhidayatullah (23343056)

#include <stdio.h>

int main(){
	double panjang, lebar, luas;
	
	// Input panjang dan lebar
	printf("Panjang: ");
	scanf("%lf", &panjang);
	
	printf("Lebar: ");
	scanf("%lf", &lebar);
	
	// Hitung luas
	luas = panjang * lebar;
	
	// Tampilkan luas
	printf("Luas: %.2lf", luas);
	
	return 0;
}
