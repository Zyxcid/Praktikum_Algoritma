#include <stdio.h>

int main(){
	char buff[255]; // deklarasi variabel buff dengan tipe data char dan panjang 255
	FILE *fptr; // deklarasi variabel fptr dengan tipe data FILE
	
	// membuka file namasaya.txt dengan mode read
	if ((fptr = fopen("namasaya.txt", "r")) == NULL){ // jika file tidak ditemukan
		printf("File tidak ditemukan!");
		// tutup program karena file tidak ada
		return 1;
	}
	
	/*fgets(buff, sizeof(buff), fptr);
	printf("%s", buff);
	fgets(buff, sizeof(buff), fptr);
	printf("%s", buff);
	fgets(buff, sizeof(buff), fptr);
	printf("%s", buff);*/
	
	// membaca isi file dengan gets lalu simpan ke buff
	while(fgets(buff, sizeof(buff), fptr)){ // selama file belum habis
		printf("%s", buff);
	}
	
	// tutup file
	fclose(fptr);
	
	return 0;
}
