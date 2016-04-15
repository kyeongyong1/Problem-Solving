/*

���ӵ� ������ �κ��� �߿��� ���� S �̻��� �Ǵ� �� ��,
���� ª�� ���� ���̸� ����ϴ� ����

psum�� �̿��Ѵ�. �ʱ�ȭ ���� ���� i���� �ε���������
���� ����. s���� ũ�ٸ� psum[i]-s ���� ū ���� ���� ����
���� �ε����� psum���� ã���� �츮�� ���ϰ��� �ϴ� ���̸�
O(nlogn)�� ���� �� �� �ִ�.

*/

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
#include <math.h>
#include <cstring>
using namespace std;

const int INF = 987654321;
int n, s;
vector<int> num, ps;

int main()
{
	ios::sync_with_stdio(false);

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		num.push_back(a);
	}
	ps.resize(100010, INF);
	ps[0] = num[0];
	for (int i = 1; i < num.size(); i++)
		ps[i] = ps[i - 1] + num[i];

	int minn = INF;

	vector<int>::iterator it;
	for (int i = 0; i < n; i++) {
		if (ps[i] < s) continue;
		it = upper_bound(ps.begin(), ps.end(), ps[i] - s);
		minn = min(minn, i - (it - ps.begin() - 1));
	}
	if (minn == INF) minn = 0;
	cout << minn << endl;
}