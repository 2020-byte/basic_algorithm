#include <stdio.h>

//int d[100];
//
//int fibonacci(int x) {
//	if( x == 1) return 1;
//	if( x == 2) return 1;
//	if(d[x] != 0) return d[x];
//	return d[x] = fibonacci( x -1 ) + fibonacci(x - 2);
//}
//
//int main(void) {
//	printf("%d", fibonacci(30));
//}

//If the recurrence relation include when n is 0, we have to set base when it is 0.

int d[101];
int fibonacci(int x) {
	d[1] = 1;
	d[2] = 1;
	for ( int i = 3; i <= x; i++) {
		d[i] = d[i-1] + d[i-2];
	}
	return d[x];
}

int main(void) {
	printf("%d", fibonacci(30));
}
