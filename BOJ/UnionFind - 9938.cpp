/*

https://www.acmicpc.net/problem/9938

규칙 1,2,3,4 순서로 술을 서랍에 보관하고 아니면 마셔야 되는 문제

규칙 각각에 대해서 가능하다면 서랍 A의 부모와 서랍 B의 부모를 합쳐 줘야 한다.
규칙 1,3 에 대해서는 A의 부모를 B의 부모 라고 하고 (B의 부모에 A의 부모를 연결)
규칙 2,4 에 대해서는 B의 부모를 A의 부모 라고 한다.

이런식으로 구현을 하면 다음번에 그 술을 옮기려고 할 때 그 서랍에 대한
부모를 찾으면 옮길 수 있는 서랍을 O(1)에 알 수 있다. 

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

		//위에서 부터 순서대로 각각의 분기가 규칙 1,2,3,4
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