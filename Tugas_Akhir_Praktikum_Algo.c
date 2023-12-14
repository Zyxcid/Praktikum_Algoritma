// Created by Syahid Nurhidayatullah (23343056)

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
    char persediaan[INVENTORY_SIZE][39];
    int HP;
    int MP;
    char equip[39];
} Player = {25, {}, 100, 20};

// Struct senjata-senjata yang tersedia
struct senjata {
    // Pedang
    int harga_pedang;
    int damage_pedang;
    // Busur
    int harga_busur;
    int damage_busur;
    // Tombak
    int harga_tombak;
    int damage_tombak;
    // Tongkat
    int harga_tongkat;
    int damage_tongkat;
    int mp_tongkat;
} Senjata = {20, 10, 20, 10, 40, 15, 50, 22, 2};

struct item { // Ada item HP-potion sama MP-potion di game ini
    int harga_hp_potion;
    int harga_mp_potion;
} Item = {3, 2};

// Ini struct musuh, nanti diisi random data-data struct ini di fungsi init_enemy
struct musuh {
    char nama[20];
    int HP;
    int damage;
    int hadiah;
} Musuh;

//  Nambah musuh baru secara random
void init_enemy(struct musuh *musuh) {
    int musuh_random = rand() % 1000 + 1;  // Angka random 1 - 1000

    //  Memasukkan data musuh dari sini ke dalam struct musuh tadi
    if (musuh_random >= 1 && musuh_random <= 200) {
        strcpy(musuh->nama, "Goblin");
	    musuh->HP = 60;
	    musuh->damage = 10;
	    musuh->hadiah = 10;
    }
	else if (musuh_random >= 201 && musuh_random <= 400) {
	    strcpy(musuh->nama, "Slime");
	    musuh->HP = 30;
	    musuh->damage = 6;
	    musuh->hadiah = 8;	    
    }
	else if (musuh_random >= 401 && musuh_random <= 600) {
	    strcpy(musuh->nama, "Undead");
	    musuh->HP = 55;
	    musuh->damage = 10;
	    musuh->hadiah = 10;	    
    }
	else if (musuh_random >= 601 && musuh_random <= 800) {
	    strcpy(musuh->nama, "Skeleton");
	    musuh->HP = 50;
	    musuh->damage = 9;
	    musuh->hadiah = 10;	    
    }
	else if (musuh_random >= 801 && musuh_random <= 950) {
	    strcpy(musuh->nama, "Golem");
	    musuh->HP = 125;
	    musuh->damage = 18;
	    musuh->hadiah = 30;
    }
    else {
	    strcpy(musuh->nama, "Mimic");
	    musuh->HP = 50;
	    musuh->damage = 15;
	    musuh->hadiah = 50;	    
	}
}

//  Fungsi untuk menambahkan item ke persediaan
void tambah_ke_persediaan(struct penyimpanan *Player, const char *item_name) {
    for (int i = 0; i < INVENTORY_SIZE; ++i) {
        if (strlen(Player->persediaan[i]) == 0) {
            strcpy(Player->persediaan[i], item_name);
            break;
        }
    }
}

int hitung_damage_senjata(struct senjata *Senjata) {
    int damage_dasar = 0;
    int angka_random = rand() % 4 - 1; // Angka random -1 sampai 2

    // Damage dasar menyesuaikan dengan pilihan senjata player
    if (strcmp(Player.equip, "Pedang") == 0) {
        damage_dasar = Senjata->damage_pedang;
    } 
    else if (strcmp(Player.equip, "Busur") == 0) {
        damage_dasar = Senjata->damage_busur;
    } 
    else if (strcmp(Player.equip, "Tombak") == 0) {
        damage_dasar = Senjata->damage_tombak;
    } 
    else if (strcmp(Player.equip, "Tongkat") == 0) {
        damage_dasar = Senjata->damage_tongkat;
        if (Player.MP > 0) {
            printf("\tMenggunakan %d mana\n", Senjata->mp_tongkat);
            Player.MP -= Senjata->mp_tongkat;
        } else {
            printf("Mana tidak cukup!!\n");
            return 0;
        }
    } 
    else {
        strcpy(Player.equip, "Tinju");
        damage_dasar = 2; // Base damage Tinju
    }

    //  Nah ini rumus total damagenya biar seru pakai angka random, lagi lagi
    int total_damage = damage_dasar + angka_random;
    if (total_damage < 0) {
        total_damage = 0; // Biar damage nya non-negative
    }

    return total_damage;
}
int hitung_damage_musuh(struct musuh *musuh) {
    int damage_dasar = musuh->damage;
    int angka_random = rand() % 4 - 1; // Angka random -1 sampai 2

    int total_damage = damage_dasar + angka_random;
    if (total_damage < 0) {
        total_damage = 0;
    }

    return total_damage;
}


//  Nyerang musuh biar gak gacha terus:)
void bertualang(struct penyimpanan *Player, struct senjata *sen, struct musuh *musuh) {
    bool dalam_pertempuran = true;
    printf("\n\tMenemukan %s! HP: %d\n", musuh->nama, musuh->HP);

    while (dalam_pertempuran) {
        printf("\n-- Battle Menu --\n");
        printf("HP: %d MP: %d\n", Player->HP, Player->MP);
        printf("1. Serang\n");
        printf("2. Pakai Item\n");
        printf("3. Kabur\n");

        int battle_choice;
        printf("-> ");
        scanf("%d", &battle_choice);
        fflush(stdin);

        int damage_player = hitung_damage_senjata(sen);
        int damage_musuh = hitung_damage_musuh(musuh);
        
        switch (battle_choice) {
            //  Serang
            case 1:
                {
                    printf("\tKamu menyerang %s dengan %s dan menyebabkan %d damage!\n", musuh->nama, Player->equip, damage_player);
                    musuh->HP -= damage_player;

                    if (musuh->HP > 0) {
                        printf("\t%s menyerang Kamu dan menyebabkan %d damage!\n", musuh->nama, damage_musuh);
                        Player->HP -= damage_musuh;
 
                        if (Player->HP <= 0) {
                            printf("\n\n\t!! Kamu kalah dalam pertarungan !!\n");
                            printf("\n\n\tCredit: Made by Sha\n");
                            printf("\n\n\n\tThanks for playing!\n");
                            exit(0);
                        }
                    } 
                    else {
                        printf("\tKamu berhasil mengalahkan %s!\n", musuh->nama);
                        printf("\t+%d emas\n", musuh->hadiah);
                        Player->emas += musuh->hadiah; // hadiah emas ditambahkan ke emas player
                        dalam_pertempuran = false;
                    }
                } 
                break;

            //  Pakai Item
            case 2:
                {
                    int barang = 0;
                    printf("Item mu:\n");
                    for (int i = 0; i < INVENTORY_SIZE; ++i) {
                        if (strlen(Player->persediaan[i]) > 0) {
                            printf("%d. %s\n", i + 1, Player->persediaan[i]);
                            barang++;
                        }
                    }
                    if (barang == 0)
                    {
                        printf("Kosong\n");
                        break;
                    }
                    
                    printf("Pilih item untuk digunakan\n");
                    int item_choice;
                    printf("-> ");
                    scanf("%d", &item_choice);
                    fflush(stdin);

                    int Pakai_hp_potion = 0;
                    int Pakai_mp_potion = 0;

                    if (item_choice >= 1 && item_choice <= INVENTORY_SIZE && strlen(Player->persediaan[item_choice - 1]) > 0) {
                        if (strcmp(Player->persediaan[item_choice - 1], "HP-Potion") == 0) {
                            // Menghandle HP-Potion
                            if (HP_MAX == Player->HP) {
                                printf("Kamu menggunakan HP-potion walapun HPmu sudah penuh!\n");
                            }
                            else if (HP_MAX - Player->HP < 20) {
                                Pakai_hp_potion = HP_MAX - Player->HP;
                                Player->HP += Pakai_hp_potion;
                                printf("Kamu menggunakan HP-Potion dan mendapatkan %d HP!\n", Pakai_hp_potion);
                            }
                            else {
                                Player->HP += 20;
                                printf("Kamu menggunakan HP-Potion dan mendapatkan 20 HP!\n");
                            }

                            printf("HPmu: %d\n", Player->HP);
                            strcpy(Player->persediaan[item_choice - 1], ""); // Menghapus item dari persediaan setelah dipakai
                        }
                        else if (strcmp(Player->persediaan[item_choice - 1], "MP-Potion") == 0) {
                            // Menghandle MP-Potion
                            if (MP_MAX == Player->MP) {
                                printf("MPmu sudah penuh!\n");
                            }
                            else if (MP_MAX - Player->MP < 5) {
                                Pakai_mp_potion = MP_MAX - Player->MP;
                                Player->MP += Pakai_mp_potion;
                                printf("Kamu menggunakan MP-Potion dan mendapatkan %d MP!\n", Pakai_mp_potion);
                            }
                            else {
                                Player->MP += 5;
                                printf("Kamu menggunakan MP-Potion dan mendapatkan 20 MP!\n");
                            }

                            printf("MP Kamu: %d\n", Player->MP);
                            strcpy(Player->persediaan[item_choice - 1], ""); // Menghapus item dari persediaan setelah dipakai
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

            // Larii
            case 3:
                //  Angka random lagi. sekarang ku baru sadar.. ternyata hidup ini penuh gacha
                int angka_random = rand() % 100 + 1;  // Angka random 1 - 1000

                if (angka_random >= 1 && angka_random <= 40) {
                    printf("\tKamu melarikan diri dari pertarungan!\n");
                    dalam_pertempuran = false; // Keluar dari loop
                }
                else if (angka_random >= 41 && angka_random <= 50) {
                    printf("\tEntah bagaimana ada petir menyambar %s!\n", musuh->nama);
                    printf("\t+%d emas\n", musuh->hadiah + 2);
                    Player->emas += musuh->hadiah + 2;
                    dalam_pertempuran = false;
                }
                else {
                    printf("\tGagal melarikan diri!\n\n");
                    printf("\t%s menyerangmu dan menyebabkan %d damage!\n", musuh->nama, damage_musuh);
                    Player->HP -= damage_musuh;

                    if (Player->HP <= 0) {
                        printf("\n\n\t!! Kamu kalah dalam pertarungan !!\n");
                        printf("\n\n\tCredit: Made by Sha\n");
                        printf("\n\n\n\tThanks for playing!\n");
                        exit(0);
                    }
                }
                break;

            default:
                printf("Masukkan input yang valid\n");
        }
    }
}

void beli_senjata(struct penyimpanan *Player, struct senjata *sen) {

	if (strlen(Player->equip) != 0) {
		printf("Kamu sudah mempunyai %s!\n", Player->equip);
		return;
	}

    printf("Senjata apa yang ingin Kamu beli?\n");
    printf("1. Pedang\tharga: %d emas\t\tserangan dasar: %d\n", sen->harga_pedang, sen->damage_pedang);
    printf("2. Busur\tharga: %d emas\t\tserangan dasar: %d\n", sen->harga_busur, sen->damage_busur);
    printf("3. Tombak\tharga: %d emas\t\tserangan dasar: %d\n", sen->harga_tombak, sen->damage_tombak);
    printf("4. Tongkat\tharga: %d emas\t\tserangan dasar: %d\tkonsumsi mp: %d\n", sen->harga_tongkat, sen->damage_tongkat, sen->mp_tongkat);
    printf("5. Info\n");
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
        case 5:
            printf("Serangan total = serangan dasar + faktor random\n");
            printf("faktor random merupakan angka random dari -1 sampai 2\n");
            break;
        case 9:
            break;
        default:
            printf("Masukkan input yang valid\n");
    }
}

void beli_item(struct penyimpanan *Player, struct item *Item) {
    printf("Item apa yang ingin Kamu beli?\n");
    printf("1. HP-Potion\tharga: %d emas\n", Item->harga_hp_potion);
    printf("2. MP-Potion\tharga: %d emas\n", Item->harga_mp_potion);
    printf("9. Kembali\n");

    int pilihan_item;
    printf("-> ");
    scanf("%d", &pilihan_item);
    fflush(stdin);

    switch (pilihan_item) {
        case 1:
            if (Player->emas >= Item->harga_hp_potion) {
                Player->emas -= Item->harga_hp_potion;
                tambah_ke_persediaan(Player, "HP-Potion");
                printf("Kamu telah membeli HP-Potion\n");
            } 
            else {
                printf("Emas tidak cukup!\n");
            }
            break;
        case 2:
            if (Player->emas >= Item->harga_mp_potion) {
                Player->emas -= Item->harga_mp_potion;
                tambah_ke_persediaan(Player, "MP-Potion");
                printf("Kamu telah membeli MP-Potion\n");
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

//  Jauhi gambling dekati GACHA;)
void gacha(struct penyimpanan *Player) {
    int angka_random = rand() % 1000 + 1;  // Angka random 1 - 1000

    // printf("Angka random = %d\n", angka_random); // cheat gacor GACHA
    
    printf("Gacha?\n");
    printf("1. Low Risk Gacha\n");
    printf("2. High Risk Gacha\n");
    printf("3. Info\n");
    printf("9. Kembali\n");

    int pilihan_gacha;
    printf("-> ");    
    scanf("%d", &pilihan_gacha);
    fflush(stdin);

    switch (pilihan_gacha) {
        case 1:
            if (Player->emas < 10) {
                printf("Tidak cukup emas!\n");
                break;
            }
            printf("The wheels of fate are turning...\n");

            if (angka_random >= 1 && angka_random <= 500) {
                printf("Bad luck! -10 emas.\n");
                Player->emas -= 10;
            } else if (angka_random >= 501 && angka_random <= 900) {
                printf("+20 emas!\n");
                Player->emas += 20;
            } else {
                printf("Jackpot! +40 emas!\n");
                Player->emas += 40;
            }
            break;

        case 2:
            if (Player->emas < 40) {
                printf("Tidak cukup emas!\n");
                break;
            }
            printf("The wheels of fate are turning...\n");

            if (angka_random >= 1 && angka_random <= 500) {
                printf("Bad luck! -40 emas.\n");
                Player->emas -= 40;
            } 
            else if (angka_random >= 501 && angka_random <= 900) {
                printf("+40 emas!\n");
                Player->emas += 50;
            } 
            else {
                printf("Jackpot! +100 emas!\n");
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

void tampilkan_persediaan(struct penyimpanan *Player) {
    printf("\n> Inventaris <\n");
	printf("Senjata: %s\n", Player->equip);
    printf("HP: %d\n", Player->HP);
    printf("MP: %d\n", Player->MP);
    printf("%d emas\n", Player->emas);
    for (int i = 0; i < INVENTORY_SIZE; ++i) {
        if (strlen(Player->persediaan[i]) > 0) {
            printf("%d. %s\n", i + 1, Player->persediaan[i]);
        }
    }

    char pilihan_inventaris;
    printf("\n(Input 'a' untuk melepas senjata)\n(Press any button to continue)\n");
    printf("-> ");
    scanf("%c", &pilihan_inventaris);
    fflush(stdin);

    switch (pilihan_inventaris) {
        case 'a':
            strcpy(Player->equip, "");
            printf("Kamu melepas senjata\n");
            break;
        default:
            printf("Kembali\n");
    }
}

//  Menyimpan data struct player sebagai bentuk progress dalam game
void simpan_progress(struct penyimpanan *Player) {
    FILE *file = fopen("progress.txt", "w");
    if (file == NULL) {
        printf("Gagal membuat file progres.\n");
        return;
    }

    fprintf(file, "%d\n", Player->emas);
    fprintf(file, "%d\n%d\n", Player->HP, Player->MP);
    fprintf(file, "%s\n", Player->equip);
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        fprintf(file, "%s\n", Player->persediaan[i]);
    }

    printf("Berhasil menyimpan progress\n");
    
    fclose(file);
}

void muat_progress(struct penyimpanan *Player) {
    FILE *file = fopen("progress.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file progres.\n");
        return;
    }

    fscanf(file, "%d\n", &Player->emas);
    fscanf(file, "%d\n%d\n", &Player->HP, &Player->MP);
    fscanf(file, "%s\n", Player->equip);
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        fscanf(file, "%s\n", Player->persediaan[i]);
    }

    printf("Berhasil memuat progress\n");

    fclose(file);
}


int main() {
    int pilihan_menu_utama, pilihan_toko;
	
    while (pilihan_menu_utama != 9) {
        printf("\n- Main Menu -\n");
        printf("1. Toko\n");
        printf("2. Gacha\n");
        printf("3. Bertualang\n");
        printf("4. Inventaris\n");
        printf("5. Simpan\n");
        printf("6. Muat\n");
        printf("9. Keluar\n");

        printf("-> ");
        scanf("%d", &pilihan_menu_utama);
        fflush(stdin);

        switch (pilihan_menu_utama) {
            case 1:
                printf("\n- Menu Toko -\n");
                printf("1. Beli Senjata\n");
                printf("2. Beli Item\n");
                printf("9. Kembali\n");
                printf("-> ");
                scanf("%d", &pilihan_toko);
                fflush(stdin);

                switch (pilihan_toko) {
                    case 1:
                        beli_senjata(&Player, &Senjata);
                        break;
                    case 2:
                        beli_item(&Player, &Item);
                        break;
                    case 9:
                        break;
                    default:
                        printf("Masukkan input yang valid!\n");
                }
                break;
            case 2:
                gacha(&Player);
                break;
            case 3:
            	init_enemy(&Musuh); // Menambahkan musuh baru
                bertualang(&Player, &Senjata, &Musuh);
                break;
            case 4:
                tampilkan_persediaan(&Player);
                break;
            case 5:
                simpan_progress(&Player);
                break;
            case 6:
                muat_progress(&Player);
                break;
            case 9:
                return 0;
            default:
                printf("Masukkan input yang valid!\n");
        }
    }

    return 0;
}
