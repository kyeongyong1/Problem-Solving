#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

typedef long long ll;
vector<ll> v;

//num보다 작은 수(0<=수<pre)를 num뒤에 붙이고, v벡터에 push
void sol(ll num, ll pre) {

	for (int i = 0; i < pre; i++) {
		num *= 10;
		num += i;
		v.push_back(num);
		//'i'는 '당연히' pre보다 작다
		sol(num, i);
		//BackTracking
		num /= 10;
	}
}
int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	//ios::sync_with_stdio(false);

	for (int i = 0; i < 10; i++) {
		v.push_back(i);
		sol(i, i);
	}
	sort(v.begin(), v.end());

	int n; cin >> n;
	if (n >= v.size()) {
		cout << "-1" << endl;
		return 0;
	}
	cout << v[n] << endl;
}
