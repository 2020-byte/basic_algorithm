//#include <stdio.h>
//
//int main(void) {
//	int i, j, temp;
//	int array[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
//	for(i = 0; i < 10; i++) {
//		for(j = 0; j < 9 - i; j++) {
//			if(array[j] > array[j+1]) {
//				temp = array[j];
//				array[j] = array[j+1];
//				array[j+1] = temp;
//			}
//		}
//	}
//	for (i = 0; i < 10; i++) {
//		printf("%d ", array[i]);
//	}
//	return 0;
//}

//in bubble sort, every loop, biggest number in each loop places from the last.
//
//in selection sort, every loop, smallest number in each loop places from the first.  


//O(N^2)

//It can be said that it is a bad algorithm with the slowest actual execution time 
//because the computation inside the computer becomes the most inefficient.


#include <stdio.h>

int main(void) {
	int i, j, temp;
	int array[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	
	for( i = 0; i < 10; i++) {
		for( j = 0; j < 9-i; j++) {
			if(array[j]> array[j+1]) {
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
	for (i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	return 0;
}







