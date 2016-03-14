/*
'k번째' 최단 경로를 출력해야 하는 문제

일반적인 다익스트라 알고리즘을 약간 변형한다.
다익스트라 함수 안에서 dist 배열 정점에 대한 원소를
priorityQueue를 이용하여 저장한다.

*/

#include <algorithm>
#include <functional>
#include <vector>
#include <map>    
#include <cstdio>
#include <string>
#include <queue>
#include <limits.h>
#include <stack>
#include <set>
#include <math.h>
#include <cstring>
using namespace std;

const int INF = 987654321;

int n, m, k, a, b, c;
vector<pair<int, int > > graph[1010];

//k번째 최단 경로를 반환하는 함수
vector<priority_queue<int > > dijkstra(int s) {

	//dist배열 안의 원소는 pq이다.
	vector<priority_queue<int> > dist(n + 1);
	priority_queue<pair<int, int > > pq;
	pq.push(make_pair(0, s));
	dist[s].push(0);

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[here].size(); i++) {
			int there = graph[here][i].first;
			int nextdist = graph[here][i].second + cost;

			//현재까지 there의 최단경로가 k개를 못찾았다면 현재 최단경로를
			//넣어주고 최단경로가 k개라면 최단경로가 가장 큰값과 비교하여
			//작을 경우에만 최단경로를 넣어준다.
			int kdist = dist[there].size() == k ? dist[there].top() : INF;

			if (nextdist<kdist) {
				//현재 dist[there]의 pq의 size가 k개 라면.. k개를 유지시킨다.
				if (kdist != INF) dist[there].pop();
				//nextdist를 push
				dist[there].push(nextdist);
				pq.push(make_pair(-nextdist, there));
			}
		}
	}
	return dist;
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);

	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		graph[a].push_back(make_pair(b, c));
	}

	vector<priority_queue<int > > v = dijkstra(1);

	for (int i = 1; i < v.size(); i++) {
		int a = v[i].size() == k ? v[i].top() : -1;
		printf("%d\n", a);
	}
}