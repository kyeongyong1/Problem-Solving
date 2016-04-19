/*

�׸��� ����� ������ ����
ȸ���� ���� �ð��� ������ �ð��� �־��� ��,
�ִ� ����� �� �ִ� ȸ�� ���� ����ϴ� ����

������ �ð��� ���� ȸ�Ǹ� �����ϴ� ���� ���� ��Ȳ����
�ּ��� �����̴�. 

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

int main()
{

	ios::sync_with_stdio(false);

	int t; cin >> t;

	vector<pair<int, int> > v;
	while (t--) {
		int st, en;
		cin >> st >> en;
		v.push_back(make_pair(en, st));
	}
	sort(v.begin(), v.end());

	int cnt = 1;
	int pre = v[0].first;
	for (int i = 1; i < v.size(); i++) {
		if (v[i].second >= pre) {
			cnt++;
			pre = v[i].first;
		}
	}
	cout << cnt << endl;
}