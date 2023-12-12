#include <stdio.h>

int main() {
    char ulangi = 'y';
    int counter = 0;

    // perulangan while
    while (ulangi == 'y') {
        printf("Apakah kamu ingin mengulang?\n");
        printf("Jawab (y/t) : ");
        scanf(" %c", &ulangi);  // perbaikan di sini, tambahkan spasi sebelum %c

        // increment counter
        counter++;
    }

    printf("\n\n-------------\n");
    printf("Perulangan selesai.\n");
    printf("Kamu mengulang sebanyak %i kali", counter);

    return 0;
}
