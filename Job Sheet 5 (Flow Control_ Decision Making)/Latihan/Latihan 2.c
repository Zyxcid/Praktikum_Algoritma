#include <stdio.h>
#include <string.h>

main(void){
	// membuat array karakter untuk menyimpan password
	char password[30];
	
	printf("=== Program Login ===\n");
	printf("Masukkan password : ");
	scanf("%s", &password);
	
	// percabangan if/else
	if(strcmp(password, "kopi") == 0){ // strcmp digunakan untuk membandingkan string
		printf("Selamat datang bos!\n");
	} else{
		printf("Password salah, coba lagi!\n");
	}
	
	printf("Terimakasih sudah menggunakan aplikasi ini\n");
}
