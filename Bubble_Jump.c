#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <math.h>

/*
Nama: Felliani Kurniawati
NPM: 20081010085
MK: Pemrograman Lanjut Kelas F

Metode : Bubble Sort & Jump Search
*/

// array of struct
struct mahasiswa{
	char nama[50];
	long int NPM;
};

// metode bubble sort
void bubble_sort (struct mahasiswa mahasiswa_arr[], int n){
	int i,j;
	struct mahasiswa temp;
	
	for (i = 0; i < n-1; i++){
		for (j = 0; j < n-i-1; j++){
			if (mahasiswa_arr[j].NPM > mahasiswa_arr[j+1].NPM){
				temp = mahasiswa_arr[j];
				mahasiswa_arr[j] = mahasiswa_arr[j+1];
				mahasiswa_arr[j+1] = temp;
			}
		}
	}
}

// print hasil struct yang sudah urut
void print_array(struct mahasiswa mahasiswa_arr[], int size){
	int i;
	for (i = 0; i < size; i++){
		printf("%d\t| %s\t| %ld\n", i+1, mahasiswa_arr[i].nama, mahasiswa_arr[i].NPM);
	}
}

// jump search
int min(int a, int b){
	return a < b ? a : b;
}

int jump_search(struct mahasiswa mahasiswa_arr[], int n, int key){
	int jump = (int) sqrt(n);
	int left = 0;
	int right = 0;
	
	while (left < n && mahasiswa_arr[left].NPM <= key) {
		right = min(n - 1, left + jump);
		
		if (mahasiswa_arr[left].NPM <= key && mahasiswa_arr[right].NPM >= key){
			break;
		}
		left += jump;
	}
	
	if (left >= n || mahasiswa_arr[left].NPM > key){
		return -1;
	}
	right = min(n - 1, right);
	
	int i;
	for (i = left; i <= right && mahasiswa_arr[i].NPM <= key; i++){
		if (mahasiswa_arr[i].NPM == key){
			return i;
		}
	}
	return -1;
}

// utama
int main(){
	struct mahasiswa mahasiswa_arr[15] = {
		{"Kaito Kid", 101054},
		{"Ran Mori", 101015},
		{"Mary Law", 101030},
		{"Ayase Kimura", 101002},
		{"Suzune", 101032},
		{"Fena Key", 101029},
		{"Yukimaru", 101023},
		{"Noragami", 101087},
		{"Yakobu", 101001},
		{"Tanaka Nao", 101034},
		{"Naomi Key", 101050},
		{"Tamako", 101010},
		{"Shiroi", 101055},
		{"Igarashi Ao", 101099},
		{"Tanaka Kise", 101011},
	};
	
	printf("===================================\n");
	printf("\tData Mahasiswa\n");
	printf("===================================\n");
	printf("No\t| Nama\t\t| NPM\n");
	printf("-----------------------------------\n");
	
	int n = sizeof(mahasiswa_arr) / sizeof(mahasiswa_arr[0]);
	
//	Menampilkan array lama
	print_array(mahasiswa_arr, n);
	
//	Memanggil fungsi bubble sort
	bubble_sort(mahasiswa_arr, n);
	
	printf("\n\n");
	
	printf("===================================\n");
	printf("\tData Mahasiswa Urut\n");
	printf("===================================\n");
	printf("No\t| Nama\t\t| NPM\n");
	printf("-----------------------------------\n");
	
//	Menampilkan array yang sudah urut
	print_array(mahasiswa_arr, n);
	
	
	int length = sizeof(mahasiswa_arr) / sizeof(struct mahasiswa);
	
	printf("\n\n");
	
	int input;
	printf("Masukkan NPM yang ingin dicari: ");
	scanf("%d", &input);
	
//	Memanggil fungsi jump search
	int fungsi = jump_search(mahasiswa_arr, length, input);
	
	printf("\n");
	
//	Menampilkan hasil jump search
	int i = 0;
	do {
		if (fungsi >= 0){
				printf("Hasil anda berada diurutan %d", fungsi + 1);
		} else {
			printf("Masukkan anda tidak ditemukan");
		}
		i++;
	} while ((fungsi != mahasiswa_arr[i].NPM || fungsi == i) && fungsi < -1);
	
	return 0;
}


