#include <stdio.h> // library standar input output

// main function
main(void){
	// deklarasi variabel a dan b
	int a, b;
	//float a, b; //gunakan apabila data yang diinputkan adalah desimal
	
	//meminta input dari user dan menyimpannya di variabel a dan b
	printf("Inputkan nilai a: ");
	scanf("%i", &a);
	
	printf("Inputkan nilai b: ");
	scanf("%i", &b);
	
	// memprint hasil penjumlahan, pengurangan, perkalian, pembagian, dan sisa bagi
	printf("Hasil a + b: %i\n", a + b); //penjumlahan
	printf("Hasil a - b: %i\n", a - b); //pengurangan
	printf("Hasil a * b: %i\n", a * b); //perkalian
	printf("Hasil a / b: %i\n", a / b); //pembagian
	printf("Hasil a % b: %i\n", a % b); //sisa bagi
	
	//printf("Hasil a / b : %f\n", a / b);
}