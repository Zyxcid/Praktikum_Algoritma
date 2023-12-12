#include <stdio.h> // library standar input output

// main function
main(void){
	// deklarasi variabel
	int a = 6;
	int b = 3;
	
	//bitwise AND
	printf("Operator Bitwise AND : a & b = %d\n", a & b);
	
	//bitwise OR
	printf("Operator Bitwise OR : a | b = %d\n", a | b);
	
	//bitwise XOR
	printf("Operator Bitwise XOR : a ^ b = %d\n", a ^ b);
	
	//bitwise NOT
	printf("Operator Bitwise NOT : ~a = %d\n", ~a);
	
	//bitwise Left Shift
	printf("Operator Bitwise Left Shift : a << 1 = %d\n", a << 1);
	
	//bitwise Right Shift
	printf("Operator Bitwise Right Shift : a >> 1 = %d\n", a >> 1);
}
