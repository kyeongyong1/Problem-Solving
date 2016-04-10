/*

������ ���̱ⱸ�� ���� �ð��� ������ �ְ�, �� ���ִ� �� ����
���̴� ����ִ� ���̱ⱸ �� ��ȣ�� ���� ���̱ⱸ�� ž�� �Ѵٰ�
���� ��, �� �������� ���ִ� ���̰� Ÿ�ԵǴ� ���̱ⱸ�� ����ϴ� ����

��� ���̰� �� Ÿ�ԵǴ� �ð����� ���� �Ķ��Ʈ�� ��ġ�� �̿��Ͽ�
������ ���Ѵ�. ��� Ÿ�ԵǴ� �ּ� �ð��� ���ϰ� ������ ���̰�
��� ���̱ⱸ�� Ÿ���� ���Ѵ�.

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

typedef long long ll;

int n, m, a;
vector<int> v;

bool func(ll l) {

	//l�� �ð�, ����ð��� v[i]��� l/v[i] ��ŭ�� ���̰� ž�� �� �� �ִ�.
	ll cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		cnt += (l / v[i]) + 1;
	}
	return cnt >= (ll)n;
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; i++) {
		scanf("%d", &a);
		v.push_back(a);
	}
	ll lo = 0, hi = 2000000000LL * 10000LL;
	ll res = 2000000000LL * 10000LL;

	for (int i = 0; i < 100; i++) {
		ll mid = (lo + hi) / 2;

		if (func(mid)) {
			res = min(res, mid);
			hi = mid;
		}
		else {
			lo = mid;
		}
	}
	ll curCnt = 0;

	if (res == 0) {
		printf("%d\n", n); return 0;
	}
	//���������� Ÿ�� �Ǵ� ���̸� ���ϱ� ���� �ϳ� �� �ð����� ���Ѵ�.
	res--;
	for (int i = 0; i < m; i++) 
		curCnt += (res / v[i]) + 1;
	
	if (curCnt == n) {
		for (int i = m - 1; i >= 0; i--) {
			if (res%v[i] == 0) {
				printf("%d\n", i + 1); return 0;
			}
		}
	}
	res++;
	for (int i = 0; i < m; i++) {
		if (res%v[i] == 0)
			curCnt++;
		if (curCnt == n) {
			printf("%d\n", i + 1); return 0;
		}
	}

}