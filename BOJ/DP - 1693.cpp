/*

트리의 각 정점을 색칠하려고 하는데, i(1<=i<=n) 번 색깔로 칠할 때에는
i번 만큼의 비용이 든다. 또 인접한 두 정점은 서로 다른 색깔로 칠해야 
한다고 할때 전체 정점들을 색칠하는데 드는 최소 비용을 구하는 문제

4가지 색만 있으면 모든 정점을 칠하는데 최소 비용을 구할 수 있다.
3가지 색만 쓰는 경우 한 가지 색을 더 이용해서 칠했을 때 최소인 경우가 있다.

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
#include <string>
#include <iostream>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const ll MOD = 1000000007;
const ll PLUS = 1000000;

int n, dp[100010][5], a, b;
vector<int> graph[100010], tree[100010], v;
bool visited[100010];
vector<pair<int, int > > vv;

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
int sol(int here, int color) {

	int &ret = dp[here][color];
	if (ret != -1) return ret;

	ret = color;
	int minn;

	for (int i = 0; i < tree[here].size(); i++) {
		int there = tree[here][i];

		minn = INF;
		//자식 정점을 4가지 색으로 칠하는 것 중
		//가장 작은 값을 구한다.
		for (int j = 1; j <= 4; j++) {
			if (j == color) continue;
			minn = min(minn, sol(there, j));
		}
		ret += minn;
	}
	return ret;
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	memset(dp, -1, sizeof(dp));

	scanf("%d", &n);


	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a, &b);
		v.push_back(a), v.push_back(b);
		vv.push_back(make_pair(a, b));
	}

	//좌표 압축을 해야 한다.
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < vv.size(); i++) {
		a = vv[i].first, b = vv[i].second;
		int aidx = lower_bound(v.begin(), v.end(), a) - v.begin();
		int bidx = lower_bound(v.begin(), v.end(), b) - v.begin();
		graph[aidx].push_back(bidx); graph[bidx].push_back(aidx);
	}

	//트리 형태로 모델링한다.
	modeling(1);

	//루트 정점을 1,2,3,4 번 각각 색깔로 칠할 때의 최소값 중
	//가장 작은 값이 답이다.
	int minn = min(sol(1, 1), sol(1, 2));
	minn = min(minn, sol(1, 3));
	minn = min(minn, sol(1, 4));
	printf("%d\n", minn);
}