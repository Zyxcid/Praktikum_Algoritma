#include <stdio.h>
#include <string.h>

main(void){
	//membuat array karakter untuk menyimpan username dan password
	char username[30], password[30];
	
	printf("=== Welcome to Awesome Program ===\n");
	printf("Username : ");
	scanf("%s", &username);
	printf("Password : ");
	scanf("%s", &password);
	
	// if else bersarang
	if(strcmp(username, "petanikode") == 0){
		if(strcmp(password, "kopi") == 0){
		printf("Selamat datang bos!\n");
		} else{
		printf("Password salah, coba lagi!\n");
		}
	} else{
		printf("Anda belum terdaftar\n");
	}
}
