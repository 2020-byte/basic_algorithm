#include <iostream>
#include <vector>
#define MAX 101

using namespace std;

vector<int> a[MAX];
int d[MAX];
bool c[MAX];
int n = 3, m, s;


bool dfs(int x) {
	for(int i = 0; i < a[x].size(); i++) {
		int t = a[x][i];
		// It's for the base of the recursive function, so you might be used to it not being used at the first cycle.
		if(c[t]) continue;
		c[t] = true;
		//In case(if), when the destination is empty || when the one occupying that destination can go other place.
		if(d[t] == 0 || dfs(d[t])) {
			d[t] = x;
			return true;
		}
	}
	return false;
}

int main(void) {
	a[1].push_back(1);
	a[1].push_back(2);
	a[1].push_back(3);
	a[2].push_back(1);
	a[3].push_back(2);
	int count = 0;
	for(int i = 1; i <= n; i++) { 
		fill(c, c + MAX, false);
		if(dfs(i)) count++;
	}
	printf("%d match has been made.\n", count);
	for(int i = 1; i <= 100; i++) {
		if(d[i] != 0) {
			printf("%d -> %d\n", d[i], i);
		}
	}
	return 0;
}
