#include <stdio.h> // library standar input output

// main function
int main(){
	// deklarasi variabel
	char nama[50], email[50];
	
	// meminta input nama dan email dari user
	printf("Nama: ");
	fgets(nama, sizeof(nama), stdin); // fgets adalah fungsi untuk membaca string dari input pengguna.
	
	printf("Email: ");
	fgets(email,  sizeof(email), stdin); // fgets adalah fungsi untuk membaca string dari input pengguna.
	
	// Note: fungsi fgets() lebih aman dibandingkan gets(), karena kita bisa menentukan ukuran buffer dan sumber inputan

	// memprint nama dan email yang diinputkan
	printf("\n----------------------------\n");
	printf("Nama anda: %s", nama);
	printf("Alamat email: %s", email);
	
	// return 0 berfungsi untuk mengakhiri program
	return 0;
}