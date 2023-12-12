#include <stdio.h>

int main(){
	// deklarasi array of char
	char greeting[6] = {'H', 'E', 'L', 'L', 'O', '\O'}; // \O adalah null character
	
	printf("Greeting message : %s\n", greeting);
	
	return 0;
}