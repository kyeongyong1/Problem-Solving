/*

2���� �迭�� �־����µ� ���̾Ƹ�� ������ ���� ū ������
���ϴ� �����̴�.

dp[i][j][0] -> (i, j) ��ġ���� ���� �밢�� �Ʒ��������� 1�� ����
dp[i][j][1] -> (i, j) ��ġ���� ������ �밢�� �Ʒ��������� 1�� ����

���̾Ƹ�� ������ ũ�Ⱑ k+1�϶�
dp[i][j][0], dp[i+k][j+k][0], dp[i][j][1], dp[i+k][j-k][1] 
4�� �� �� ���� ���� ���� k+1���� ũ�ٸ� k+1�� ������ ũ�Ⱑ �����Ѵ�.

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

const int INF = 987654321;

//0 -> ���ʾƷ�, 1-> �����ʾƷ� 
int r, c, arr[753][753], dp[753][753][2];

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d %d", &r, &c);

	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			scanf("%1d", &arr[i][j]);

	for (int i = r; i >= 1; i--) {
		for (int j = c; j >= 1; j--) {
			if (arr[i][j] == 1) {
				dp[i][j][0] = dp[i + 1][j - 1][0] + 1;
				dp[i][j][1] = dp[i + 1][j + 1][1] + 1;
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (arr[i][j] == 0) continue;

			for (int k = ans; i + k <= r && j + k <= c && j - k >= 1; k++) {
				int res = min(dp[i][j][0], dp[i + k][j + k][0]);
				res = min(res, dp[i][j][1]);
				res = min(res, dp[i + k][j - k][1]);

				if (res >= k + 1) ans = k + 1;
			}
		}
	}
	printf("%d\n", ans);
}