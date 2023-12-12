#include <stdio.h>

int main(){
	//deklarasi array of char
	char nama[20];
	
	printf("Masukkan nama anda : ");
	gets(nama);
	
	printf("Hello, %s. Salam kenal.", nama);
	
	return 0;
}