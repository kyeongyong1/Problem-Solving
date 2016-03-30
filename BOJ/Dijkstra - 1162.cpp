/*

1�� ���ú��� N�� ���ñ��� ���µ� �ּ� �ð��� ����ϴ� ����
���ÿ� ���ô� ���η� �̾��� �ִ�. k�� ������ ���δ� ������ �� �ְ�
�����ϸ� �� ���θ� �̵��Ͽ� �ɸ��� �ð��� 0�� �ȴ�.

���ͽ�Ʈ�� �ణ �����Ͽ� ������ Ǯ �� �ִ�.

*/

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>    
#include <cstdio>
#include <string>
#include <queue>
#include <stack>
#include <math.h>
#include <cstring>
using namespace std;

const int INF = 987654321;

int n, m, k, u, v, t;
vector<pair<int, int > > graph[10010];

int dijkstra(int s) {

	//dist[i][j] ���� j�� ���� �԰�, �̶����� ���θ� ������ Ƚ���� i�� �϶�
	//			 �ɸ��� �ּ� �ð�
	int dist[22][10010];
	memset(dist, 0x3f, sizeof(dist));
	priority_queue < pair<pair<int, int >, int > > pq;
	pq.push(make_pair(make_pair(0, s), 0));

	while (!pq.empty()) {
		int cost = -pq.top().first.first;
		int here = pq.top().first.second;
		int cnt = pq.top().second;
		pq.pop();

		if (dist[cnt][here] < cost) continue;

		for (int i = 0; i < graph[here].size(); i++) {
			int there = graph[here][i].first;
			int nextdist = cost + graph[here][i].second;

			//���θ� �����ϴ� ���
			if (cnt<k && dist[cnt + 1][there] > cost) {
				dist[cnt + 1][there] = cost;
				pq.push(make_pair(make_pair(-cost, there), cnt + 1));
			}
			if (dist[cnt][there] > nextdist) {
				dist[cnt][there] = nextdist;
				pq.push(make_pair(make_pair(-nextdist, there), cnt));
			}
		}
	}
	return dist[k][n];
}
int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	ios::sync_with_stdio(false);

	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		cin >> u >> v >> t;
		graph[u].push_back(make_pair(v, t));
		graph[v].push_back(make_pair(u, t));
	}
	cout << dijkstra(1) << endl;
}