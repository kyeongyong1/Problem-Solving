/*

구간의 시작과 끝구간이 주어질 때
어떤 한 구간이 다른 구간들을 최대한 많이 
포함하고 있는 개수를 출력하는 문제

*/

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <iomanip>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;

int n, a, b;
long long maxx = 0;
//first는 시작, end는 끝
vector<pair<int, int > > v;
vector<pair<int, int > > d;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back(make_pair(a, b));
		d.push_back(make_pair(b, a));
	}
	//시작점에 대해서 정렬
	sort(v.begin(), v.end());
	//끝점에 대해서 정렬
	sort(d.begin(), d.end());


	for (int i = 0; i < v.size(); i++) {

		vector<pair<int, int> >::iterator st = lower_bound(d.begin(), d.end(), make_pair(v[i].second, -1));
		int to_idx = st - d.begin();

		vector<pair<int, int> >::iterator fr = lower_bound(d.begin(), d.end(), make_pair(v[i].first, -1));
		int fr_idx = fr - d.begin();

		long long cnt = 0;

		//끝나는 지점으로 정렬한 벡터에 대해서
		//시작점과 끝점을 본다.
		//끝나는 지점에 대해서는 포함한다.
		for (int j = fr_idx; j < to_idx; j++) {
			//'그 시작점'이 '현재 시작점'보다 크다면 포함하는 구간이다.
			if (d[j].second > v[i].first)
				cnt++;
		}
		maxx = max(maxx, cnt);
	}
	cout << maxx << endl;
}