/*

연속된 수들의 부분합 중에서 합이 S 이상이 되는 것 중,
가장 짧은 것의 길이를 출려하는 문제

psum을 이용한다. 초기화 시켜 놓고 i까지 인덱스까지의
합을 본다. s보다 크다면 psum[i]-s 보다 큰 가장 작은 값을
가진 인덱스를 psum에서 찾으면 우리가 구하고자 하는 길이를
O(nlogn)에 구현 할 수 있다.

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