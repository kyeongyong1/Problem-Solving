/*

������ ���� �ٸ��� ����Ǿ� �ִµ� �� �ٸ��� �߷������� �ִ�.
�� ��, �� ������ �ٸ� ������ ���� ��� �� �� �ִ� �ִ밪�� ����ϴ� ����

Parametric Search + BFS

Parametric Search ���� �߷��̰�, �� �߷��� ���� ������ ���θ�
�Ǵ��ϴ� �Լ����� BFS�� ������. �ش� �߷����� ���� ������ ���� ������
�� �� ������ ���ʹ��� ���ְ�, �ƴ϶�� �����ʹ��� ���ش�.

*/



#include <algorithm>
#include <functional>
#include <vector>
#include <map>    
#include <cstdio>
#include <queue>
#include <climits>
#include <stack>
#include <set>
#include <cmath>
#include <cstring>
#include <list>
using namespace std;

int n, m, a, b, c, s, t;
vector<pair<int, int > > graph[100010];
bool visited[100010];

bool func(int mid) {

	queue<int> q;
	q.push(s);
	memset(visited, 0, sizeof(visited));
	visited[s] = true;

	while (!q.empty()) {
		int here = q.front();
		q.pop();

		for (int i = 0; i < graph[here].size(); i++) {
			int there = graph[here][i].first;
			int cut = graph[here][i].second;

			if (cut >= mid && visited[there] == false) {
				if (there == t) return true;
				visited[there] = true;
				q.push(there);
			}
		}
	}
	return false;
}

int main() {

	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	scanf("%d%d", &s, &t);
	int lo = 1, hi = 1000000001;

	int res = -1;
	for (int i = 0; i < 100; i++) {
		int mid = (lo + hi) / 2;

		if (func(mid)) {
			res = max(res, mid);
			lo = mid;
		}
		else
			hi = mid;
	}
	printf("%d\n", res);
}