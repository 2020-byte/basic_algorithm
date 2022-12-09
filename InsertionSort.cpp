#include <stdio.h>

int main(void) {
	int i, j, temp;
	int array[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	for(i = 0; i < 10; i++) {
		for( j = i ; j > 0; j-- ) {
			if( array[j] < array[j-1]) {
				temp = array[j];
				array[j] = array[j-1];
				array[j-1] = temp;
			}
		}
	}
	
	for( i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	
	
	return 0;
}

//it is faster than any other algorithm when data almost aligned.

//#include <stdio.h>
//
//int main(void) {
//	int i, j, temp;
//	int array[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
//	for(i = 0; i < 9; i++) {
//		j = i;
//		while(j >= 0 && array[j] > array[j + 1]) {
//			temp = array[j];
//			array[j] = array[j + 1];
//			array[j + 1] = temp;
//			j--;
//		}
//	}
//	for(i = 0; i < 10; i++) {
//		printf("%d ", array[i]);
//	}
//	return 0;
//}
