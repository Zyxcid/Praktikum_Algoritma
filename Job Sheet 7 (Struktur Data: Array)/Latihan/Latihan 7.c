#include <stdio.h>

int main(){
	// deklarasi array 2 dimensi
	int matriks[3][3] = {
		{1, 3, 5},
		{5, 3, 1},
		{6, 2, 3}
	};
	
	// mencetak isi array 
	printf("Isi Data pada indeks ke-(0,0) : %d\n", matriks[0][0]);
	printf("Isi Data pada indeks ke-(0,1) : %d\n", matriks[0][1]);
	printf("Isi Data pada indeks ke-(0,2) : %d\n", matriks[0][2]);
	printf("Isi Data pada indeks ke-(1,0) : %d\n", matriks[1][0]);
	printf("Isi Data pada indeks ke-(1,1) : %d\n", matriks[1][1]);
	printf("Isi Data pada indeks ke-(1,2) : %d\n", matriks[1][2]);
	printf("Isi Data pada indeks ke-(2,0) : %d\n", matriks[2][0]);
	printf("Isi Data pada indeks ke-(2,1) : %d\n", matriks[2][1]);
	printf("Isi Data pada indeks ke-(2,2) : %d\n", matriks[2][2]);
}