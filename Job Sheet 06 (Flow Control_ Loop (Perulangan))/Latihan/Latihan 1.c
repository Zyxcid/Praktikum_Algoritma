#include <stdio.h>

main(void){
	
	//kondisi hitungan dimulai dari 1; hitungan sampai i<11; setiap perulangan akan +1
	for(int i=1; i<11; i++){
		printf("Perulangan ke-%d\n", i);
	}
	
	printf("\n"); 
	
	//menggunakan variabel counter
	/*for(int counter = 0; counter < 50; counter+=2){ //setiap perulangan nilai variabel + 2
		printf("Perulangan ke-%d\n", counter);
	}*/
	
	//menghitung mundur dari angka terbesar ke kecil
	for(int n=10; n>0; n--){
		printf("Perulangan ke-%d\n", n);
	}
}