// Created by Syahid Nurhidayatullah (23343056)
/*
program ATM

No Rek: 0123 
Nama Akun: Hatori
Saldo ATM: Rp. 175.000 
*/
#include <stdio.h>

int saldo = 175000;
char nama[10] = "Hatori";
int norek = 0123;

void cek_saldo(){
	printf("Saldo anda adalah: Rp. %d\n", saldo);
}

void setoran(){
	int jumlah_setoran;
	printf("Masukkan jumlah yang ingin disetorkan: ");
	scanf("%d", &jumlah_setoran);
	saldo += jumlah_setoran;
}

void penarikan_tunai(){
	int jumlah_penarikan;
	printf("Masukkan jumlah yang ingin ditarik: ");
	scanf("%d", &jumlah_penarikan);
	if (saldo>0 && saldo>= jumlah_penarikan){
		saldo -= jumlah_penarikan;
		return;
	}
	printf("Saldo tidak mencukupi\n");
}

int main(){
	int pilihan; 
	
	do{
		printf("1) Cek Saldo \n2) Setoran \n3) Penarikan Tunai \n4) Exit\n");
		printf("Masukkan pilihan anda: ");
		scanf("%d", &pilihan);
        getchar(); // Membersihkan karakter newline dari buffer

		switch(pilihan){
			case 1:
				cek_saldo();
				break;
			case 2:
				setoran();
				break;
			case 3:
				penarikan_tunai();
				break;
			case 4:
                printf("Keluar dari program.\n");
                break;
			default:
                printf("Pilihan tidak valid.\n");
		}
		
	} 
	while(pilihan!=4);
	
	return 0;
}
