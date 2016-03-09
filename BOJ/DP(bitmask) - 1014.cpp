/*

DP(bitmask)

왼쪽 위부터 오른쪽으로 행 단위로 차례대로 학생을 배치 할 수
있는지 없는지에 대해 조사한다.

state에 대한 정의는 한 위치에 대하여 왼쪽부터 왼쪽위까지의 상태이다.
왼쪽이 최하위 비트인 0번째 비트가 되고 왼쪽위가 최상위 비트인 m번째 비트가 된다.
오른쪽위는 m-2번째 비트이다.

한 위치에 대해서 0번째비트, m-2번째비트, m번째비트가 안 켜져 있고, 앉을 수 있는 자리('.')
라면 현재 위치에 학생을 배치할 수 있다. DP함수는 이 자리에 배치했을 때와 이 자리에
배치하지 않았을 때의 최대값을 return하는 전형적인 함수이다.

다음 상태로 state를 넘겨줄때 최상위 비트인 m번째 비트는 꺼주고 왼쪽으로 쉬프트 시킨 후
해당 자리에 배치할때는 최하위 비트를 켜주고 아닐때에는 그대로 두고 다음 함수를 호출한다.

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

int m, n, c, dp[12][12][1 << 12];
char ch[12][12];

int sol(int row, int col, int state) {

	if (col == m) return sol(row + 1, 0, state);
	if (row == n) return 0;

	int &ret = dp[row][col][state];
	if (ret != -1) return ret;

	ret = 0;

	int Left = state&(1 << 0);
	int Ldiagonal = state&(1 << m), Rdiagonal = state&(1 << (m - 2));
	state &= ~(1 << m); state <<= 1;

	if (col == 0) {
		if (Rdiagonal || ch[row][col] == 'x')
			ret = sol(row, col + 1, state);
		else
			ret = max(sol(row, col + 1, state), sol(row, col + 1, state | 1) + 1);
	}
	else if (col == m - 1) {
		if (Ldiagonal || Left || ch[row][col] == 'x')
			ret = sol(row + 1, 0, state);
		else
			ret = max(sol(row + 1, 0, state), sol(row + 1, 0, state | 1) + 1);
	}
	else {
		if (Ldiagonal || Rdiagonal || Left || ch[row][col] == 'x')
			ret = sol(row, col + 1, state);
		else
			ret = max(sol(row, col + 1, state), sol(row, col + 1, state | 1) + 1);
	}
	return ret;
}
int main() {

	scanf("%d", &c);

	while (c--) {

		memset(dp, -1, sizeof(dp));

		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) {
			getchar();
			for (int j = 0; j < m; j++)
				scanf("%c", &ch[i][j]);
		}
		printf("%d\n", sol(0, 0, 0));
	}
}