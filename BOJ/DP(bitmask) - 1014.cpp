/*

DP(bitmask)

���� ������ ���������� �� ������ ���ʴ�� �л��� ��ġ �� ��
�ִ��� �������� ���� �����Ѵ�.

state�� ���� ���Ǵ� �� ��ġ�� ���Ͽ� ���ʺ��� ������������ �����̴�.
������ ������ ��Ʈ�� 0��° ��Ʈ�� �ǰ� �������� �ֻ��� ��Ʈ�� m��° ��Ʈ�� �ȴ�.
���������� m-2��° ��Ʈ�̴�.

�� ��ġ�� ���ؼ� 0��°��Ʈ, m-2��°��Ʈ, m��°��Ʈ�� �� ���� �ְ�, ���� �� �ִ� �ڸ�('.')
��� ���� ��ġ�� �л��� ��ġ�� �� �ִ�. DP�Լ��� �� �ڸ��� ��ġ���� ���� �� �ڸ���
��ġ���� �ʾ��� ���� �ִ밪�� return�ϴ� �������� �Լ��̴�.

���� ���·� state�� �Ѱ��ٶ� �ֻ��� ��Ʈ�� m��° ��Ʈ�� ���ְ� �������� ����Ʈ ��Ų ��
�ش� �ڸ��� ��ġ�Ҷ��� ������ ��Ʈ�� ���ְ� �ƴҶ����� �״�� �ΰ� ���� �Լ��� ȣ���Ѵ�.

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