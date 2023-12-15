#include <stdio.h>

int main(){
	char ulangi = 'y';
	int counter = 0;
	
	do{
		printf("Apakah kamu ingin mengulang?\n");
        printf("Jawab (y/t) : ");
        scanf(" %c", &ulangi);  

        // increment counter
        counter++;
	} while(ulangi == 'y');
	
	printf("\n\n-------------\n");
    printf("Perulangan selesai.\n");
    printf("Kamu mengulang sebanyak %i kali", counter);

    return 0;
}