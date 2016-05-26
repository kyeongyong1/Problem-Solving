/*

���� ¥�� �Ǵµ� ���� �� ¥���� ������ �ִ밪�� ����ϴ� �����̴�.
������ ���� �� ¥���� ������ ���� ���� ���ϰ� �� �л����� ���� ���� ������
���� ���� ������ ���̰� �ȴ�. �Ѹ����� ���� ������ ��쿡�� �� ���� �� ¥����
������ 0�� �ȴ�. ��ü������ ���� �� ¥���� ������ ������ ���� �� ¥���� ������
������ ��Ÿ����.

dp[i] => i+1 ����� ���� ��¥���� ������ �ִ밪

dp[i] = dp[i-k] + ((i-k+1 ~ i) �� �ִ� ������ �ּ� ������ ����) (��, 1<=k<=i ) 
*/

#include <algorithm>
#include <vector>  
#include <cstdio>
#include <cstring>
using namespace std;

const int INF = 987654321;
int n, a, dp[1010];
vector<int> v;
int sol(int idx) {
	
	int &ret = dp[idx];
	if (ret != -1) return ret;
	
	int minn = INF, maxx = -INF;
	ret = 0;
	
	for (int i = idx - 1; i >= 0; i--) {
		minn = min(minn, v[i]), maxx = max(maxx, v[i]);
		ret = max(ret, sol(i) + maxx - minn);
	}
	
	return ret;
}
int main() {

	memset(dp, -1, sizeof(dp));
	
	scanf("%d", &n);
	v.resize(n);
	
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	printf("%d\n", sol(n));

}