//partial sum, DP 아이디어 이용
//정사각형 형태로'만' 
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int main(void)
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	ios::sync_with_stdio(false);

	int m; cin >> m;

	while (m--) {
		//dp[i][j] -> (0,0) 을 왼쪽 위 꼭지점으로 하고 (i,j) 을 오른쪽 아래 꼭지점으로 
		//            하는 직사각형에 해당하는 지역의 이익
		int p, q, data[510][510], dp[510][510];
		memset(data, 0, sizeof(data));
		memset(dp, 0, sizeof(dp));
		cin >> p >> q;

		for (int i = 1; i <= p; i++) {
			for (int j = 1; j <= q; j++) {
				cin >> data[i][j];
				//dp테이블을 채운다.
				dp[i][j] = data[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
			}
		}

		int maxx = 0;

		//정사각형을 빠르게 구하는 알고리즘
		for (int i = 1; i <= p; i++) 
			for (int j = 1; j <= q; j++) 
				for (int k = 1; k < min(i, j); k++) 
					maxx = max(maxx, dp[i][j] - dp[i - k][j] - dp[i][j - k] + dp[i - k][j - k]);
		
		cout << maxx << endl;
	}
}