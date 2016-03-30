/*

1번 도시부터 N번 도시까지 가는데 최소 시간을 출력하는 문제
도시와 도시는 도로로 이어져 있다. k개 이하의 도로는 포장할 수 있고
포장하면 그 도로를 이동하여 걸리는 시간은 0이 된다.

다익스트라를 약간 변형하여 문제를 풀 수 있다.

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

	//dist[i][j] 도시 j번 까지 왔고, 이때까지 도로를 포장한 횟수가 i번 일때
	//			 걸리는 최소 시간
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

			//도로를 포장하는 경우
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