//Plane Sweeping
//'x좌표에 대해서' '모든 y좌표'를 조사한다

#include <iostream>
#include <string>
#include <iomanip>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct Rec{
	double x1, y1, x2, y2;
};

// y는 y좌표 모음, v는 사각형 모음
// section은 y좌표 구간, ps는 <x좌표, 시작인지끝인지, 사각형번호>
vector<double> y;
vector<Rec> v;
vector<double> section;
vector< pair<double, pair<int, int > > > ps;

//정렬 함수
void Sort()
{
	sort(ps.begin(), ps.end());
	sort(y.begin(), y.end());
	//y좌표중 중복된 좌표를 제외
	y.erase(unique(y.begin(), y.end()), y.end());
}
//넓이를 계산하는 함수
double Cal()
{
	//시작은 1 끝은 -1
	for (int i = 0; i < v.size(); i++)
	{
		ps.push_back(make_pair(v[i].x1, make_pair(1, i)));
		ps.push_back(make_pair(v[i].x2, make_pair(-1, i)));
	}

	Sort();

	double ret = 0;
	section.resize(y.size() - 1, 0);

	for (int i = 0; i < ps.size() - 1; i++)
	{
		double line = ps[i].first;
		double nextline = ps[i + 1].first;
		int delta = ps[i].second.first;
		int num = ps[i].second.second;

		//해당 line을 가지고 있는 사각형의 y좌표
		double y1 = v[num].y1, y2 = v[num].y2;

		//구간을 update
		for (int j = 0; j < y.size(); j++)
		{
			if (y1 <= y[j] && y[j] < y2)
				section[j] += delta;
		}

		//구간만큼 돌면서 0보다 크다면 그 구간에 해당하는
		//넓이를 더해준다.
		for (int j = 0; j < section.size(); j++)
		{
			if (section[j] > 0)
				ret += (y[j + 1] - y[j])*(nextline - line);
		}
	}
	return ret;
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	ios::sync_with_stdio(false);

	int n; cin >> n;
	v.resize(n);

	for (int i = 0; i < n; i++)
	{
		double a, b, c, d;
		cin >> a >> b >> c >> d;
		v[i].x1 = a, v[i].y1 = b, v[i].x2 = a + c, v[i].y2 = b + d;

		//y좌표
		y.push_back(b);
		y.push_back(b + d);

	}
	cout << Cal() << endl;
}