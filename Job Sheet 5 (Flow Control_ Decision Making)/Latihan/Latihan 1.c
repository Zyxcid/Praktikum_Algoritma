#include <stdio.h>

main(void){
	printf("== Program Pembayaran ==\n");
	int total_belanja = 0;
	
	printf("Inputkan total belanja : ");
	scanf("%i", &total_belanja);
	
	// if statement untuk mengecek apakah total belanja lebih dari 100000
	if(total_belanja > 100000){
		printf("Selamat, Anda mendapatkan hadiah!\n");
	}
	
	printf("Terimakasih sudah berbelanja di toko kami\n");
}
