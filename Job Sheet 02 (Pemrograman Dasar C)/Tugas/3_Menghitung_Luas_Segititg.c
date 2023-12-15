// Created by Syahid Nurhidayatullah (23343056)

#include <stdio.h>

int main(){
	double alas, tinggi, luas;
	
	// Input alas dan tinggi
	printf("Alas: ");
	scanf("%lf", &alas);
	
	printf("Tinggi: ");
	scanf("%lf", &tinggi);
	
	// Hitung luas
	luas = alas * tinggi;
	
	// Tampilkan luas
	printf("Luas: %.2lf", luas);
	
	return 0;
}
