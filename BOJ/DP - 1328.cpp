/*

dp[i][j][k] -> i개의 건물이 있고 왼쪽에서 j개 오른쪽에서 k개가
			   보이는 경우의 수

점화식
dp[i][j][k] = dp[i-1][j-1][k] + dp[i-1][j][k-1] + dp[i-1][j][k]*(n-2)
'전'의 정보로부터 '지금'의 정보를 구한다. 


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
const ll MOD = 1000000007;
const ll PLUS = 1000000;

int n, l, r;
ll dp[102][102][102];

ll sol(int idx, int left, int right) {

	if (idx <= 1) return 0;
	if (left == 0 || right == 0) return 0;
	if (left + right > idx + 1) return 0;
	if (idx == 2) {
		if (left == 2 && right == 1 || left == 1 && right == 2) return 1;
		else return 0;
	}

	ll &ret = dp[idx][left][right];
	if (ret != -1) return ret;

	ret = (sol(idx - 1, left - 1, right) % MOD + sol(idx - 1, left, right - 1) % MOD
		+ ((sol(idx - 1, left, right) % MOD)*(idx - 2)) % MOD) % MOD;

	return ret;
}

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	memset(dp, -1, sizeof(dp));

	dp[1][1][1] = 1;
	dp[2][2][1] = 1;
	dp[2][1][2] = 1;

	scanf("%d%d%d", &n, &l, &r);
	if (n == 1 && l == 1 && r == 1) printf("1\n");
	else printf("%lld\n", sol(n, l, r));
}