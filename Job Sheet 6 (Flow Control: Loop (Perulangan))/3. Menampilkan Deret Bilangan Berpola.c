// Created by Sha
/*
menampilkan keluaran sebagai berikut:
1
2 4 
3 6 9 
4 8 12 16
5 10 15 20 25
*/

#include <stdio.h>

int main(){	
    for (int i = 1; i <= 5; i++) {
        int num = i;
        for (int j = 1; j <= i; j++) {
            printf("%d ", num);
            num += i;
        }
        printf("\n");
    }
}
