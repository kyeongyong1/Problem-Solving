/*

DP[left][right] -> left, right 범위를 가지는 분할의 개수의 최솟값을 반환

이라고 dp테이블을 정의하고 코딩을 시작했는데 시간초과가 났다.
함수안에는 left, right 사이에 대한 모든 경우의 수를 구한 뒤
최솟값을 갱신하여 반환시켜 주는 방식으로 구현하였다.

DP[idx] -> idx까지 봤을 때 분할의 개수의 최솟값을 반환
i(<idx) 인덱스를 살펴보는데 i+1부터 idx까지 팰린드롬이라면
i까지 분할의 개수의 최솟값 + 1 을 해주었고
팰린드롬이 아니라면 
i까지 분할의 개수의 최솟값 + 문자의 수 를 해주었다.
그 중 최솟값을 갱신하여 반환해 주는 방식으로 함수를 구현하였다.

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

int n, lenSize, dp[2510], dp2[2510][2510];
char str[2510];

bool ispossible(int left, int right) {

	int &ret = dp2[left][right];
	if (ret != -1) return ret;

	if (left >= right) return ret = true;

	if (str[left] == str[right])
		return ret = ispossible(left + 1, right - 1);
	return ret = false;
}
int sol(int idx) {

	if (idx == -1) return 0;

	int &ret = dp[idx];
	if (ret != -1) return ret;

	ret = INF;
	for (int i = -1; i < idx; i++) {
		if (dp2[i + 1][idx] == 1)
			ret = min(ret, sol(i) + 1);
		else
			ret = min(ret, sol(i) + idx - i + 1);
	}
	return ret == INF ? 1 : ret;
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	memset(dp, -1, sizeof(dp));
	memset(dp2, -1, sizeof(dp2));

	scanf("%s", &str);
	lenSize = strlen(str);

	//팰린드롬인지 확인하기 위한 전처리
	for (int i = 0; i < lenSize; i++)
		for (int j = 0; j < lenSize; j++)
			ispossible(i, j);

	printf("%d\n", sol(lenSize - 1));
}