// Created by Syahid Nurhidayatullah (23343056)
//  Ide saat ini adalah untuk membuat toserba game RPG
//  Hmm, kalau uangnya habis gimana? kutambahlah sistem GACHA!
//  Eh, kalau kalah gacha gimana? gacha kan perlu uang juga...
//  Yodahlah tambah musuh untuk dilawan:)
//  Kok jadi game turn based RPG wkwk

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define INVENTORY_SIZE 10
#define DARAH_MAX 100

// Ini struct Player
struct penyimpanan {
    int emas;
    char inventory[INVENTORY_SIZE][39];
    int darah;
} Player = {100, {}, 100};

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
} Item = {4, 3};

struct musuh {
    char nama[20];
    int darah;
    int damage;
    int hadiah;
} Enemy;

void damage_senjata(struct senjata *Senjata) {
	int random_damage = rand() % 1000 + 1;  // Random number between 1 and 1000
}

void init_enemy(struct musuh *enemy) {    
    // Generate a random number
    int musuh_random = rand() % 1000 + 1;  // Random number between 1 and 1000

    printf("Angka random: %d\n", musuh_random);

    //  Menambahkan emas ke inventory Player
    if (musuh_random >= 1 && musuh_random <= 500) {
        strcpy(enemy->nama, "Goblin");
	    enemy->darah = 70;
	    enemy->damage = 18;
	    enemy->hadiah = 20;
    }
	else if (musuh_random >= 501 && musuh_random <= 900) {
	    strcpy(enemy->nama, "Slime");
	    enemy->darah = 50;
	    enemy->damage = 10;
	    enemy->hadiah = 10;	    
    }
	else {
	    strcpy(enemy->nama, "Golem");
	    enemy->darah = 100;
	    enemy->damage = 25;
	    enemy->hadiah = 50;
	}
}

//  Fungsi untuk menambahkan item ke inventory
void tambah_ke_inventory(struct penyimpanan *Player, const char *item_name) {
    for (int i = 0; i < INVENTORY_SIZE; ++i) {
        if (strlen(Player->inventory[i]) == 0) {
            strcpy(Player->inventory[i], item_name);
            break;
        }
    }
}

//  Nyerang musuh biar gk ngegacha terus:)
void serang_musuh(struct penyimpanan *Player, struct senjata *sen, struct musuh *enemy) {
    bool in_battle = true;

	printf("\n\tMenemukan %s! darah: %d\n", enemy->nama, enemy->darah);

    while (in_battle) {
    	
        printf("\n-- Battle Menu --\n");
        printf("1. Attack\n");
        printf("2. Use Item\n");
        printf("3. Run Away\n");

        int battle_choice;
        printf("-> ");
        scanf("%d", &battle_choice);
        fflush(stdin);

        switch (battle_choice) {
            case 1: {
                printf("Pilih senjata untuk menyerang musuh:\n");
                for (int i = 0; i < INVENTORY_SIZE; ++i) {
                    if (strlen(Player->inventory[i]) > 0) {
                        printf("%d. %s\n", i + 1, Player->inventory[i]);
                    }
                }

                int weapon_choice;
                printf("-> ");
                scanf("%d", &weapon_choice);
                fflush(stdin);

                if (weapon_choice >= 1 && weapon_choice <= INVENTORY_SIZE && strlen(Player->inventory[weapon_choice - 1]) > 0) {
                    const char *selected_weapon = Player->inventory[weapon_choice - 1];
                    int damage = 0;

                    if (strcmp(selected_weapon, "Pedang") == 0) {
                        damage = sen->pedang;
                    } 
					else if (strcmp(selected_weapon, "Busur") == 0) {
                        damage = sen->busur;
                    } 
					else if (strcmp(selected_weapon, "Tombak") == 0) {
                        damage = sen->tombak;
                    } 
					else if (strcmp(selected_weapon, "Tongkat") == 0) {
                        damage = sen->tongkat;
                    }
					else {
	                    printf("Pilihan item tidak valid!\n");
	                }

                    printf("\tAnda menyerang %s dengan %s dan menyebabkan %d damage!\n", enemy->nama, selected_weapon, damage);
                    enemy->darah -= damage;
                    printf("\tdarah Anda: %d | darah %s: %d\n\n", Player->darah, enemy->nama, enemy->darah);

                    if (enemy->darah > 0) {
                        printf("\t%s menyerang Anda dan menyebabkan %d damage!\n", enemy->nama, enemy->damage);
                        Player->darah -= enemy->damage;
                        printf("\tdarah Anda: %d | darah %s: %d\n", Player->darah, enemy->nama, enemy->darah);

                        if (Player->darah <= 0) {
                            printf("\n\n\t!! Anda kalah dalam pertarungan !!\n");
                            printf("\n\n\tCredit: Made by Sha\n");
                            printf("\n\n\n\tThanks for playing!\n");
                            exit(0);
                        }
                    } else {
                        printf("\tAnda berhasil mengalahkan %s!\n", enemy->nama);
                        printf("\t+%d emas\n", enemy->hadiah);
                        Player->emas += enemy->hadiah; // hadiah emas ditambahkan ke emas player
                        in_battle = false; // Keluar dari loop pertempuran
                    }
                } else {
                    printf("Pilihan senjata tidak valid!\n");
                }
                break;
            }
            case 2: {
                printf("Pilih item untuk digunakan:\n");
                for (int i = 0; i < INVENTORY_SIZE; ++i) {
                    if (strlen(Player->inventory[i]) > 0) {
                        printf("%d. %s\n", i + 1, Player->inventory[i]);
                    }
                }

                int item_choice;
                printf("-> ");
                scanf("%d", &item_choice);
                fflush(stdin);
                int Pakai_hp_potion = 0;

                if (item_choice >= 1 && item_choice <= INVENTORY_SIZE && strlen(Player->inventory[item_choice - 1]) > 0) {
                    if (strcmp(Player->inventory[item_choice - 1], "HP Potion") == 0) {
                        // Handle HP Potion
                        if (DARAH_MAX == Player->darah) {
                        	printf("Darahmu sudah penuh!\n");
						}
                        else if (DARAH_MAX - Player->darah < 20) {
                        	Pakai_hp_potion = DARAH_MAX - Player->darah;
                        	Player->darah += Pakai_hp_potion;
	                        printf("Anda menggunakan HP Potion dan mendapatkan %d HP!\n", Pakai_hp_potion);
						}
						else {
							Player->darah += 20;
	                        printf("Anda menggunakan HP Potion dan mendapatkan 20 HP!\n");
						}

                        printf("darah Anda: %d | darah %s: %d\n", Player->darah, enemy->nama, enemy->darah);
                    }
					else if (strcmp(Player->inventory[item_choice - 1], "MP Potion") == 0) {
                        // Handle MP Potion
                        printf("Anda tidak bisa menggunakan MP Potion saat menyerang!\n");
                    }
                    else {
                    	printf("Item tidak bisa digunakan!\n");
					}
                } 
				else {
                    printf("Pilihan item tidak valid!\n");
                }
                break;
            }
            case 3:
                printf("Anda melarikan diri dari pertarungan!\n");
                in_battle = false; // Exit the battle loop
                break;
            default:
                printf("Masukkan input yang valid\n");
        }
    }
}


void pilih_senjata(struct penyimpanan *Player, struct senjata *sen) {
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
            if (Player->emas >= sen->pedang) {
                Player->emas -= sen->pedang;
                tambah_ke_inventory(Player, "Pedang");
                printf("Kamu telah membeli sebuah PEDANG\n");
            } else {
                printf("Emas tidak cukup!\n");
            }
            break;
        case 2:
            if (Player->emas >= sen->busur) {
                Player->emas -= sen->busur;
                tambah_ke_inventory(Player, "Busur");
                printf("Kamu telah membeli sebuah BUSUR\n");
            } else {
                printf("Emas tidak cukup!\n");
            }
            break;
        case 3:
            if (Player->emas >= sen->tombak) {
                Player->emas -= sen->tombak;
                tambah_ke_inventory(Player, "Tombak");
                printf("Kamu telah membeli sebuah TOMBAK\n");
            } else {
                printf("Emas tidak cukup!\n");
            }
            break;
        case 4:
            if (Player->emas >= sen->tongkat) {
                Player->emas -= sen->tongkat;
                tambah_ke_inventory(Player, "Tongkat");
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

void pilih_item(struct penyimpanan *Player, struct item *Item) {
    printf("Item apa yang ingin Anda beli?\n");
    printf("1. HP Potion\tharga: %d emas\n", Item->hp_potion);
    printf("2. MP Potion\tharga: %d emas\n", Item->mp_potion);
    printf("9. Kembali\n");

    int pilihan_item;
    printf("-> ");
    scanf("%d", &pilihan_item);
    fflush(stdin);

    switch (pilihan_item) {
        case 1:
            if (Player->emas >= Item->hp_potion) {
                Player->emas -= Item->hp_potion;
                tambah_ke_inventory(Player, "HP Potion");
                printf("Kamu telah membeli HP Potion\n");
            } else {
                printf("Emas tidak cukup!\n");
            }
            break;
        case 2:
            if (Player->emas >= Item->mp_potion) {
                Player->emas -= Item->mp_potion;
                tambah_ke_inventory(Player, "MP Potion");
                printf("Kamu telah membeli MP Potion\n");
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

void gacha(struct penyimpanan *Player) {
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
            if (Player->emas < 10) {
                printf("Tidak cukup emas!\n");
                break;
            }
            printf("Rolling the dice...\n");

            //  Menambahkan emas ke inventory Player
            if (angka_random >= 1 && angka_random <= 500) {
                printf("Bad luck! -10 emas.\n");
                Player->emas -= 10;
            } else if (angka_random >= 501 && angka_random <= 900) {
                printf("+20 emas!\n");
                Player->emas += 20;
            } else {
                printf("Jackpot! You won 40 emas!\n");
                Player->emas += 40;
            }
            break;

        case 2:
            if (Player->emas < 40) {
                printf("Tidak cukup emas!\n");
                break;
            }
            printf("Hahahaha! Rolling the dice...\n");

            //  Menambahkan emas ke inventory Player
            if (angka_random >= 1 && angka_random <= 500) {
                printf("Bad luck! -40 emas.\n");
                Player->emas -= 40;
            } else if (angka_random >= 501 && angka_random <= 900) {
                printf("+40 emas!\n");
                Player->emas += 40;
            } else {
                printf("Jackpot! You won 100 emas!\n");
                Player->emas += 100;
            }
            break;

        case 3:
            printf("Informasi mengenai kemungkinan gacha\n");
            printf("1. Low Risk Gacha, biaya: 10 emas, hadiah: 0-40 emas\n");
            printf("2. High Risk Gacha, biaya: 40 emas, hadiah: 0-100 emas\n");
            break;

        case 9:
            printf("Kembali\n");
            break;

        default:
            printf("Masukkan input yang valid\n");
            break;
    }
}

void tampilkan_inventory(struct penyimpanan *Player) {
    printf("Inventory:\n");
    printf("darah: %d\n", Player->darah);
    printf("%d emas\n", Player->emas);
    for (int i = 0; i < INVENTORY_SIZE; ++i) {
        if (strlen(Player->inventory[i]) > 0) {
            printf("%d. %s\n", i + 1, Player->inventory[i]);
        }
    }
}

int main() {
    int pilihan_menu_utama;
	
    while (pilihan_menu_utama != 9) {
        printf("\n- Main Menu -\n");
        printf("1. Senjata\n");
        printf("2. Item\n");
        printf("3. Gacha\n");
        printf("4. Serang Musuh\n");
        printf("5. Inventory\n");
        printf("9. Keluar\n");

        printf("-> ");
        scanf("%d", &pilihan_menu_utama);
        fflush(stdin);

        switch (pilihan_menu_utama) {
            case 1:
                pilih_senjata(&Player, &Senjata);
                break;
            case 2:
                pilih_item(&Player, &Item);
                break;
            case 3:
                gacha(&Player);
                break;
            case 4:
            	init_enemy(&Enemy); // Menambahkan musuh baru
                serang_musuh(&Player, &Senjata, &Enemy);
                break;
            case 5:
                tampilkan_inventory(&Player);
                break;
            case 9:
                return 0;
            default:
                printf("Masukkan input yang valid\n");
        }
    }

    return 0;
}
