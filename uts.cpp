#include <stdio.h>
#include <math.h>

int min(int a, int b){
	return a < b ? a : b;	
}

int jumpSearch(int arr[], int n, int key){
	int jump = (int) sqrt(n);
	int left = 0;
	int right = 0;
	
	while (left < n && arr[left] <= key){
		right = min(n-1, left + jump);
		
		if (arr[left] <= key && arr[right] >= key){
			break;
		}
		left += jump;
	}
	if (left >= n || arr[left] > key){
		return -1;
	}
	right = min (n-1, right);
	int i;
	for (i = left; i <= right && arr[i] <= key; ++i){
		if (arr[i] == key){
			return i;
		}
	}
	return -1;
}

int main(){
	int arr[] = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
	int n = 15;
	
	printf("Elemen 10 found at index %d\n", jumpSearch(arr, n, 10));
	printf("Elemen 15 found at index %d\n", jumpSearch(arr, n, 15));
	printf("Elemen 36 found at index %d\n", jumpSearch(arr, n, 36));
	printf("Elemen 42 found at index %d\n", jumpSearch(arr, n, 42));
	printf("Elemen 19 found at index %d\n", jumpSearch(arr, n, 19));

	return 0;
}

