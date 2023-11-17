#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int tebakan;
	char lanjut;
	
    srand(time(NULL));
    int x = rand()%20;
    printf("%d\n", x);
    
    LOOP:do {

    	while (tebakan != x){
    		printf("masukkan tebakan anda: ");
	    	scanf("%d", &tebakan);
	    	getchar();
	    	
			if (tebakan < x) {
	    		printf("Nomor saya lebih besar! ");
	    		continue;
			}
	    	else if (tebakan > x) {
	    		printf("Nomor saya lebih kecil! ");
	    		continue;
	    	}
	    	else if (tebakan = x) {
	    		printf("Selamat Anda benar! ");
	    		break;
	    	}
		}
    	
	    printf("Apakah anda ingin bermain lagi? (y/n) ");
	    scanf("%c", &lanjut);
	    if (lanjut = 'y'){
	    	goto LOOP;
		}
	
	} while (lanjut != 'n');
	
    return 0;
}
