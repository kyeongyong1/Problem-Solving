//Plane Sweeping
//'x��ǥ�� ���ؼ�' '��� y��ǥ'�� �����Ѵ�

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

// y�� y��ǥ ����, v�� �簢�� ����
// section�� y��ǥ ����, ps�� <x��ǥ, ��������������, �簢����ȣ>
vector<double> y;
vector<Rec> v;
vector<double> section;
vector< pair<double, pair<int, int > > > ps;

//���� �Լ�
void Sort()
{
	sort(ps.begin(), ps.end());
	sort(y.begin(), y.end());
	//y��ǥ�� �ߺ��� ��ǥ�� ����
	y.erase(unique(y.begin(), y.end()), y.end());
}
//���̸� ����ϴ� �Լ�
double Cal()
{
	//������ 1 ���� -1
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

		//�ش� line�� ������ �ִ� �簢���� y��ǥ
		double y1 = v[num].y1, y2 = v[num].y2;

		//������ update
		for (int j = 0; j < y.size(); j++)
		{
			if (y1 <= y[j] && y[j] < y2)
				section[j] += delta;
		}

		//������ŭ ���鼭 0���� ũ�ٸ� �� ������ �ش��ϴ�
		//���̸� �����ش�.
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

		//y��ǥ
		y.push_back(b);
		y.push_back(b + d);

	}
	cout << Cal() << endl;
}