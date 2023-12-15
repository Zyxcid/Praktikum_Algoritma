#include <stdio.h>

int sum(int n);

main(void) {

	int number, result;
	printf("Masukkan angka : ");
	scanf("%d", &number);

	result = sum (number);

	printf("sum = %d", result);
	
}

int sum(int num) {
	// fungsi rekursif
	if (num!=0){
		return num + sum(num-1);
	}
	else{
		return num;
	}
}
