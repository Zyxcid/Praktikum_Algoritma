#include <stdio.h>

int main(){
	char buff[255];
	char text[255];
	FILE *fptr;
	
	// membuka file
	fptr = fopen("namasaya.txt", "w");
	
	for(int i = 0; i < 5; i++){
	
	// mengambil input dari user
	printf("Inputkan isi file : ");
	fgets(text, sizeof(text), stdin);
	
	// menulis ke text ke file
	fputs(text, fptr);
	}
	
	printf("File berhasil ditulis\n");
	
	// tutup file
	fclose(fptr);
	
	// buka kembali file untuk dibaca
	fptr = fopen("namasaya.txt", "r");
	
	// baca isi file dengan gets lalu simpan ke buff
	while(fgets(buff, sizeof(buff), fptr)){
		printf("Isi filenya sekarang: %s", buff);
	}
	
	// tutup file
	fclose(fptr);
	
	return 0;
}
