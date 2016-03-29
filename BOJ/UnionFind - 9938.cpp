/*

https://www.acmicpc.net/problem/9938

��Ģ 1,2,3,4 ������ ���� ������ �����ϰ� �ƴϸ� ���ž� �Ǵ� ����

��Ģ ������ ���ؼ� �����ϴٸ� ���� A�� �θ�� ���� B�� �θ� ���� ��� �Ѵ�.
��Ģ 1,3 �� ���ؼ��� A�� �θ� B�� �θ� ��� �ϰ� (B�� �θ� A�� �θ� ����)
��Ģ 2,4 �� ���ؼ��� B�� �θ� A�� �θ� ��� �Ѵ�.

�̷������� ������ �ϸ� �������� �� ���� �ű���� �� �� �� ������ ����
�θ� ã���� �ű� �� �ִ� ������ O(1)�� �� �� �ִ�. 

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

int n, l, a, b;
bool visited[300010];

struct DisjoinSet {

	DisjoinSet() {}
	vector<int> parent, rank;
	DisjoinSet(int n) {
		parent.resize(n);
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	int find(int u) {
		if (parent[u] == u) return u;
		else return parent[u] = find(parent[u]);
	}
	void merge(int u, int v) {

		u = find(u), v = find(v);
		if (u == v) return;
		parent[u] = v;
	}
};

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d%d", &n, &l);

	DisjoinSet ds(l + 1);
	for (int i = 0; i < n; i++) {

		scanf("%d%d", &a, &b);

		//������ ���� ������� ������ �бⰡ ��Ģ 1,2,3,4
		if (visited[a] == false) {
			visited[a] = true;
			ds.merge(ds.find(a), ds.find(b));
		}
		else if (visited[b] == false) {
			visited[b] = true;
			ds.merge(ds.find(b), ds.find(a));
		}
		else if (visited[ds.find(a)] == false) {
			visited[ds.find(a)] = true;
			ds.merge(ds.find(a), ds.find(b));
		}
		else if (visited[ds.find(b)] == false) {
			visited[ds.find(b)] = true;
			ds.merge(ds.find(b), ds.find(a));
		}
		else {
			printf("SMECE\n");
			continue;
		}
		printf("LADICA\n");
	}
}