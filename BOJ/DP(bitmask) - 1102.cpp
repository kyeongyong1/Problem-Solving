/*

���峪 �ִ� �����Ҹ� ��ġ�� ���ؼ��� ���� ���ư��� �ִ� �����Ҹ� �̿��ؼ�
���峪 �ִ� �����Ҹ� ��ĥ �� �ִ�. ��� p���� �����Ұ� ���峪 ����
�ʵ��� �� ��, �����Ҹ� ��ġ�� ����� �ּҰ��� ����ϴ� ����

arr[i][j] => i�� �����Ҹ� �̿��� j�� �����Ҹ� �����µ� ��� ���

dp[i] => ���� �����ִ� �����Ұ� i�� ��, (2������ ǥ�������� 1�� ��Ʈ�� �ڸ�����
		 �����Ұ� �����ִ�.) ��� ����� �ּҰ�


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
		//�����Ұ� �����ִٸ�
		if ((state & (1 << i)) == 0) {
			//�����ִ� �͵� �� �ּڰ�
			for (int j = 0; j < n; j++) {
				//j�����ҷ� i��° ������ Ű�ڴ�
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

	//�����ִ� �����ҿ� ���ؼ� ��Ʈ�� 1�� set
	for (int i = 0; i < sSize; i++)
		if (str[i] == 'Y') state |= (1 << i), sCnt++;

	int res = sol(state, sCnt);
	printf("%d\n", res == INF ? -1 : res);

}