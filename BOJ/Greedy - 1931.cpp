/*

그리디 기법의 유명한 문제
회의의 시작 시간과 끝나는 시간이 주어질 때,
최대 사용할 수 있는 회의 수를 출력하는 문제

끝나는 시간이 빠른 회의를 선택하는 것이 현재 상황에서
최선의 선택이다. 

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