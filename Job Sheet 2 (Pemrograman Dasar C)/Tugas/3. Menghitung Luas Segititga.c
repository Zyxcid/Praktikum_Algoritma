// Created by Syahid Nurhidayatullah (23343056)

#include <stdio.h>

int main(){
	double alas, tinggi, luas;
	
	printf("Alas: ");
	scanf("%lf", &alas);
	
	printf("Tinggi: ");
	scanf("%lf", &tinggi);
	
	luas = alas * tinggi;
	
	printf("Luas: %.2lf", luas);
	
	return 0;
}
