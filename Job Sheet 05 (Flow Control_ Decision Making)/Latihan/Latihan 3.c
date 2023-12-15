#include <stdio.h>

main(void){
	int nilai;
	char grade;
	
	printf("=== Program Grade Nilai ===\n");
	printf("Inputkan nilai : ");
	scanf("%i", &nilai);
	
	// menggunakan percabangan if/else if/else
	if(nilai >= 90){
		grade = 'A';
	} else if (nilai >= 80){
		grade = 'B';
	} else if (nilai >= 70){
		grade = 'B-';
	} else if (nilai >= 60){
		grade = 'C';
	} else if (nilai >= 50){
		grade = 'C-';
	} else if (nilai >= 40){
		grade = 'D';
	} else if (nilai >= 30){
		grade = 'E';
	} else{
		grade = 'F';
	}
	
	printf("Nilai : %i\n", nilai);
	printf("Grade anda : %c\n", grade);
}
