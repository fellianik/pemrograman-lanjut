#include <stdio.h>
#include <string.h>

/*
Nama: Felliani Kurniawati
NPM: 20081010085
MK: Pemrograman Lanjut Kelas F

Metode: Bubble Sort
*/

// bubble sort
void bubbleSort (char nama[][100], int n){
	int i, j;
	char temp[100];
	
	for (j = 0; j < n-1; j++){
		for (i= j+1; i < n; i++){
			if (strcmp(nama[j], nama[i]) > 0){
				strcpy(temp, nama[j]);
				strcpy(nama[j], nama[i]);
				strcpy(nama[i], temp);
			}
		}		
	}		
}

void printArray (char nama[][100], int n){
	int i;
	for (i = 0; i < n; i++){
		printf("%d. %s\n", i+1, nama[i]);
	}
}

// utama
int main () {
	printf("=====================================\n");
	printf("\tProgram Bubble Sort\n");
	printf("=====================================\n");

	
	char nama[][100] = {"Christ", "Fay", "Moriarty", "Ray", "Kid", "Arthur"};
	int n = sizeof(nama) / sizeof(nama[0]);
	int i;
	
//	menampilkan array lama
	printf("Array Lama :\n");
	printArray(nama, n);
	
//	memanggil fungsi bubble sort
	bubbleSort(nama, n);
	
	printf("\n\n");
	
//	menampilkan array baru
	printf("Array Baru :\n");
	printArray(nama, n);
		
	return 0;
}
