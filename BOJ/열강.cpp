#include <algorithm>
#include <vector>  
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <functional>
#include <queue>
#include <set>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;
const int INF = 987654321;

struct Edge {
	int cap, next;
	Edge *rev;
	Edge() {};
};

int n, m, k, source = 0, sink = 1, a, b, MAX_V;
vector<int> parent, iter;
vector<Edge *> graph[2010];

void addEdge(int u, int v, int c) {
	Edge *uv = new Edge(), *vu = new Edge();

	uv->next = v, uv->cap = c, uv->rev = vu;
	vu->next = u, vu->cap = 0, vu->rev = uv;

	graph[u].push_back(uv);
	graph[v].push_back(vu);
}
void bfs() {
	queue<int> q;
	parent[source] = source;
	q.push(source);
	while (!q.empty() && parent[sink] == -1) {
		int here = q.front(); q.pop();
		for (int i = 0; i < graph[here].size(); i++) {
			Edge *e = graph[here][i];
			int there = e->next;
			if (e->cap && parent[there] == -1) {
				q.push(there); parent[there] = parent[here] + 1;
			}
		}
	}
}
int dfs(int here, int curFlow) {

	if (here == sink) return curFlow;

	for (int &i = iter[here]; i < graph[here].size(); i++) {
		Edge *e = graph[here][i];
		int there = e->next;
		if (e->cap && parent[here] < parent[there]) {
			int amount = dfs(there, min(curFlow, e->cap));
			if (amount > 0) {
				e->cap -= amount;
				e->rev->cap += amount;
				return amount;
			}
		}
	}
	return 0;
}
int networkFlow() {

	int totalFlow = 0, amount;
	while (1) {
		iter = vector<int>(MAX_V, 0);
		parent = vector<int>(MAX_V, -1);
		bfs();
		if (parent[sink] == -1) break;
		while (amount = dfs(source, INF)) {
			totalFlow += amount;
		}
	}
	return totalFlow;
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d %d %d", &n, &m, &k);
	MAX_V = 2 + n + m + 1;

	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		for (int j = 0; j < a; j++) {
			scanf("%d", &b);
			addEdge(2 + i, 2 + n + (b - 1), 1);
		}
	}
	for (int i = 2; i < 2 + n; i++)
		addEdge(0, i, 1);
	for (int i = 0; i < m; i++)
		addEdge(2 + n + i, 1, 1);

	int res = networkFlow(), cnt = 0;
	addEdge(0, MAX_V - 1, 1010);

	for (int i = 0; i < n; i++) {
		if (res >= m || cnt == k)
			break;

		addEdge(MAX_V - 1, i + 2, 1);
		int temp = networkFlow();
		if (temp == 1)
			res++, cnt++;

	}
	printf("%d\n", res);
}