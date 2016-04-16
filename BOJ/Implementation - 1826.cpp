/*

마을에 도착해야 되는데 연료가 한정되어 있다. 이때, 각 주유소마다
위치가 있고, 채울 수 있는 연료의 양이 있을 때, 주유소에 들리는 횟수를
최소로 할 때, 이 들리는 횟수를 출력하는 문제

PQ를 이용하여, 해당 트럭이 거리 L까지 갈 수 있다면, L이하의 주유소는
모두 들릴 수 있다. 이 때, 가장 연료를 많이 채워주는 주유소부터 방문
한다고 하면 이 문제를 해결 할 수 있다.

*/

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

priority_queue<int> pq;
int n, a, b, l, p;
vector<pair<int, int > > v;
int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	//ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end());

	cin >> l >> p;

	int cnt = 0, idx = 0;

	//마을까지 가지 못했다면
	while (p<l) {

		if (idx != n) {
			//해당 거리보다 작은 주유소는 모두 방문
			while (v[idx].first <= p) {
				pq.push(v[idx].second);
				idx++;
				if (idx == n) break;
			}
		}
		//들릴 주유소가 없다
		if (pq.empty()) {
			cout << "-1" << endl;
			return 0;
		}
		//가장 연료가 많은 주유소를 방문
		p += pq.top();
		pq.pop();

		cnt++;
	}
	cout << cnt << endl;
}