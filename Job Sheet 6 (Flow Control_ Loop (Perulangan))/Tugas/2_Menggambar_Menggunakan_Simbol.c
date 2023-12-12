// Created by Syahid Nurhidayatullah (23343056)
/*
menggambar simbol berikut:
*
**
***
****
*****
*/

#include <stdio.h>

int main(){
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}
