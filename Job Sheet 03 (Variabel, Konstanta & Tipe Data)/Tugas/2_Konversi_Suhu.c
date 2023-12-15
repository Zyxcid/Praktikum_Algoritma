// Created by Syahid Nurhidayatullah (23343056)

#include <stdio.h>

int main(){
	double celcius, kelvin, fahrenheit, reamur;
	
	// Input suhu dalam celcius
	printf("Masukkan suhu dalam celcius: ");
	scanf("%lf", &celcius);
	
	// Konversi suhu ke kelvin, fahrenheit, dan reamur
	kelvin = celcius + 273.15;
	fahrenheit = (celcius * 1.8) + 32;
	reamur = celcius * 0.8;
	
	// Output hasil konversi
	printf("==================================\n");
	printf("Suhu dalam celcius: %.2lf\n", celcius);	
	printf("Suhu dalam kelvin: %.2lf\n", kelvin);	
	printf("Suhu dalam fahrenheit: %.2lf\n", fahrenheit);
	printf("Suhu dalam reamur: %.2lf\n", reamur);

	return 0;
}
