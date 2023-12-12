// Created by Syahid Nurhidayatullah (23343056)

#include <stdio.h>

int main() {
	int lesley = 57082, layla, balmond;
	
    printf("Untuk pertanyaan A\n");
    layla = lesley;
    balmond = layla + 1;
    //  Nilai Lesley
    printf("Nilai Layla = %d\n", layla);
    //  Nilai Balmond
    printf("Nilai Balmond = %d\n\n", balmond);
	
	
    printf("Untuk pertanyaan B\n");
	int *ptr_layla = &lesley;
    balmond = *ptr_layla + 1;
	//  Nilai Layla
    printf("Nilai Layla = %d\n", *ptr_layla);
    //  Nilai Balmond
    printf("Nilai Balmond = %d\n", balmond);
	
    return 0;
}

