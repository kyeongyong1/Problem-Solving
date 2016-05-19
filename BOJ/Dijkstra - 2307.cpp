/*

� ���ΰ� ������ � ���θ� ���Ƽ� ������ų �� �ִ�
�ִ�ð��� ����ϴ� ����

���ͽ�Ʈ�� �˰������� �ִܰ�θ� ���ϰ�, �ִܰ�θ� �̾Ƴ���
�ִܰ�� '����'�� ���ؼ� �Ѱ��� ���� ���� �ִܰ�θ� ���Ѵ�.
�� �� ���� ũ�� ���� �ִܰ�ΰ� � ���θ� ������ ��
�ִ�� ������ �ִܰ���̴�.

*/
#include <algorithm>
#include <functional>
#include <vector>
#include <map>    
#include <cstdio>
#include <queue>
#include <stack>
#include <set>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const int RETURN = 0x3f3f;
const int INF = 987654321;
const int MAX_SIZE = 500000 * 4;
const int MAX_NUM = 1000000010;
const ll INFF = 9876543212345;
const int MAX_V = 210;

int n, m, a, b, t;
int graph[1010][1010], parent[1010];

int dijkstra(int s) {

	vector<int> dist(n + 1, INF);
	dist[s] = 0;
	parent[s] = -1;
	priority_queue<pair<int, int > > pq;
	pq.push(make_pair(0, s));

	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (dist[here] < cost) continue;

		for (int i = 0; i <= n; i++) {
			if (graph[here][i]>0) {
				int nextdist = cost + graph[here][i];
				if (dist[i] > nextdist) {

					parent[i] = here;
					dist[i] = nextdist;
					pq.push(make_pair(-nextdist, i));

				}
			}
		}

	}
	return dist[n];
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &a, &b, &t);
		graph[a][b] = t, graph[b][a] = t;
	}
	int res = dijkstra(1);
	vector<int> order;
	int here = n, maxx = 0;
	while (here != -1) {
		order.push_back(here);
		here = parent[here];
	}
	for (int i = 0; i < order.size() - 1; i++) {
		int here = order[i];
		int hereParent = order[i + 1];
		int Cost = graph[here][hereParent];
		graph[here][hereParent] = graph[hereParent][here] = 0;

		int aa = dijkstra(1);
		maxx = max(maxx, aa);
		graph[here][hereParent] = graph[hereParent][here] = Cost;
	}
	printf("%d\n", maxx == INF ? -1 : maxx - res);
}