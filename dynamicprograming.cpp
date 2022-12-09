#include <stdio.h>

int d[1000001];
	
long long int dp(int d[], int x) {
	if(x == 0) return 1;
	if(x == 1) return 2;
	if(x == 2) return 7;
	if(d[x] > 0) return d[x];
	long long int result = 3 * dp(d, x - 2) + 2 * dp(d, x - 1);
	for(int i = 3; i <= x; i++) {
		result += (2 * dp(d, x - i))  % 100000007; // here thing is calculated from d[3] but it isn't saved, so wasting time by calculating more than once.
	}
	return d[x] = result % 100000007;
}

int main(void)
{
	int x;
	scanf("%d", &x);
	printf("%lld", dp(d, x));
	return 0;
}



int d[1000001];
	
long long int dp(int d[], int x) {
	d[0] = 1;
	d[1] = 2;
	d[3] = 7;
	for(int i = 3; i <= x; i++) {
		d[x] = 3*d[x-2]+2*d[x-1];
	}
	return d[x] = result % 100000007;
}

int main(void)
{
	int x;
	scanf("%d", &x);
	printf("%lld", dp(d, x));
	return 0;
}
