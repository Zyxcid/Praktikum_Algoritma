#include <stdio.h>

// enum adalah tipe data yang berisi kumpulan konstanta
enum hari {SENIN, SELASA, RABU, KAMIS, JUMAT, SABTU, MINGGU};

int main(){
	// deklarasi variabel hari sekarang bertipe data enum hari
	enum hari sekarang;
	sekarang = RABU;
	printf("Sekarang hari ke-%d", sekarang +1);
	
}
