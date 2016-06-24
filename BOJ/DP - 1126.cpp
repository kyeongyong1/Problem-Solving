/*

블럭을 이용하여 두 개의 높이가 같은 탑을 만드려고 할때
탑의 높이의 최대값을 출력하는 문제

중복 계산 있을 거 같고, 모든 경우의 수 다 봐야될 거 같고...

dp[i][j] => i번째 블록을 사용하여 두 개의 탑을 만드는데
			두 개의 탑 '높이의 차이'


v는 블럭 높이를 가지고 있는 배열

한쪽의 높이를 더 키우거나
dp[i][j] = max(dp[i-1][j+v[j]], dp[i][j])

차이를 더 줄여주거나 
dp[i][j] = max(dp[i-1][j-v[j]], dp[i][j])

*/

#include <algorithm>
#include <vector>  
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <functional>
#include <set>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const ll MOD = 1000007;
const int MAX_SIZE = 10000010;
const int INF = 0x3f3f3f3f;

int n, maxx = -1, dp[2][500010];
vector<int> v;


int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	memset(dp, -1, sizeof(dp));

	scanf("%d", &n);
	v.resize(n);

	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	int m = 0;
	dp[0][0] = 0;

	for (int i = 0; i < n; i++) {
		m += v[i];

		memcpy(dp[1], dp[0], sizeof(dp[0]));

		for (int j = 0; j <= m; j++) {
			if (dp[1][j] >= 0) {
				int k = j + v[i];
				dp[0][k] = max(dp[0][k], dp[1][j] + v[i]);
				k = abs(j - v[i]);
				dp[0][k] = max(dp[0][k], dp[1][j] + v[i]);
			}
		}
	}
	if (dp[0][0] <= 0) printf("-1\n");
	else printf("%d\n", dp[0][0] >> 1);
}