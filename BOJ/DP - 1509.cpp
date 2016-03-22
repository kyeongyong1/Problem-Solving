/*

DP[left][right] -> left, right ������ ������ ������ ������ �ּڰ��� ��ȯ

�̶�� dp���̺��� �����ϰ� �ڵ��� �����ߴµ� �ð��ʰ��� ����.
�Լ��ȿ��� left, right ���̿� ���� ��� ����� ���� ���� ��
�ּڰ��� �����Ͽ� ��ȯ���� �ִ� ������� �����Ͽ���.

DP[idx] -> idx���� ���� �� ������ ������ �ּڰ��� ��ȯ
i(<idx) �ε����� ���캸�µ� i+1���� idx���� �Ӹ�����̶��
i���� ������ ������ �ּڰ� + 1 �� ���־���
�Ӹ������ �ƴ϶�� 
i���� ������ ������ �ּڰ� + ������ �� �� ���־���.
�� �� �ּڰ��� �����Ͽ� ��ȯ�� �ִ� ������� �Լ��� �����Ͽ���.

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

	//�Ӹ�������� Ȯ���ϱ� ���� ��ó��
	for (int i = 0; i < lenSize; i++)
		for (int j = 0; j < lenSize; j++)
			ispossible(i, j);

	printf("%d\n", sol(lenSize - 1));
}