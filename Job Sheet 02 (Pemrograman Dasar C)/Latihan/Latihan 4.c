#include <stdio.h> // library standar input output

// main function
int main() {
    // deklarasi variabel
    char nama[20], web_address[30];
    
    // meminta input nama dari user
    printf("Nama: ");
    scanf("%s", &nama); 
    
    // meminta input alamat dari user
    printf("Alamat web: ");
    scanf("%s", &web_address); 
    
    // memprint nama dan alamat web yang diinputkan
    printf("\n----------------------------\n");
    printf("Nama yang diinputkan: %s\n", nama); 
    printf("Alamat web yang diinputkan: %s\n", web_address);
    
    // return 0 berfungsi untuk mengakhiri program
    return 0;
}
