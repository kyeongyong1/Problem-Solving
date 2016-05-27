/*

¡�˴ٸ��� �ǳʴµ� 1�� ���� �������� ��� N�� ���� ������ ��ƾ� �Ѵ�.
������ ���ڰ� ���� �ִµ� Trailing Zero�� �ּҷ� �ϵ��� ���� ��ƾ� �Ѵ�.

Trailing Zero�� ��� ���� ���� ������ �ڿ� �ٴ� 0�� �����̴�.
�� 2400�� Trailing Zero�� ������ 2�̰� 25904�� 0���̴�.

�ּҷ� �ؾ� �ϱ� ������ '�ش� ���� ����� ���� 2�� �ּڰ���
�ش� ���� ����� ���� 5�� �ּڰ�'�� ���� �� �� �� ��
�ּҰ��� ���ϴ� ���� �ȴ�. 2�� 5�� ���Ҷ��� �ڿ� 0�� ������ �����̴�.

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

typedef long long ll;
const int MOD = 100000;
const int MAX_SIZE = 10000010;

int t, n, k, dp2[100010], dp5[100010];
vector<int> v;

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d", &t);

	while (t--) {

		memset(dp2, 0x3f, sizeof(dp2));
		memset(dp5, 0x3f, sizeof(dp5));
		dp2[0] = 0, dp5[0] = 0;

		scanf("%d %d", &n, &k);
		v.resize(n);
		for (int i = 0; i < n; i++)
			scanf("%d", &v[i]);
		vector<int> temp = v;

		for (int i = 0; i < n; i++) {
			int cnt = 0;
			while (temp[i] % 2 == 0)
				temp[i] /= 2, cnt++;

			if (i < k)
				dp2[i] = dp2[0] + cnt;
			else
				for (int j = i - k; j < i; j++)
					dp2[i] = min(dp2[i], dp2[j] + cnt);
		}

		temp = v;

		for (int i = 0; i < n; i++) {
			int cnt = 0;
			while (temp[i] % 5 == 0)
				temp[i] /= 5, cnt++;

			if (i < k)
				dp5[i] = dp5[0] + cnt;
			else
				for (int j = i - k; j < i; j++)
					dp5[i] = min(dp5[i], dp5[j] + cnt);

		}
		printf("%d\n", min(dp2[n - 1], dp5[n - 1]));
	}
}