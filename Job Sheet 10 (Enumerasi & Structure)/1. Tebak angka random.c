//  Created by Sha

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int tebakan;
	char lanjut;
	
    srand(time(NULL));
    int x = rand()%20;
    printf("%d\n", x);
    
    do {

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
	
	} while (lanjut = 'y');
	
    return 0;
}
