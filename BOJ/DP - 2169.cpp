/*

로봇이 움직일 때 배열에서 왼쪽, 오른쪽, 아래쪽으로만 이동 할 수 있을때
이동한 지역들의 가치의 합이 최대를 출력하는 문제

배열 (r,c)에 왔을 때의 여태까지 이동한 지역들의 가치의 합은
위에서 왔을때((r-1,c)), 왼쪽에서 왔을때((r,c-1)), 오른쪽에서 왔을때((r,c+1))
3가지 경우 중 큰값이 된다.

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

const int INF = 987654321;

int n, m, dp[3][1010][1010], dat[1010][1010];

//s -> 0 : up, 1 : left, 2 : right
int sol(int s, int r, int c) {

	if (r == 1 && c == 1) return dat[r][c];
	if (r < 1 || c < 1 || c > m) {
		return -INF;
	}
	int &ret = dp[s][r][c];
	if (ret != -1) return ret;

	if (s == 0) {
		//위쪽에서 온 값을 계산 할 때에는 위쪽의 3가지 경우중 큰 값으로 가져온다. 
		ret = max(sol(0, r - 1, c) + dat[r][c], sol(1, r - 1, c) + dat[r][c]);
		ret = max(ret, sol(2, r - 1, c) + dat[r][c]);
	}
	else if (s == 1) {
		//왼쪽에서 왔을때는 왼쪽의 왼쪽에서 온 값이랑 위쪽에서 온 값만 가능하다.
		ret = sol(1, r, c - 1) + dat[r][c];
		ret = max(ret, sol(0, r, c - 1) + dat[r][c]);
	}
	else {
		//오른쪽에서 왔을때는 오른쪽의 오른쪽에서 온 값이랑 위쪽에서 온 값만 가능한다.
		ret = sol(2, r, c + 1) + dat[r][c];
		ret = max(ret, sol(0, r, c + 1) + dat[r][c]);
	}
	return ret;
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	memset(dp, -1, sizeof(dp));

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &dat[i][j]);

	printf("%d\n", max(sol(0, n, m), max(sol(1, n, m), sol(2, n, m))));

}