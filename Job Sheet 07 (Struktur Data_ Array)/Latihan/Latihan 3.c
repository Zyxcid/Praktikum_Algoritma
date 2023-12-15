#include <stdio.h>

int main(){
	int marks[10], i, n, average;
	int sum = 0;
	
	printf("Enter number of elements: ");
	scanf("%d", &n);
	
	// input array menggunakan perulangan
	for(i=0; i<n; i++){
		printf("Enter number %d : ", i);
		scanf("%d", &marks[i]);
		
		sum += marks[i];
	}
	
	average = sum/n;
	printf("Average = %d", average);
	
	return 0;
}