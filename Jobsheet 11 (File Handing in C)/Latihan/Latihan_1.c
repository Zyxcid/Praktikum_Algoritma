#include <stdio.h>

int main(){
	char buff[255];
	FILE *fptr;
	
	// membuka file
	if ((fptr = fopen("namasaya.txt", "r")) == NULL){
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
	while(fgets(buff, sizeof(buff), fptr)){
		printf("%s", buff);
	}
	
	// tutup file
	fclose(fptr);
	
	return 0;
}
