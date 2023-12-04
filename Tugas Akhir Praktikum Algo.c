// Created by Syahid Nurhidayatullah (23343056)

//ide saat ini adalah untuk membuat toserba game RPG

#include <stdio.h>

//  Struct untuk menghitung jumlah barang yang tersedia
struct senjata {
	int pedang;
	int panah;
	int tombak;
	int tongkat;
};
struct item {
	int hp_potion;
	int mp_potion;
	int exp_potion;
	int str_up;
	int def_up;
};
struct kostum {
	int zirah;
	int zirah_lapis_kulit_naga;
	int jubah_tahan_api;
};

//  Fungsi yang akan dijalankan apabila user memilih piihan senjata di main menu
int pilih_senjata() {
	printf("Senjata apa yang ingin Anda beli?\n");
	printf("1. Pedang\n");
	printf("2. Busur\n");
	printf("3. Tombak\n");
	printf("4. Tongkat\n");
}

//  Fungsi yang akan dijalankan apabila user memilih piihan item di main menu
int pilih_item() {
	printf("Item apa yang ingin Anda beli?\n");
	printf("1. hp_potion\n");
	printf("2. mp_potion\n");
	printf("3. exp_potion\n");
	printf("4. str_up\n");
	printf("5. def_up\n");
}

//  Fungsi yang akan dijalankan apabila user memilih piihan 'kostum' di main menu
int pilih_kostum() {
	printf("Kostum apa yang ingin Anda beli?\n");
	printf("1. Zirah\n");
	printf("2. Jubah\n");
}

//  Fungsi yang akan dijalankan apabila user memilih piihan 'gacha' di main menu
int gacha() {
	printf("Hahahaha");
}

int main(){
	char player;
	int pilihan_menu_utama, i, uangku = 5000;
	
	while (pilihan_menu_utama != 5) {		
		printf("- Main Menu -\n");
		printf("1. Senjata\n");
		printf("2. Toko Item\n");
		printf("3. Kostum\n");
		printf("4. Gacha\n");
		printf("5. Keluar\n");
		
		printf("-> %d", uangku);
		scanf("%d", &pilihan_menu_utama);
		fflush(stdin);
		
		
		switch (pilihan_menu_utama) {
			case 1:
				pilih_senjata();
				break;
			case 2:
				pilih_item();
				break;
			case 3:
				pilih_kostum();
				break;
			case 4:
				gacha();
				break;
			case 5:
				break;
			default:
				printf("Looking forward to the Weekend\n");
				
		}
	}
	
	return 0;
}

