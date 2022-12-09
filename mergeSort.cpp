//#include <stdio.h>
//
//int number = 8;
//int size;
//int sorted[8];  //array must be declared a global variable
//int count = 0;
//
//void merge(int a[], int m, int middle, int n) {
//	int i = m;
//	int j = middle + 1;
//	int k = m;
//	
//	while(i <= middle && j <= n) {
//		if(a[i] <= a[j]) {
//			sorted[k] = a[i];
//			i++;
//		} else {
//			sorted[k] = a[j];
//			j++;
//		}
//		k++;
//	}
//	if(i>middle) {               //when all of left is sorted first  
//		for(int t = j; t <= n; t++) {
//			sorted[k] = a[t];
//			k++;
//		}
//	} else {                    //when all of right is sorted first 
//		for (int t = i; t<=middle; t++) {
//			sorted[k] = a[t];
//			k++;
//		}
//	}
//	
//	for(int t = m; t <= n; t++) {
//		a[t] = sorted[t];
//	}
//}
//
//void mergeSort(int a[], int m, int n) {
//	if(m < n) {
//		int middle = (m+n) / 2;
//		mergeSort(a, m, middle);
//		mergeSort(a, middle + 1, n);
//		merge(a, m, middle, n);
//	}
//}
//
//
//int main(void) {
//	int array[number] = {7, 6, 5, 8, 3, 5, 9, 1};
//	mergeSort(array, 0, number - 1);
//	for(int i = 0; i < number; i++) {
//		printf("%d ", array[i]);
//	}
//}



//Merge sorting is a very efficient algorithm 
//in that although it is generally slower than quick sorting, 
//it can guarantee exactly O(N * logN) under any circumstances.


#include <stdio.h>

int number = 8;
int sorted[8];

void merge(int a[], int m, int middle, int n) {
	int i = m;
	int j = middle+1;
	int k = m;
	int t;
	
	while(i <= middle && j <= n) {
		if(a[i] <= a[j] ) {
			sorted[k] = a[i];
			i++;
		} else {
			sorted[k] = a[j];
			j++;
		}
		k++;
	}
	if(i > middle) {
		t = j;
	}else {
		t = i;
	}
	while( t <= n) {
			sorted[k] = a[t];
			t++;
			k++;
	}
	
	for(int t = m; t<= n; t++) {
		a[t] = sorted[t];
	}
}

void mergeSort(int a[], int m, int n) {
	if( m < n) {
		int middle = (m + n) / 2;
		mergeSort(a, m, middle);
		mergeSort(a, middle + 1, n);
		merge(a, m, middle, n);
	}
} 


int main(void) {
	int array[number] = {7, 6, 5, 8, 3, 5, 9, 1};
	mergeSort(array, 0, number - 1);
	for(int i = 0; i < number; i++) {
		printf("%d ", array[i]);
	}
	
	return 0;
}
