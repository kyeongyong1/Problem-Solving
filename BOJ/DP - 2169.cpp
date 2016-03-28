/*

�κ��� ������ �� �迭���� ����, ������, �Ʒ������θ� �̵� �� �� ������
�̵��� �������� ��ġ�� ���� �ִ븦 ����ϴ� ����

�迭 (r,c)�� ���� ���� ���±��� �̵��� �������� ��ġ�� ����
������ ������((r-1,c)), ���ʿ��� ������((r,c-1)), �����ʿ��� ������((r,c+1))
3���� ��� �� ū���� �ȴ�.

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
		//���ʿ��� �� ���� ��� �� ������ ������ 3���� ����� ū ������ �����´�. 
		ret = max(sol(0, r - 1, c) + dat[r][c], sol(1, r - 1, c) + dat[r][c]);
		ret = max(ret, sol(2, r - 1, c) + dat[r][c]);
	}
	else if (s == 1) {
		//���ʿ��� �������� ������ ���ʿ��� �� ���̶� ���ʿ��� �� ���� �����ϴ�.
		ret = sol(1, r, c - 1) + dat[r][c];
		ret = max(ret, sol(0, r, c - 1) + dat[r][c]);
	}
	else {
		//�����ʿ��� �������� �������� �����ʿ��� �� ���̶� ���ʿ��� �� ���� �����Ѵ�.
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