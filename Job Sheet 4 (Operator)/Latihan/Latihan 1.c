#include <stdio.h> // library standar input output

// main function
main(void){
	// deklarasi variabel
	int a, b, c;
	
	// meminta input dari user dan menyimpannya di variabel a dan b
	printf("Inputkan nilai a: ");
	scanf("%i", &a);
	
	printf("Inputkan nilai b: ");
	scanf("%i", &b);
	
	// menjumlahkan nilai a dan b dan menyimpannya di variabel c
	c = a + b;
	
	// memprint hasil penjumlahan
	printf("Hasil a + b: %i", c);
}
