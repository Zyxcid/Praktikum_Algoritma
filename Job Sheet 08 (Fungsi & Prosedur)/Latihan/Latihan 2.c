#include <stdio.h>

void add(int a, int b){
	printf("%d + %d = %d\n", a, b, a+b);
}

int main(){
	
	add (1, 4);
	add(8, 2);
	add(3, 2);
	
	return 0;
}
	