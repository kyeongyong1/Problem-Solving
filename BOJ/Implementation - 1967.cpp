/*

Ʈ���� ���� �� ���� ��ΰ� �� Ʈ���� ������ ����ϴ� ����

*/


#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;

int n, mmax;
vector<pair<int, int > > graph[10010];

//here�� root�� �ϴ� ����Ʈ������ �ڽĳ�带 ����Ʈ���� ��Ʈ�� �ϴ� ������
//here�� �ڽ��� ����ġ�� ���� �� �� �ִ��� ��ȯ
int sol(int here) {

	int ret = 0;

	//here�� root�� �ϴ� ����Ʈ������ �ڽĳ�带 ����Ʈ���� ��Ʈ�� �ϴ� ������
	//here�� �ڽ��� ����ġ�� ���� ������ ����
	vector<int> v;

	for (int i = 0; i < graph[here].size(); i++) {
		int there = graph[here][i].first, cost = graph[here][i].second;
		v.push_back(sol(there) + cost);
	}
	if (v.empty()) return 0;

	sort(v.begin(), v.end());
	//�ִ��� ��ȯ
	ret = v[v.size() - 1];

	//�ش� here�� root�� �ϴ� ����Ʈ�� �߿��� Ʈ���� ������ ���� �� �ִ� �ĺ��̴�.
	if (v.size() > 1)
		mmax = max(mmax, v[v.size() - 1] + v[v.size() - 2]);
	return ret;
}
int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b, c; cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
	}

	int res = sol(1);
	cout << max(res, mmax) << endl;
}