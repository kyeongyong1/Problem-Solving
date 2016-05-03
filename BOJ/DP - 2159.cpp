/*

케익을 배달해야 하는데 배달 위치는 x,y 좌표가 주어진다. 이때 케익을 주기
위해서 그 좌표에 가거나 그 좌표에 상하좌우 인접한 위치까지 가야 배달을 할 수 있다.

이때 최단 거리를 출력하는 문제

dp[100010][5]
dp[i][j] => 현재 위치가 i이고 i-1번째 상태가 j에서 왔을 때 최소값

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
		
		//d는 '전'의 상태이다.
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