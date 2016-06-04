/*

���Ƹ� ���� �������� ����� a�� ������ ������ a��ŭ �����Ѵ�.
������� ���� ���谨�� ���Ƹ� ���� ������� ���� ���� ���Ƹ� ����
�������� b�̰� �ٳణ ����� c�� �̶�� �� ���谨�� b*c�� �ȴ�.

û�Ҵ� ���ῡ ��� ������� �ٳణ �Ŀ� �ϴµ�, û�Ҹ� �ϰ� ����
�������� 0�� �ȴ�. ��, N�� �߿� M���� �Ѵ�.

 DP ���� 
pos������ �־�� �� �� ���Ұ�, pos���� ������, '����' û���ߴ�����
���� ������ �־�� �� �� ���Ҵ�. û���� pos�� ���ؼ� ��Ʈ����ũ��
���������� N�� �ִ� 100�̶� ��Ʈ����ũ�� ����ϸ� ���̺��� ���ǵ���
�ʴ´�. ���� û���ߴ����� ���� ������ �˱� ����ٸ� ���� ��ġ����
������ ������ ���� ������ �ʿ��� �� ���Ҵ�. ��, û�� ��� �ߴ�����
���� ���������� �ʿ��ߴ�. 3���� ������ �ʿ��߰� �׿� ���� 
dp���̺��� �����ߴ�. 

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

int n, m, p, dp[105][2010][10];
vector<int> v;

int sol(int pos, int dirty, int scnt) {

	if (pos == n) {
		if (scnt == m) return 0;
		else return INF;
	}
	if (scnt > m) return INF;

	int &ret = dp[pos][dirty][scnt];
	if (ret != -1) return ret;

	//pos�ϳ� ���谨�� �����ش�.
	ret = v[pos] * dirty;

	int a = INF, b = INF;
	//û�Ҹ� �Ҽ��ִٸ�, û�Ҹ� �ϰ� dirty�� 0�̴�.
	if (scnt < m) a = sol(pos + 1, 0, scnt + 1);
	//û�Ҹ� ���Ѵٸ� �������� �����Ѵ�.
	b = sol(pos + 1, dirty + v[pos], scnt);

	ret += min(a, b);
	return ret;
}
//��� ���� �ϴ� �Լ�
void printL(int curSum, int pos, int dirty, int scnt) {

	//pos�Ͽ� ���� ���谨�� ����
	curSum -= v[pos] * dirty;

	if (pos == n - 1) {
		if (scnt == m - 1) printf("%d ", pos + 1);
		return;
	}
	//û�Ҹ� �� ���̺��� ���� ���̺� �� ���� ���谨 ����
	//���� ������ ��͸� ȣ���Ѵ�.
	if (curSum == dp[pos + 1][0][scnt + 1]) {
		printf("%d ", pos + 1);
		printL(curSum, pos + 1, 0, scnt + 1);
	}
	else
		printL(curSum, pos + 1, dirty + v[pos], scnt);
}
int main() {

	memset(dp, -1, sizeof(dp));

	scanf("%d %d", &n, &m);
	v.resize(n);

	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	int res = sol(0, 0, 0);
	printf("%d\n", res);
	printL(res, 0, 0, 0);
	printf("\n");
}