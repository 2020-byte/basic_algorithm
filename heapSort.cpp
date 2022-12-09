//#include <stdio.h>
//
//int number = 9;
//int heap[9] = {7, 6, 5, 8, 3, 5, 9, 1, 6};
//
//int main(void) {
//	for (int i = 1; i < number; i++) {
//		int c = i;
//		do {
//			int root = (c - 1) / 2;
//			if(heap[root] < heap[c]) {
//				int temp = heap[root];
//				heap[root] = heap[c];
//				heap[c] = temp;
//			}
//			c =  root;
//		} while (c != 0);
//	} 
//	
//	for (int i = number - 1; i >= 0; i--) {
//		int temp = heap[0];
//		heap[0] = heap[i];
//		heap[i] = temp;
//		int root = 0;
//		int c = 1;
//		do {
//			c = 2 * root + 1;
//			if(c < i - 1 && heap[c] < heap[c + 1]) {
//				c++;
//			}
//			
//			if(c < i && heap[root] < heap[c]) {
//				temp = heap[root];
//				heap[root] = heap[c];
//				heap[c] = temp;
//			}
//			root = c;
//		} while(c < i);
//	}
//	
//	for(int i = 0; i <number; i++) {
//		printf("%d ", heap[i]);
//	}
//}

//It's very efficient in terms of memory. 
//In addition, O(N*logN) is always guarantees O(N*logN).


//#include <stdio.h>
//
//int number = 9;
//int heap[9] = {7, 6, 5, 8, 3, 5, 9, 1, 6};
//
//int main(void) {
//	for(int i = 1; i < number; i++) {   // O(N)
//		int c = i;
//		do {
//			int root = (c - 1) / 2;
//			if(heap[root] < heap[c]) {
//				int temp = heap[root];
//				heap[root] = heap[c];
//				heap[c] = temp;
//			}
//			c= root;
//		} while (c != 0);  //O(logN)
//	} //O(NlogN)
//	
//	for (int i = number - 1; i >= 0; i--) {   //O(N)
//		int temp = heap[0];
//		heap[0] = heap[i];
//		heap[i] = temp;
//		int root = 0;
//		int c = 1;
//		
//		do {
//			int c = 2 * root + 1;
//			if(heap[c] < heap[c + 1] && c < i - 1) {
//				c++;
//			}
//			if( heap[root] < heap[c] && c < i) {
//				temp = heap[root];
//				heap[root] = heap[c];
//				heap[c] = temp;
//			}
//			root= c;    //here reason why root=c which is different with above, because here
//						//once we find bigger one between two childs and change with root
//						//that root is automatically bigger than the other cild 
//						//so we can do hip following only one way
//		} while ( c < i ); //O(logN)
//	} //O(NlogN)
//	
//	for(int i = 0; i < number; i++) {
//		printf("%d ", heap[i]);
//	}
//}




#include <stdio.h>

int number = 9;
int heap[9] = {7, 6, 5, 8, 3, 5, 9, 1, 6};

int main(void) {

	for(int i = 1; i <= number; i++) {
		int c = i;
		while (c != 0) {
			int root = (c - 1) / 2;
			if(heap[root] < heap[c]) { //dont need to make for loop 1/2 bc if state doenst satisfies if statement it automatically skip so it will not be calculated
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			c = root;
		} 
	}

	for (int i = number - 1; i > 0; i--) { 
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		int root = 0;
		int c = 1;
		while (c < i) {
			c = 2 * root + 1;  // c can be smaller than i before enter, but when it come inside c can be >=i -1

			if(c < i - 1 && heap[c] < heap[c + 1]) {
				c++;
			}

			if(c < i && heap[root] < heap[c]) {
				temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			root = c;
		} //the origin answer code used do while i think bc it is about c.
		 // by the recursive thing of c or root, before it comes to while, the first c doesnt matter but after come into recursive, c matter
		//so when use someithing like this (recurseive) should better use do while
	} 

	for(int i = 0; i < number; i++) {
		printf("%d ", heap[i]);
	}
}


