#include <stdio.h>

int main(){
	// membuat variabel
	int umur = 19;
	float tinggi = 175.6;
	
	// membuat pointer
	int *ptr_umur = &umur;
	int *ptr2 = &umur;
	float *ptr_tinggi = &tinggi;
	
	// mencetak alamat memori
	printf("alamat memori variabel 'umur' = %d\n", &umur);
	printf("alamat memori variabel 'tinggi' = %d\n", &tinggi);
	
	printf("\n");
	
	// mencetak referensi alamat memori
	printf("referensi alamat memori *ptr_umur = %d\n", ptr_umur);
	printf("referensi alamat memori *ptr2 = %d\n", ptr2);
	printf("referensi alamat memori *ptr_tinggi = %d\n", ptr_tinggi);
	
	printf("\n");
	
	// mentcetak alamat memori
	printf("alamat memori *ptr_umur = %d\n", &ptr_umur);
	printf("alamat memori *ptr2 = %d\n", &ptr2);
	printf("alamat memori *ptr_tinggi = %d\n", &ptr_tinggi);
	
	return 0;
	
}
