// Created by Sha

#include <stdio.h>

int main () {
    int jam, menit, detik, detik_total;
    
	printf("\n===== Alat Detik ke Bentuk Jam, Menit, Detik =====\n\n");
	printf("Masukkan nilai detik: ");
	scanf("%d", &detik_total);
    
	jam = detik_total/3600;
	menit = (detik_total%3600) / 60;
	detik = (detik_total%60);
	
	printf("%d:%d:%d\n", jam, menit, detik);
	
	return 0;
}
