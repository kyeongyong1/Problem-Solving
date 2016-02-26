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

//num���� ���� ��(0<=��<pre)�� num�ڿ� ���̰�, v���Ϳ� push
void sol(ll num, ll pre) {

	for (int i = 0; i < pre; i++) {
		num *= 10;
		num += i;
		v.push_back(num);
		//'i'�� '�翬��' pre���� �۴�
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
