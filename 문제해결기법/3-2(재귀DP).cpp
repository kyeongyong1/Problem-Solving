//DP 기초 cc문제
//DP테이블 dp[i] -> i원을 만드는데 필요한 코인의 최소 갯수
//DP점화식 dp[i]=min(dp[i], dp[i-coin[j]]+1)

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

const int INF = 987654321;
int dp[10010], coin[510];

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	ios::sync_with_stdio(false);

	int t; cin >> t;
	while (t--)
	{
		int p, n;
		cin >> p >> n;
		p = 10000 - p;

		for (int i = 0; i < n; i++) cin >> coin[i];

		//가장 큰값으로 초기화
		for (int i = 0; i <= p; i++) dp[i] = INF;

		dp[0] = 0;
		for (int i = 1; i <= p; i++) {
			for (int j = 0; j < n; j++) {
				if (i - coin[j] < 0) break;
				dp[i] = min(dp[i], dp[i - coin[j]] + 1);
			}
		}
		if (dp[p] == INF) cout << "0" << endl;
		else cout << dp[p] << endl;
	}
}