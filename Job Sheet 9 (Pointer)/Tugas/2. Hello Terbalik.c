// Created by Sha

#include <stdio.h>
#include <string.h>

int main() {
	int i;
    char aisatsu[6] = {'H', 'E', 'L', 'L', 'O'};
    
    char *ptr_aisatsu = aisatsu;
    
    //  Untuk output HELLO
    for (i = 0; i < 5; i++) {
        printf("%c", ptr_aisatsu[i]);
    }
    printf("\n");
    //  Untuk output terbalik / OLLEH:
	for (i = 4; i >= 0; i--) {
        printf("%c", ptr_aisatsu[i]);
    }
    
	return 0;
}

