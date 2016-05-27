/*

징검다리를 건너는데 1번 돌을 시작으로 밟고 N번 돌을 끝으로 밟아야 한다.
돌마다 숫자가 쓰여 있는데 Trailing Zero를 최소로 하도록 돌을 밟아야 한다.

Trailing Zero란 밟는 돌의 곱을 했을때 뒤에 붙는 0의 개수이다.
즉 2400의 Trailing Zero의 개수는 2이고 25904는 0개이다.

최소로 해야 하기 때문에 '해당 돌을 밟았을 때의 2의 최솟값과
해당 돌을 밟았을 때의 5의 최솟값'을 구한 뒤 두 값 중
최소값이 원하는 값이 된다. 2와 5를 곱할때만 뒤에 0이 나오기 때문이다.

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