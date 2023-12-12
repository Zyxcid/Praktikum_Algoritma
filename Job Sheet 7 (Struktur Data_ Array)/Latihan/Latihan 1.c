#include <stdio.h>

main(void){
	//isi awal array
	char huruf[5] = {'a', 'b', 'c', 'd', 'e'};
	
	//mengubah isi array
	huruf[2] = 'r';
	
	//mencetak isi array
	printf("Huruf : %c\n", huruf[2]);
}