/*

N개의 문제를 모두 풀어야 되는데
입력에 따라서 먼저 푸는 문제가 좋은 문제가 있고,
앞 번호의 문제를 뒷 번호의 문제보다 먼저 풀어야 된다.

3가지 조건을 만족하면서 문제집을 풀어야 될때 풀 문제의
순서를 출력하는 문제이다.

deg라는 배열을 이용하여 우선순위를 결정한다.
즉, deg[i]는 i번 문제를 풀기 위해서 먼저 풀어야 할
문제의 수로 정의하여 deg[i]가 0이 될때에 비로소 풀 수 있게끔 한다.

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

int n, m, a, b;
vector<int> graph[32010];
int deg[32010];

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		graph[a].push_back(b);
		deg[b]++;
	}
	priority_queue<int> pq;

	//deg가 0인 문제는 풀 수 있고, 앞 번호부터 
	//풀어야 되므로 pq에 넣는다.
	for (int i = 1; i <= n; i++)
		if (deg[i] == 0) pq.push(-i);

	while (!pq.empty()) {
		int here = -pq.top();
		pq.pop();
		printf("%d ", here);

		for (int i = 0; i < graph[here].size(); i++) {
			int there = graph[here][i];
			deg[there]--;
			//deg가 0이라면 해당 문제는 풀 수 있으므로 pq에 넣는다.
			if (deg[there] == 0)
				pq.push(-there);
		}
	}
	printf("\n");
}