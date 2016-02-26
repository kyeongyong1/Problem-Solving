#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;

const int INF = 1200;

ll sol;
int m, n, x, y;
vector<pair<int, int> > v, d, u;

//좌표를 갖기 위한 구조체
class point
{
public:
	int x, y;
};
//'A'점을 찾기 위한 sort기준
bool aa(pair<int, int > a, pair<int, int > b) {
	if (a.first != b.first) return a.first > b.first;
	else return a.second < b.second;
}
//'B'점을 찾기 위한 sort기준
bool bb(pair<int, int > a, pair<int, int > b) {
	if (a.first != b.first) return a.first < b.first;
	else return a.second > b.second;
}
int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	ios::sync_with_stdio(false);

	cin >> m;
	while (m--) {
		cin >> n;

		v.clear(), u.clear(), d.clear();
		//모든 점을 포함할수 있는 가장 작은 직사각형의 왼쪽 아래 점의 좌표 -> minn
		//                                             오른족 위의 점의 좌표 -> maxx
		point A, B, minn, maxx;

		A.x = INF, A.y = 0, B.x = 0, B.y = INF;
		minn.x = INF, minn.y = INF;
		maxx.x = 0, maxx.y = 0;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;

			if (minn.x > x) minn.x = x; if (minn.y > y) minn.y = y;
			if (maxx.x < x) maxx.x = x; if (maxx.y < y) maxx.y = y;
			v.push_back(make_pair(x, y));
		}

		sort(v.begin(), v.end(), aa);
		A.x = v[v.size() - 1].first, A.y = v[v.size() - 1].second;
		v.pop_back();
		sort(v.begin(), v.end(), bb);
		B.x = v[v.size() - 1].first, B.y = v[v.size() - 1].second;
		v.pop_back();

		for (int i = 0; i < v.size(); i++) {
			//직선의 방정식 이용
			if (v[i].second*(B.x - A.x) >= ((B.y - A.y)*(v[i].first - A.x) + A.y*(B.x - A.x)))
				u.push_back(make_pair(v[i].first, v[i].second));
			else
				d.push_back(make_pair(v[i].first, v[i].second));
		}
		u.push_back(make_pair(A.x, A.y)); u.push_back(make_pair(B.x, B.y));
		d.push_back(make_pair(A.x, A.y)); d.push_back(make_pair(B.x, B.y));

		sol = 0;
		sort(u.begin(), u.end(), bb);
		sort(d.begin(), d.end(), bb);

		//삼각형을 사다리꼴의 '특수한' 경우라고 생각
		//삼각형 -> 사다리꼴 두 변의 길이 중 한 변의 길이가 0인 사다리꼴
		for (int i = 0; i < d.size() - 1; i++) {
			sol += ((d[i].second - minn.y) + (d[i + 1].second - minn.y))*(d[i + 1].first - d[i].first) * 10000;
		}
		for (int i = 0; i < u.size() - 1; i++) {
			sol += ((maxx.y - u[i].second) + (maxx.y - u[i + 1].second))*(u[i + 1].first - u[i].first) * 10000;
		}
		long long area = ((ll)maxx.x - (ll)minn.x)*((ll)maxx.y - (ll)minn.y);

		cout << area * 10000 - sol / 2 << endl;
	}
}
