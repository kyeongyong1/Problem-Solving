/*

dp[i] -> i거리 까지 가는데 최소 거리

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
const ll MOD = 1000000000;
const ll PLUS = 1000000;

struct inf {
	int s, e, l;
	inf() {}
	inf(int a, int b, int c) {
		s = a, e = b, l = c;
	}
};
int n, d, a, b, c, dp[10010];
vector<inf> v;

bool cmp(inf a, inf b) {
	if (a.e != b.e) return a.e < b.e;
	else return a.s < b.s;
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d%d", &n, &d);

	for (int i = 0; i <= d; i++)
		dp[i] = i;

	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &a, &b, &c);
		v.push_back(inf(a, b, c));
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		a = v[i].s, b = v[i].e, c = v[i].l;

		for (int i = 1; i <= a; i++)
			dp[i] = min(dp[i], dp[i - 1] + 1);

		dp[b] = min(dp[b], dp[a] + c);

	}
	for (int i = 1; i <= d; i++)
		dp[i] = min(dp[i], dp[i - 1] + 1);
	printf("%d\n", dp[d]);
}