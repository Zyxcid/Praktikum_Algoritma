#include <stdio.h>

int main(){
	double panjang, lebar, luas;
	
	printf("Panjang: ");
	scanf("%lf", &panjang);
	
	printf("Lebar: ");
	scanf("%lf", &lebar);
	
	luas = panjang * lebar;
	
	printf("Luas: %.2lf", luas);
	
	return 0;
}
