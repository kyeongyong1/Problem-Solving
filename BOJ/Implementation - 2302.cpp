/*

���� �¼��� ������, �������� m���� �ִ�.
�������� ������ ������ �¼����� �����̳� ���������� 1ĭ
�̵��Ͽ� �ٲ� ���� �� �ִ�. �̶� ������ ����� ���� ����ϴ� ����

�������� ���ٰ� ������ n���� ���� �� �ִ� ����� ���� 
�Ǻ���ġ ���� ���ǵȴ�.

�������� �������� ������ ����� ���� ���Ͽ� �ָ� �ȴ�.

*/

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>    
#include <cstdio>
#include <string>
#include <queue>
#include <limits.h>
#include <stack>
#include <set>
#include <math.h>
#include <cstring>
using namespace std;

typedef long long ll;

const int MOD = 1000000;
const int RETURN = 1061109567;
const int INF = 987654321;

int n, m, a;
ll dp[42];
vector<ll> v;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	//ios::sync_with_stdio(false);

	dp[0] = 1, dp[1] = 1, dp[2] = 2;
	for (int i = 1; i <= 40; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cin >> n >> m;

	v.push_back(0);
	for (int i = 0; i < m; i++) {
		cin >> a;
		v.push_back(a);
	}
	v.push_back(n + 1);

	ll sol = 1;

	for (int i = 1; i < v.size(); i++) {
		sol *= dp[v[i] - v[i - 1] - 1];
	}
	cout << sol << endl;
}