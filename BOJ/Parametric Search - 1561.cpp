/*

각각의 놀이기구는 운행 시간이 정해져 있고, 줄 서있는 맨 앞의
아이는 비어있는 놀이기구 중 번호가 작은 놀이기구를 탑승 한다고
했을 때, 맨 마지막에 서있는 아이가 타게되는 놀이기구를 출력하는 문제

모든 아이가 다 타게되는 시간부터 먼저 파라메트릭 서치를 이용하여
빠르게 구한다. 모두 타게되는 최소 시간을 구하고 마지막 아이가
어느 놀이기구를 타는지 구한다.

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

	//l은 시간, 운행시간이 v[i]라면 l/v[i] 만큼의 아이가 탑승 할 수 있다.
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
	//마지막으로 타게 되는 아이를 구하기 위해 하나 뺀 시간부터 구한다.
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