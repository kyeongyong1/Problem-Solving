/*

그래프의 정점의 부분 집합 중에서 정점쌍이 서로 인접하지 않으면
그 부분 집합을 독립 집합이라고 하는데 이때 최대 독립 집합을 구하는 문제이다.

정점의 가중치가 주어진다.

DP[i][j] i번째 정점 봤을때 그 정점을 선택 했을때 (j==1)
혹은 선택 하지 않았을때 (j==0) 가중치 합의 최대값


nx[i][j] 현재 정점이 i번이고, 상태가 j일때 다음번째 상태를 pair값으로 저장
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

int n, a, b, dp[10010][2];
vector<int> w, graph[10010], tree[10010];
bool visited[10010];
vector<int> s;
vector<pair<int, int > > nx[10010][2];

int sol(int here, int choice) {

	int &ret = dp[here][choice];
	if (ret != -1) return ret;

	ret = 0;

	//현재를 선택하는 거라면 가중치를 더해준다.
	if (choice == 1) ret += w[here];

	for (int i = 0; i < tree[here].size(); i++) {
		int there = tree[here][i];

		//현재를 선택한 정점이라면 다음 정점은 선택 안한다.
		if (choice == 1) {
			ret += sol(there, 0);
			nx[here][1].push_back(make_pair(there, 0));
		}
		else {

			//현재 정점을 선택하지 않았다면 다음 정점은 선택하거나
			//선택하지 않아도 된다.
			int a = sol(there, 0), b = sol(there, 1);
			if (a > b) {
				nx[here][0].push_back(make_pair(there, 0));
				ret += a;
			}
			else {
				nx[here][0].push_back(make_pair(there, 1));
				ret += b;
			}

		}
	}
	return ret;
}
//트리로 모델링한다.
void modeling(int here) {

	visited[here] = true;
	for (int i = 0; i < graph[here].size(); i++) {
		int there = graph[here][i];
		if (visited[there] == false) {
			modeling(there);
			tree[here].push_back(there);
		}
	}
}
void chase(int here, int choice) {

	//현재를 선택하는 거라면 s벡터에 넣어준다.
	if (choice) s.push_back(here);
	for (int i = 0; i < nx[here][choice].size(); i++) {
		int there = nx[here][choice][i].first;
		int nextch = nx[here][choice][i].second;
		chase(there, nextch);
	}
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	w.resize(n + 1);
	for (int i = 1; i <= n; i++)
		scanf("%d", &w[i]);

	while (scanf("%d%d", &a, &b) != EOF) {
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	modeling(1);
	vector<int> res;

	int maxx = max(sol(1, 0), sol(1, 1));

	if (maxx == sol(1, 0))
		chase(1, 0);
	else
		chase(1, 1);

	printf("%d\n", maxx);
	sort(s.begin(), s.end());
	for (int i = 0; i < s.size(); i++)
		printf("%d ", s[i]);
	printf("\n");
}