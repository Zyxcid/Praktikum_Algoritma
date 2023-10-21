#include <stdio.h>

int main () {
    int nilai_akhir, presensi, praktek, uts, uas;
	
	//presensi = 85, praktek = 65, uts = 80, uas = 75
	
	presensi = 85*10/100;
	praktek = 65*20/100;
	uts = 80*30/100;
	uas = 75*40/100;
	
	nilai_akhir = presensi + praktek + uts + uas;
	
	printf("Nilai akhir ditentukan oleh presensi(10%%), praktek(20%%), UTS(30%%), UAS(40%%)\n\n");
	printf("presensi = 85, praktek = 65, uts = 80, uas = 75\n");

	printf("Nilai akhir = %d ", nilai_akhir);

	return 0;
}
