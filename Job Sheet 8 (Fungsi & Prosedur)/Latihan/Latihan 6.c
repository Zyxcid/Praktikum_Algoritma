#include <stdio.h>

void kali_dua(int *num){
	*num = *num * 2;
}

int main(){
	int angka = 9;
	
	// memanggil fungsi
	kali_dua(&angka);
	
	// mencetak isi variabel
	// setelah fungsi dipanggil
	printf("Isi variabel angka = %d\n", angka);
	
	return 0;
}