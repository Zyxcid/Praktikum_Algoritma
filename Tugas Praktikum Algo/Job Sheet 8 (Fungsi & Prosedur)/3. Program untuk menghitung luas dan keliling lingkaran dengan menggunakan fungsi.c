// Program untuk menghitung luas dan keliling lingkaran dengan menggunakan fungsi

#include <stdio.h>

#define phi 3.14

// jari-jari = r
float jari_jari;

// menghitung luas lingkaran
float luas(float r) {
	return phi * r * r;
}

// menghitung keliling lingkaran
float keliling(float r) {
	return 2 * phi * r;
}


int main() {
	printf("Masukkan jari-jari dari lingkaran tersebut: ");
	scanf("%f", &jari_jari);
	printf("Luas dari lingkaran tersebut adalah: %.2f\n", luas(jari_jari));
	printf("Keliling dari lingkaran tersebut adalah: %.2f\n", keliling(jari_jari));
}
