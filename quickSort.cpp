//#include <stdio.h>
//
//int number = 10;
//int data[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
//
//void quickSort(int *data, int start, int end) {
//	if (start >= end) { //When element is one. 
//		return;
//	}
//	
//	int key = start; //Key is first element
//	int i =  start + 1;
//	int j = end;
//	int temp;
//	
//	while(i <= j) { //Repeat untill it cross it
//		while(data[i] <= data[key] && i <= end) { //Until meet a value greater than your Key **
//			i++;
//		}
//		while(data[j] >= data[key] && j > start) { //Until meet a value lower than your Key	**
//			j--;
//		}
//		if(i > j) { //If it is crossed, replace it with the key value.
//			temp = data[j];
//			data[j] = data[key];
//			data[key] = temp;
//		} else {
//			temp = data[j];
//			data[j] = data[i];
//			data[i] = temp;
//		}
//		
//	}
//	quickSort(data, start, j - 1);
//	quickSort(data, j + 1, end);
//}
//
//int main(void) {
//	quickSort(data, 0, number - 1);
//	for(int i = 0; i < number; i++) {
//		printf("%d ", data[i]);
//	}
//}






///////////////////////////////////////////////////////////////
#include <stdio.h>

int number = 10;
int data[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

void quickSort(int *data, int start, int end) {
	if(start >= end) {
		return;
	}
	int key = start;
	int i = start + 1;
	int j = end;
	int temp;
	while(i<=j) {
		while( data[i] <= data[key] && i <=end) {
			i++;
		}
		while( data[j] >= data[key] && j > start ) {
			j--;
		}
		if(i > j) {
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		} else {
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;
		}
	}
	
	quickSort(data, start, j-1);
	quickSort(data, j+1, end);
}

int main(void) {
	quickSort(data, 0, number - 1);
	for(int i = 0; i < number; i++) {
		printf("%d ", data[i]);
	}
}


//O(NlogN)  
//but worst case: O(N^2)  when it is already almost aligned. because it separated in one side i guess	
