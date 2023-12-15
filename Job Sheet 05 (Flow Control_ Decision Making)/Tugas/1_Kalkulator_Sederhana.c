// Created by Syahid Nurhidayatullah (23343056)
// Kalkulator Sederhana

#include <stdio.h>

int main() {
	double a,b;
	char pilihan;
	
	// Input operasi yang akan dilakukan pada kalkulator
	printf("Input jenis operasi yang akan dilakukan (+, -, /, *)\n");
	scanf("%c", &pilihan);

	// Input angka yang akan dioperasikan
	printf("Input angka 1: ");
	scanf("%lf", &a);

	printf("Input angka 2: ");
	scanf("%lf", &b);
	
	// Switch case untuk menentukan operasi yang akan dilakukan berdasarkan input pilihan
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
