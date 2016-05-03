/*

������ ����ؾ� �ϴµ� ��� ��ġ�� x,y ��ǥ�� �־�����. �̶� ������ �ֱ�
���ؼ� �� ��ǥ�� ���ų� �� ��ǥ�� �����¿� ������ ��ġ���� ���� ����� �� �� �ִ�.

�̶� �ִ� �Ÿ��� ����ϴ� ����

dp[100010][5]
dp[i][j] => ���� ��ġ�� i�̰� i-1��° ���°� j���� ���� �� �ּҰ�

*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <vector>
#include <stdlib.h>

using namespace std;

typedef long long ll;

const ll INF = 98765432123456LL;

vector<pair<ll, ll > > v;
ll n, a, b, dp[100010][5];

ll dr[5] = { 0, 1,0,-1,0 };
ll dc[5] = { 0, 0,1,0,-1 };

ll cal(pair<ll, ll> a, pair<ll, ll > b) {

	return abs(a.first - b.first) + abs(a.second - b.second);
}

ll sol(ll pos, ll d) {

	if (pos == n + 1) return 0;

	ll &ret = dp[pos][d];
	if (ret != -1) return ret;

	ret = INF;

	for (ll i = 1; i <= 4; i++) {
		pair<ll, ll > temp = v[pos];

		temp.first += dr[i], temp.second += dc[i];
		
		//d�� '��'�� �����̴�.
		ret = min(ret, cal(temp, 
			make_pair(v[pos - 1].first + dr[d], v[pos - 1].second + dc[d]))
			+ sol(pos + 1, i));
	}

	return ret;
}


int main() {

	memset(dp, -1, sizeof(dp));

	cin >> n;

	for (ll i = 0; i <= n; i++) {
		cin >> b >> a;
		v.push_back(make_pair(a, b));
	}

	ll min = INF;
	cout << sol(1, 0) << endl;
}