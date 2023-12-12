#include <stdio.h>
#include <string.h>

//string
int main(){
	
	printf("=== Fungsi String.h in C ===\n");
	
	// 1. strcpy
	printf("1.strcpy()\n");
	
	char title[] = "Belajar String.h pada Bahasa C";
	char title_copy[20];
	
	//copy string title ke title_copy
	strcpy(title_copy, title);
	
	//maka sekarang title_copy akan berisi :
	printf("Isi title_copy\t: %s\n", title_copy);
	
	printf("\n");
	
	// 2. strcat
	printf("2.strcat()\n");
	char nama[] = "Radhia Aulia Nisa";
	char gelar[] = ", S.Kom., M.T.";
	
	strcat(nama, gelar);
	
	printf("Nama Lengkap\t: %s\n", nama);
	
	printf("\n");
	
	// 3. strlen
	printf("3.strlen()\n");
	
	char name[] = "_________________";
	int panjang_nama;
	
	// menghitung panjang nama
	panjang_nama = strlen(nama);
	
	printf("Nama\t: %s\n", nama);
	printf("Panjang\t: %d karakter\n", panjang_nama);
	
	printf("\n");
	
	// 4. strcmp
	printf("4.strcmp()\n");
	
	char str1[] = "Agariadne";
	char str2[] = "Agariadne";
	int hasil;
	
	//membandingkan string
	hasil = strcmp(str1, str2);
	
	if(hasil == 0){
		printf("str1 dan str 2 sama");
	} else{
		printf("str1 dan str 2 berbeda");
	}
	
	return 0;
}