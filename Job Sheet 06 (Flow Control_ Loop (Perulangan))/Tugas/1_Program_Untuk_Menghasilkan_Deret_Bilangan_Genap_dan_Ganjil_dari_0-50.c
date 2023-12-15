// Created by Syahid Nurhidayatullah (23343056)
// Program untuk menghasilkan deret bilangan genap dan ganjil dari 0 - 50

#include <stdio.h>

int main() {
	int i;
	printf("Deret bilangan genap dari 0 - 50\n");
	for (i=0;i<=50;i += 2){ // untuk menampilkan deret bilangan genap dari 0 - 50 dimulai dari 0 dengan increment 2 (i += 2)
		printf("%d\n", i);
	}
	
	printf("\n");

	printf("Deret bilangan ganjil dari 0 - 50\n");
	for (i=1;i<=50;i += 2){ // untuk menampilkan deret bilangan ganjil dari 0 - 50 dimulai dari 1 dengan increment 2 (i += 2)
		printf("%d\n", i);	
	}

	return 0;
}
