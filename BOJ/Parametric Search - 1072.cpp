// x�� �ִ� 10���̹Ƿ�, �ð��ʰ�
// �� �� '������' ���ϴ� �˰����� �ʿ�
// �Ķ��Ʈ�� ��ġ, �̺� Ž���̶�� �Ѵ�.
// '��'�� ����ؼ� �ٿ������� ���
// logn�� ���ϴ� ���� ã�� �� �ִ�.

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

//s�� e�� ����� ���� '��'�� ���δ�.
ll sol(ll s, ll e) {

	//e�� s�� ���̰� 1���Ϸ� ���ٸ� 
	//���ϴ� ��
	if (e - s <= 1) return e;

	//c_mid���� ���ؼ� c_ratio�� ���Ѵ�.
	ll c_mid = (s + e) / 2;
	ll c_ratio = (y + c_mid) * 100 / (x + c_mid);

	//�Է¹��� ratio�� �� ũ�ų� ���ٸ� ���� ���� ���δ�.
	//�ƴ϶�� ���� ���� ���δ�.
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
