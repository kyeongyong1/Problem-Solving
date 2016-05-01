/*

������ ���۰� �������� �־��� ��
� �� ������ �ٸ� �������� �ִ��� ���� 
�����ϰ� �ִ� ������ ����ϴ� ����

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
//first�� ����, end�� ��
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
	//�������� ���ؼ� ����
	sort(v.begin(), v.end());
	//������ ���ؼ� ����
	sort(d.begin(), d.end());


	for (int i = 0; i < v.size(); i++) {

		vector<pair<int, int> >::iterator st = lower_bound(d.begin(), d.end(), make_pair(v[i].second, -1));
		int to_idx = st - d.begin();

		vector<pair<int, int> >::iterator fr = lower_bound(d.begin(), d.end(), make_pair(v[i].first, -1));
		int fr_idx = fr - d.begin();

		long long cnt = 0;

		//������ �������� ������ ���Ϳ� ���ؼ�
		//�������� ������ ����.
		//������ ������ ���ؼ��� �����Ѵ�.
		for (int j = fr_idx; j < to_idx; j++) {
			//'�� ������'�� '���� ������'���� ũ�ٸ� �����ϴ� �����̴�.
			if (d[j].second > v[i].first)
				cnt++;
		}
		maxx = max(maxx, cnt);
	}
	cout << maxx << endl;
}