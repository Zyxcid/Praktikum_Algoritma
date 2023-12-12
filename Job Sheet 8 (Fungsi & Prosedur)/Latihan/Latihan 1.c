#include <stdio.h>

// membuat fungsi say_hello()
void say_hello(){
	printf("Hello Selamat Datang!\n");
}

// fungsi yang memiliki parameter
void hallo(char name[]){
	printf("Hello %s!\n", name);
}

int main(){
	
	// memanggil fungsi say_hello()
	say_hello();
	say_hello();
	say_hello();
	
	printf("\n");
	
	// memanggil fungsi hallo()
	hallo("Dian");
	hallo("Petani");
	hallo("Kode");
	
	return 0;
}
