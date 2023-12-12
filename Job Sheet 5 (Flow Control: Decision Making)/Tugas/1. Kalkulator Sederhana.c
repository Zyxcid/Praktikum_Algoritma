// Created by Syahid Nurhidayatullah (23343056)
// Kalkulator Sederhana

#include <stdio.h>

int main() {
	double a,b;
	char pilihan;
	
	printf("Input jenis operasi yang akan dilakukan (+, -, /, *)\n");
	scanf("%c", &pilihan);

	printf("Input angka 1: ");
	scanf("%lf", &a);

	printf("Input angka 2: ");
	scanf("%lf", &b);
	
	switch(pilihan){
		case '+':
			printf("%.lf", a+b);
			break;
		case '-':
			printf("%.lf", a-b);
			break;
		case '*':
			printf("%.lf", a*b);
			break;
		case '/':
			printf("%.2lf", a/b);
			break;
		default:
			printf("Masukkan input yang valid!");
			break;
	}
}
