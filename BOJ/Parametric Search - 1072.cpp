// x가 최대 10억이므로, 시간초과
// 좀 더 '빠르게' 구하는 알고리즘이 필요
// 파라메트릭 서치, 이분 탐색이라고도 한다.
// '반'을 계속해서 줄여나가는 방식
// logn에 원하는 답을 찾을 수 있다.

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <math.h>
#include <cstring>
using namespace std;

const int INF = numeric_limits<int>::max();
typedef long long ll;

ll x, y, ratio;

//s와 e의 가운데를 보고 '반'씩 줄인다.
ll sol(ll s, ll e) {

	//e와 s의 차이가 1이하로 난다면 
	//원하는 답
	if (e - s <= 1) return e;

	//c_mid값에 대해서 c_ratio를 구한다.
	ll c_mid = (s + e) / 2;
	ll c_ratio = (y + c_mid) * 100 / (x + c_mid);

	//입력받은 ratio가 더 크거나 같다면 앞의 반을 줄인다.
	//아니라면 뒤의 반을 줄인다.
	if (ratio >= c_ratio) return sol(c_mid, e);
	else return sol(s, c_mid);
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	//ios::sync_with_stdio(false);

	while (cin >> x >> y) {

		ratio = y * 100 / x;

		ll ret = sol(0, INF);
		if (ret == INF) cout << "-1" << endl;
		else cout << ret << endl;

	}
}
