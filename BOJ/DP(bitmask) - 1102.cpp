/*

고장나 있는 발전소를 고치기 위해서는 현재 돌아가고 있는 발전소를 이용해서
고장나 있는 발전소를 고칠 수 있다. 적어도 p개의 발전소가 고장나 있지
않도록 할 때, 발전소를 고치는 비용의 최소값을 출력하는 문제

arr[i][j] => i번 발전소를 이용해 j번 발전소를 돌리는데 드는 비용

dp[i] => 현재 켜져있는 발전소가 i일 때, (2진수로 표현했을때 1인 비트의 자리수의
		 발전소가 켜져있다.) 드는 비용의 최소값


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
#include <tuple>
using namespace std;

typedef long long ll;

const int INF = 987654321;

int n, arr[17][17], p, dp[1 << 16];
char str[17];

int sol(int state, int cnt) {

	if (cnt >= p) return 0;

	int &ret = dp[state];
	if (ret != -1) return ret;

	ret = INF;
	for (int i = 0; i < n; i++) {
		//발전소가 꺼져있다면
		if ((state & (1 << i)) == 0) {
			//켜져있는 것들 중 최솟값
			for (int j = 0; j < n; j++) {
				//j발전소로 i번째 발전소 키겠다
				if (state & (1 << j))
					ret = min(ret, arr[j][i] + sol(state | (1 << i), cnt + 1));
			}
		}
	}
	return ret;

}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	memset(dp, -1, sizeof(dp));

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);

	scanf("%s %d", &str, &p);

	int sSize = strlen(str), state = 0, sCnt = 0;

	//켜져있는 발전소에 대해서 비트는 1로 set
	for (int i = 0; i < sSize; i++)
		if (str[i] == 'Y') state |= (1 << i), sCnt++;

	int res = sol(state, sCnt);
	printf("%d\n", res == INF ? -1 : res);

}