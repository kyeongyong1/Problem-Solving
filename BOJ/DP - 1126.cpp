/*

���� �̿��Ͽ� �� ���� ���̰� ���� ž�� ������� �Ҷ�
ž�� ������ �ִ밪�� ����ϴ� ����

�ߺ� ��� ���� �� ����, ��� ����� �� �� ���ߵ� �� ����...

dp[i][j] => i��° ����� ����Ͽ� �� ���� ž�� ����µ�
			�� ���� ž '������ ����'


v�� �� ���̸� ������ �ִ� �迭

������ ���̸� �� Ű��ų�
dp[i][j] = max(dp[i-1][j+v[j]], dp[i][j])

���̸� �� �ٿ��ְų� 
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