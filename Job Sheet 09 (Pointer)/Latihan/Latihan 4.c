#include <stdio.h>

int main(){
	printf("=== Program Antrian CS ===\n");
	
	char no_antri[5] = {'A', 'B', 'C', 'D', 'E'};
	
	//menggunakan pointer
	char *ptr_current = no_antri;
	
	for(int i=0; i<5; i++){
		printf("Pelanggan dengan nomor antrian %c silahkan ke loket!\n", *ptr_current);
		printf("Saat ini CS sedang melayani: %c\n", *ptr_current);
		printf("--------- Tekan Enter untuk Next ---------");
		getchar();
		ptr_current++;
	}
	
	printf("Selesai");
	
	return 0;
}