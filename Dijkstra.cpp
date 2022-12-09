#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int number = 6;
int INF = 10000000;

vector<pair<int, int> > a[7]; // ���� �����Դϴ�. 
int d[7]; // �ּ� ����Դϴ�. 

void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int> > pq; // �� �����Դϴ�. 
	pq.push(make_pair(0, start));
	// ����� ������� ó���ϹǷ� ť�� ����մϴ�.
	while(!pq.empty()) {
		int current = pq.top().second;
		// ª�� ���� ���� ������ ����ȭ(-)�մϴ�. 
		int distance = -pq.top().first;
		pq.pop();
		// �ִ� �Ÿ��� �ƴ� ��� ��ŵ�մϴ�. 
		if(d[current] < distance) continue;
		for(int i = 0; i < a[current].size(); i++) {
			// ���õ� ����� ���� ��� 
			int next = a[current][i].second; 
			// ���õ� ��带 ���� ���� ���ļ� ���� ��� 
			int nextDistance = distance + a[current][i].first;
			// ������ �ּ� ��뺸�� �� �����ϴٸ� ��ü�մϴ�. 
			if(nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push(make_pair(-nextDistance, next));
			}
		}
	}
}

int main(void) {
	// �⺻������ ������� ���� ��� ����� �����Դϴ�. 
	for(int i = 1; i <= number; i++) {
		d[i] = INF;
	}
	
	a[1].push_back(make_pair(2, 2));
	a[1].push_back(make_pair(5, 3));
	a[1].push_back(make_pair(1, 4));
	
	a[2].push_back(make_pair(2, 1));
	a[2].push_back(make_pair(3, 3));
	a[2].push_back(make_pair(2, 4));
	
	a[3].push_back(make_pair(5, 1));
	a[3].push_back(make_pair(3, 2));
	a[3].push_back(make_pair(3, 4));
	a[3].push_back(make_pair(1, 5));
	a[3].push_back(make_pair(5, 6));
	
	a[4].push_back(make_pair(1, 1));
	a[4].push_back(make_pair(2, 2));
	a[4].push_back(make_pair(3, 3));
	a[4].push_back(make_pair(1, 5));
	
	a[5].push_back(make_pair(1, 3));
	a[5].push_back(make_pair(1, 4));
	a[5].push_back(make_pair(2, 6));
	
	a[6].push_back(make_pair(5, 3));
	a[6].push_back(make_pair(2, 5));
	
	dijkstra(1);
	
	// ����� ����մϴ�. 
	for(int i = 1; i <= number; i++) {
		printf("%d ", d[i]);
	}
}