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
#define HP_MAX 100
#define MP_MAX 20

// Ini struct Player
struct penyimpanan {
    int emas;
    char inventory[INVENTORY_SIZE][39];
    int HP;
    int MP;
    char equip[39];
} Player = {25, {}, 100, 20};

// Struct senjata-senjata yang tersedia
struct senjata { // Ada senjata pedang, busur, tombak, dan tongkat.
    int harga_pedang;
    int damage_pedang;
    int harga_busur;
    int damage_busur;
    int harga_tombak;
    int damage_tombak;
    int harga_tongkat;
    int damage_tongkat;
    int mp_tongkat;
} Senjata = {20, 8, 20, 8, 40, 10, 50, 18, 2};

struct item { // Ada item HP potion sama MP potion di game ini
    int harga_hp_potion;
    int harga_mp_potion;
} Item = {9, 5};

// Ini struct musuh, nanti diisi random data-data struct ini di fungsi init_enemy
struct musuh {
    char nama[20];
    int HP;
    int damage;
    int hadiah;
} Enemy;

//  Nambah musuh baru secara random
void init_enemy(struct musuh *enemy) {
    //  Generate a random number
    int musuh_random = rand() % 1000 + 1;  // Random number 1 - 1000

    printf("Angka random: %d\n", musuh_random);

    //  Menambahkan emas ke inventory Player
    if (musuh_random >= 1 && musuh_random <= 500) {
        strcpy(enemy->nama, "Goblin");
	    enemy->HP = 70;
	    enemy->damage = 10;
	    enemy->hadiah = 10;
    }
	else if (musuh_random >= 501 && musuh_random <= 900) {
	    strcpy(enemy->nama, "Slime");
	    enemy->HP = 50;
	    enemy->damage = 6;
	    enemy->hadiah = 5;	    
    }
	else {
	    strcpy(enemy->nama, "Golem");
	    enemy->HP = 100;
	    enemy->damage = 22;
	    enemy->hadiah = 25;
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

int damage_senjata(struct senjata *Senjata) {
    int base_damage = 0;
    int random_factor = rand() % 11 - 5; // Random number between -5 and 5

    if (strcmp(Player.equip, "Pedang") == 0) {
        base_damage = Senjata->damage_pedang;
    } else if (strcmp(Player.equip, "Busur") == 0) {
        base_damage = Senjata->damage_busur;
    } else if (strcmp(Player.equip, "Tombak") == 0) {
        base_damage = Senjata->damage_tombak;
    } else if (strcmp(Player.equip, "Tongkat") == 0) {
        base_damage = Senjata->damage_tongkat;
        if (Player.MP > 0) {
            Player.MP -= Senjata->mp_tongkat;
        } else {
            printf("Mana tidak cukup!!\n");
            return 0; // Return 0 damage if not enough mana
        }
    } else {
        base_damage = 2; // Base damage for the default case (Tinju)
    }

    int total_damage = base_damage + random_factor;
    if (total_damage < 0) {
        total_damage = 0; // Ensure damage is non-negative
    }

    return total_damage;
}
int damage_musuh(struct musuh *enemy) {
    int base_damage = enemy->damage;
    int random_factor = rand() % 11 - 5; // Random number between -5 and 5

    int total_damage = base_damage + random_factor;
    if (total_damage < 0) {
        total_damage = 0; // Ensure damage is non-negative
    }

    return total_damage;
}


//  Nyerang musuh biar gak gacha terus:)
void bertualang(struct penyimpanan *Player, struct senjata *sen, struct musuh *enemy) {
    bool in_battle = true;

    printf("\n\tMenemukan %s! HP: %d\n", enemy->nama, enemy->HP);

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
            case 1:
                {
                    int damage_player = damage_senjata(sen);
                    int damage_enemy = damage_musuh(enemy);

                    printf("\tAnda menyerang %s dengan %s dan menyebabkan %d damage!\n", enemy->nama, Player->equip, damage_player);
                    enemy->HP -= damage_player;
                    printf("\tHP Anda: %d | HP %s: %d\n\n", Player->HP, enemy->nama, enemy->HP);

                    if (enemy->HP > 0) {
                        printf("\t%s menyerang Anda dan menyebabkan %d damage!\n", enemy->nama, damage_enemy);
                        Player->HP -= damage_enemy;
                        printf("\tHP Anda: %d | HP %s: %d\n", Player->HP, enemy->nama, enemy->HP);

                        if (Player->HP <= 0) {
                            printf("\n\n\t!! Anda kalah dalam pertarungan !!\n");
                            printf("\n\n\tCredit: Made by Sha\n");
                            printf("\n\n\n\tThanks for playing!\n");
                            exit(0);
                        }
                    } 
                    else {
                        printf("\tAnda berhasil mengalahkan %s!\n", enemy->nama);
                        printf("\t+%d emas\n", enemy->hadiah);
                        Player->emas += enemy->hadiah; // hadiah emas ditambahkan ke emas player
                        in_battle = false; // Keluar dari loop pertempuran
                    }
                } 
                break;

            case 2:
                {
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
                    int Pakai_mp_potion = 0;

                    if (item_choice >= 1 && item_choice <= INVENTORY_SIZE && strlen(Player->inventory[item_choice - 1]) > 0) {
                        if (strcmp(Player->inventory[item_choice - 1], "HP Potion") == 0) {
                            // Menghandle HP Potion
                            if (HP_MAX == Player->HP) {
                                printf("HPmu sudah penuh!\n");
                            }
                            else if (HP_MAX - Player->HP < 20) {
                                Pakai_hp_potion = HP_MAX - Player->HP;
                                Player->HP += Pakai_hp_potion;
                                printf("Anda menggunakan HP Potion dan mendapatkan %d HP!\n", Pakai_hp_potion);
                            }
                            else {
                                Player->HP += 20;
                                printf("Anda menggunakan HP Potion dan mendapatkan 20 HP!\n");
                            }

                            printf("HP Anda: %d\n", Player->HP);
                        }
                        else if (strcmp(Player->inventory[item_choice - 1], "MP Potion") == 0) {
                            // Menghandle MP Potion
                            if (MP_MAX == Player->MP) {
                                printf("MPmu sudah penuh!\n");
                            }
                            else if (MP_MAX - Player->MP < 5) {
                                Pakai_mp_potion = MP_MAX - Player->MP;
                                Player->MP += Pakai_mp_potion;
                                printf("Anda menggunakan MP Potion dan mendapatkan %d MP!\n", Pakai_mp_potion);
                            }
                            else {
                                Player->MP += 5;
                                printf("Anda menggunakan MP Potion dan mendapatkan 20 MP!\n");
                            }

                            printf("MP Anda: %d\n", Player->MP);
                        }
                        else {
                            printf("Item tidak bisa digunakan!\n");
                        }
                    }
                    else {
                        printf("Pilihan item tidak valid!\n");
                    }
                } 
                break;

            case 3:
                printf("Anda melarikan diri dari pertarungan!\n");
                in_battle = false; // Exit the battle loop
                break;

            default:
                printf("Masukkan input yang valid\n");
        }
    }
}

//  Nih beli senjata disini
void beli_senjata(struct penyimpanan *Player, struct senjata *sen) {

	if (strlen(Player->equip) != 0) {
		printf("Anda sudah mempunyai %s!\n", Player->equip);
		return;
	}

    printf("Senjata apa yang ingin Anda beli?\n");
    printf("1. Pedang\tharga: %d emas\n", sen->harga_pedang);
    printf("2. Busur\tharga: %d emas\n", sen->harga_busur);
    printf("3. Tombak\tharga: %d emas\n", sen->harga_tombak);
    printf("4. Tongkat\tharga: %d emas\n", sen->harga_tongkat);
    printf("9. Kembali\n");

    int pilihan_senjata;
    printf("-> ");
    scanf("%d", &pilihan_senjata);
    fflush(stdin);

    switch (pilihan_senjata) {
        case 1:
            if (Player->emas >= sen->harga_pedang) {
                Player->emas -= sen->harga_pedang;
                strcpy(Player->equip, "Pedang");
                printf("Kamu telah membeli sebuah PEDANG\n");
            } else {
                printf("Emas tidak cukup!\n");
            }
            break;
        case 2:
            if (Player->emas >= sen->harga_busur) {
                Player->emas -= sen->harga_busur;
                strcpy(Player->equip, "Busur");
                printf("Kamu telah membeli sebuah BUSUR\n");
            } else {
                printf("Emas tidak cukup!\n");
            }
            break;
        case 3:
            if (Player->emas >= sen->harga_tombak) {
                Player->emas -= sen->harga_tombak;
                strcpy(Player->equip, "Tombak");
                printf("Kamu telah membeli sebuah TOMBAK\n");
            } else {
                printf("Emas tidak cukup!\n");
            }
            break;
        case 4:
            if (Player->emas >= sen->harga_tongkat) {
                Player->emas -= sen->harga_tongkat;
                strcpy(Player->equip, "Tongkat");
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

//  Nih beli item disini
void beli_item(struct penyimpanan *Player, struct item *Item) {
    printf("Item apa yang ingin Anda beli?\n");
    printf("1. HP Potion\tharga: %d emas\n", Item->harga_hp_potion);
    printf("2. MP Potion\tharga: %d emas\n", Item->harga_mp_potion);
    printf("9. Kembali\n");

    int pilihan_item;
    printf("-> ");
    scanf("%d", &pilihan_item);
    fflush(stdin);

    switch (pilihan_item) {
        case 1:
            if (Player->emas >= Item->harga_hp_potion) {
                Player->emas -= Item->harga_hp_potion;
                tambah_ke_inventory(Player, "HP Potion");
                printf("Kamu telah membeli HP Potion\n");
            } 
            else {
                printf("Emas tidak cukup!\n");
            }
            break;
        case 2:
            if (Player->emas >= Item->harga_mp_potion) {
                Player->emas -= Item->harga_mp_potion;
                tambah_ke_inventory(Player, "MP Potion");
                printf("Kamu telah membeli MP Potion\n");
            } 
            else {
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

//  First interesting feature;)
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

//  Ini persediaan player
void tampilkan_persediaan(struct penyimpanan *Player) {
    printf("\n> Inventaris <\n");
	printf("Senjata: %s\n", Player->equip);
    printf("HP: %d\n", Player->HP);
    printf("MP: %d\n", Player->MP);
    printf("%d emas\n", Player->emas);
    for (int i = 0; i < INVENTORY_SIZE; ++i) {
        if (strlen(Player->inventory[i]) > 0) {
            printf("%d. %s\n", i + 1, Player->inventory[i]);
        }
    }

    int pilihan_inventaris;
    printf("\n(Tekan 1 untuk melepas senjata)\n(Press any button to continue)\n");
    printf("-> ");
    scanf("%d", &pilihan_inventaris);
    fflush(stdin);

    switch (pilihan_inventaris) {
        case 1:
            strcpy(Player->equip, ""); // Remove the equipped weapon
            printf("Kamu melepas senjata\n");
            break;
        default:
            printf("Kembali\n");
    }
}

int main() {
    int pilihan_menu_utama;
	
    while (pilihan_menu_utama != 9) {
        printf("\n- Main Menu -\n");
        printf("1. Beli Senjata\n");
        printf("2. Beli Item\n");
        printf("3. Gacha\n");
        printf("4. Bertualang\n");
        printf("5. Inventaris\n");
        printf("9. Keluar\n");

        printf("-> ");
        scanf("%d", &pilihan_menu_utama);
        fflush(stdin);

        switch (pilihan_menu_utama) {
            case 1:
                beli_senjata(&Player, &Senjata);
                break;
            case 2:
                beli_item(&Player, &Item);
                break;
            case 3:
                gacha(&Player);
                break;
            case 4:
            	init_enemy(&Enemy); // Menambahkan musuh baru
                bertualang(&Player, &Senjata, &Enemy);
                break;
            case 5:
                tampilkan_persediaan(&Player);
                break;
            case 9:
                return 0;
            default:
                printf("Masukkan input yang valid\n");
        }
    }

    return 0;
}
