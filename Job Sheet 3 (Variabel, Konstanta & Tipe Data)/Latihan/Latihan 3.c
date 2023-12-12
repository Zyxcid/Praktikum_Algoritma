#include <stdio.h> // library standar input output

// konstanta adalah variabel yang nilainya tidak dapat diubah
// deklarasi konstanta menggunakan #define
#define SEPULUH 10
#define VERSI 4.5
#define JENIS_KELAMIN 'L'

// deklarasi fungsi main
int main() {
	// memprint isi dari konstanta
	printf("isi konstanta SEPULUH adalah %i\n", SEPULUH);
	printf("isi konstanta VERSI adalah %f\n", VERSI);
	printf("isi konstanta JENIS_KELAMIN adalah %c\n", JENIS_KELAMIN);

	return 0;
}
