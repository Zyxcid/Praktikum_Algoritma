// Created by Syahid Nurhidayatullah (23343056)
//  Ide saat ini adalah untuk membuat toserba game RPG
//  Hmm, kalau uangnya habis gimana? kutambahlah sistem GACHA!
//  Eh, kalau kalah gacha gimana? gacha kan perlu uang juga...
//  Yodahlah tambah musuh untuk dilawan:)
//  Kok jadi game turn based RPG wkwk

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define INVENTORY_SIZE 10

// Inventory player
struct penyimpanan {
    int emas;
    char inventory[INVENTORY_SIZE][39];
} saku = {100};

// Struct harga barang yang tersedia
struct senjata {
    int pedang;
    int busur;
    int tombak;
    int tongkat;
} Senjata = {20, 20, 40, 30};

struct item {
    int hp_potion;
    int mp_potion;
    int str_up;
    int def_up;
} Item = {4, 3, 6, 6};

struct kostum {
    int zirah;
    int zirah_II;
    int jubah;
} Kostum = {30, 55, 40};

//  Fungsi untuk menambahkan item ke inventory
void tambah_ke_inventory(struct penyimpanan *saku, const char *item_name) {
    for (int i = 0; i < INVENTORY_SIZE; ++i) {
        if (strlen(saku->inventory[i]) == 0) {
            strcpy(saku->inventory[i], item_name);
            break;
        }
    }
}

void pilih_senjata(struct penyimpanan *saku, struct senjata *sen) {
    printf("Senjata apa yang ingin Anda beli?\n");
    printf("1. Pedang\tharga: %d emas\n", sen->pedang);
    printf("2. Busur\tharga: %d emas\n", sen->busur);
    printf("3. Tombak\tharga: %d emas\n", sen->tombak);
    printf("4. Tongkat\tharga: %d emas\n", sen->tongkat);
    printf("9. Kembali\n");

    int pilihan_senjata;
    printf("-> ");
    scanf("%d", &pilihan_senjata);
    fflush(stdin);

    switch (pilihan_senjata) {
        case 1:
            if (saku->emas >= sen->pedang) {
                saku->emas -= sen->pedang;
                tambah_ke_inventory(saku, "Pedang");
                printf("Kamu telah membeli sebuah PEDANG\n");
            } else {
                printf("Emas tidak cukup!\n");
            }
            break;
        case 2:
            if (saku->emas >= sen->busur) {
                saku->emas -= sen->busur;
                tambah_ke_inventory(saku, "Busur");
                printf("Kamu telah membeli sebuah BUSUR\n");
            } else {
                printf("Emas tidak cukup!\n");
            }
            break;
        case 3:
            if (saku->emas >= sen->tombak) {
                saku->emas -= sen->tombak;
                tambah_ke_inventory(saku, "Tombak");
                printf("Kamu telah membeli sebuah TOMBAK\n");
            } else {
                printf("Emas tidak cukup!\n");
            }
            break;
        case 4:
            if (saku->emas >= sen->tongkat) {
                saku->emas -= sen->tongkat;
                tambah_ke_inventory(saku, "Tongkat");
                printf("Kamu telah membeli sebuah TONGKAT\n");
            } else {
                printf("Emas tidak cukup!\n");
            }
            break;
        case 9:
            break;
        default:
            printf("Masukkan input yang valid\n");
    }
}

void pilih_item(struct penyimpanan *saku, struct item *Item) {
    printf("Item apa yang ingin Anda beli?\n");
    printf("1. HP Potion\tharga: %d emas\n", Item->hp_potion);
    printf("2. MP Potion\tharga: %d emas\n", Item->mp_potion);
    printf("3. str_up\tharga: %d emas\n", Item->str_up);
    printf("4. def_up\tharga: %d emas\n", Item->def_up);
    printf("9. Kembali\n");

    int pilihan_item;
    printf("-> ");
    scanf("%d", &pilihan_item);
    fflush(stdin);

    switch (pilihan_item) {
        case 1:
            if (saku->emas >= Item->hp_potion) {
                saku->emas -= Item->hp_potion;
                tambah_ke_inventory(saku, "HP Potion");
                printf("Kamu telah membeli HP Potion\n");
            } else {
                printf("Emas tidak cukup!\n");
            }
            break;
        case 2:
            if (saku->emas >= Item->mp_potion) {
                saku->emas -= Item->mp_potion;
                tambah_ke_inventory(saku, "MP Potion");
                printf("Kamu telah membeli MP Potion\n");
            } else {
                printf("Emas tidak cukup!\n");
            }
            break;
        case 3:
            if (saku->emas >= Item->str_up) {
                saku->emas -= Item->str_up;
                tambah_ke_inventory(saku, "str_up");
                printf("Kamu telah membeli str_up\n");
            } else {
                printf("Emas tidak cukup!\n");
            }
            break;
        case 4:
            if (saku->emas >= Item->def_up) {
                saku->emas -= Item->def_up;
                tambah_ke_inventory(saku, "def_up");
                printf("Kamu telah membeli def_up\n");
            } else {
                printf("Emas tidak cukup!\n");
            }
            break;
        case 9:
            printf("Kembali\n");
            break;
        default:
            printf("Masukkan input yang valid\n");
    }
}

void pilih_kostum(struct penyimpanan *saku, struct kostum *Kostum) {
    printf("Kostum apa yang ingin Anda beli?\n");
    printf("1. Zirah\tharga: %d emas\n", Kostum->zirah);
    printf("2. Zirah II\tharga: %d emas\n", Kostum->zirah_II);
    printf("3. Jubah\tharga: %d emas\n", Kostum->jubah);
    printf("9. Kembali\n");

    int pilihan_kostum;
    printf("-> ");
    scanf("%d", &pilihan_kostum);
    fflush(stdin);

    switch (pilihan_kostum) {
        case 1:
            if (saku->emas >= Kostum->zirah) {
                saku->emas -= Kostum->zirah;
                tambah_ke_inventory(saku, "Zirah");
                printf("Kamu telah membeli ZIRAH\n");
            } else {
                printf("Emas tidak cukup!\n");
            }
            break;
        case 2:
            if (saku->emas >= Kostum->zirah_II) {
                saku->emas -= Kostum->zirah_II;
                tambah_ke_inventory(saku, "Zirah II");
                printf("Kamu telah membeli ZIRAH II\n");
            } else {
                printf("Emas tidak cukup!\n");
            }
            break;
        case 3:
            if (saku->emas >= Kostum->jubah) {
                saku->emas -= Kostum->jubah;
                tambah_ke_inventory(saku, "Jubah");
                printf("Kamu telah membeli JUBAH\n");
            } else {
                printf("Emas tidak cukup!\n");
            }
            break;
        case 9:
            printf("Kembali\n");
            break;
        default:
            printf("Masukkan input yang valid\n");
    }
}


void gacha(struct penyimpanan *saku) {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random number
    int angka_random = rand() % 1000 + 1;  // Random number between 1 and 1000

    printf("Angka random: %d\n", angka_random);

    printf("Gacha?\n");
    printf("1. Low Risk Gacha\n");
    printf("2. High Risk Gacha\n");
    printf("3. Info\n");
    printf("9. Kembali\n");

    int pilihan_gacha;
    scanf("%d", &pilihan_gacha);
    fflush(stdin);

    switch (pilihan_gacha) {
        case 1:
            if (saku->emas < 10) {
                printf("Tidak cukup emas!\n");
                break;
            }
            printf("Rolling the dice...\n");

            //  Menambahkan emas ke inventory player
            if (angka_random >= 1 && angka_random <= 500) {
                printf("Bad luck! -10 emas.\n");
                saku->emas -= 10;
            } else if (angka_random >= 501 && angka_random <= 900) {
                printf("+20 emas!\n");
                saku->emas += 20;
            } else {
                printf("Jackpot! You won 40 emas!\n");
                saku->emas += 40;
            }
            break;

        case 2:
            if (saku->emas < 40) {
                printf("Tidak cukup emas!\n");
                break;
            }
            printf("Hahahaha! Rolling the dice...\n");

            //  Menambahkan emas ke inventory player
            if (angka_random >= 1 && angka_random <= 500) {
                printf("Bad luck! -40 emas.\n");
                saku->emas -= 40;
            } else if (angka_random >= 501 && angka_random <= 900) {
                printf("+40 emas!\n");
                saku->emas += 40;
            } else {
                printf("Jackpot! You won 100 emas!\n");
                saku->emas += 100;
            }
            break;

        case 3:
            printf("Informasi mengenai kemungkinan gacha\n");
            printf("1. Low Risk Gacha, biaya: 10 emas, hadiah: 10-40 emas\n");
            printf("2. High Risk Gacha, biaya: 40 emas, hadiah: 40-100 emas\n");
            break;

        case 9:
            printf("Kembali\n");
            break;

        default:
            printf("Masukkan input yang valid\n");
            break;
    }
}

void tampilkan_inventory(struct penyimpanan *saku) {
    printf("Inventory:\n");
    printf("%d emas\n", saku->emas);
    for (int i = 0; i < INVENTORY_SIZE; ++i) {
        if (strlen(saku->inventory[i]) > 0) {
            printf("%d. %s\n", i + 1, saku->inventory[i]);
        }
    }
}

int main(){	
	int pilihan_menu_utama;

	while (pilihan_menu_utama != 9) {		
		printf("\n- Main Menu -\n");
		printf("1. Senjata\n");
		printf("2. Item\n");
		printf("3. Kostum\n");
		printf("4. Gacha\n");
		printf("5. Inventory\n");
		printf("9. Keluar\n");
		
		printf("-> ");
		scanf("%d", &pilihan_menu_utama);
		fflush(stdin);
		
		switch (pilihan_menu_utama) {
			case 1:
				pilih_senjata(&saku, &Senjata);
				break;
			case 2:
				pilih_item(&saku, &Item);
				break;
			case 3:
				pilih_kostum(&saku, &Kostum);
				break;
			case 4:
				gacha(&saku);
				break;
			case 5:				
				tampilkan_inventory(&saku);
				break;
			case 9:				
				return 0;
			default:
				printf("Looking forward to the Weekend\n");		
		}
	}
	
	return 0;
}
