/*

정해진 예산이 있고, 도로마다 통행료가 있을 때, 정해진 예산으로
1번 도시에서 N번 도시까지 가는 최단 이동거리를 구하는 문제

dp[i][j] => i번째 정점에 왔고 현재 j원을 가지고 있을때 최소 이동 거리
			로 두고 dp로 구현 할 수 있다.

pq를 이용하여 1번 정점부터 시작하여 N번 정점까지 가장 짧은 거리 부터 본다.
단, 정해진 예산이 있으므로 해당 도로를 이용하는 것이 정해진 예산으로 지불
할 수 없으면 해당 도로는 이용하지 않는다.

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

typedef long long ll;

const int INF = 987654321;
const ll INFF = 987654321213;
const ll MOD = 987654321;
const ll PLUS = 1000000;

int k, n, r, s, d, l, t;
vector<pair<pair<int, int >, int > > graph[110];

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d%d%d", &k, &n, &r);

	for (int i = 0; i < r; i++) {
		scanf("%d%d%d%d", &s, &d, &l, &t);
		graph[s].push_back(make_pair(make_pair(d, l), t));
	}

	priority_queue < pair < pair<int, int >, int > > pq;
	pq.push(make_pair(make_pair(0, 0), 1));

	while (!pq.empty()) {

		//l은 거리, t는 비용
		l = -pq.top().first.first, t = pq.top().first.second;
		d = pq.top().second;

		pq.pop();

		if (d == n) break;

		for (int i = 0; i < graph[d].size(); i++) {
			int there = graph[d][i].first.first;
			int len = graph[d][i].first.second;
			int cost = graph[d][i].second;

			//해당 도로를 이용하는 것이 예산으로 지불 할 수 있으면 pq에 넣는다.
			if (cost + t <= k)
				pq.push(make_pair(make_pair(-(l + len), t + cost), there));
		}
	}
	printf("%d\n", d == n ? l : -1);
}