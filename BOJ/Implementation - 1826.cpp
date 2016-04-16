/*

������ �����ؾ� �Ǵµ� ���ᰡ �����Ǿ� �ִ�. �̶�, �� �����Ҹ���
��ġ�� �ְ�, ä�� �� �ִ� ������ ���� ���� ��, �����ҿ� �鸮�� Ƚ����
�ּҷ� �� ��, �� �鸮�� Ƚ���� ����ϴ� ����

PQ�� �̿��Ͽ�, �ش� Ʈ���� �Ÿ� L���� �� �� �ִٸ�, L������ �����Ҵ�
��� �鸱 �� �ִ�. �� ��, ���� ���Ḧ ���� ä���ִ� �����Һ��� �湮
�Ѵٰ� �ϸ� �� ������ �ذ� �� �� �ִ�.

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

	//�������� ���� ���ߴٸ�
	while (p<l) {

		if (idx != n) {
			//�ش� �Ÿ����� ���� �����Ҵ� ��� �湮
			while (v[idx].first <= p) {
				pq.push(v[idx].second);
				idx++;
				if (idx == n) break;
			}
		}
		//�鸱 �����Ұ� ����
		if (pq.empty()) {
			cout << "-1" << endl;
			return 0;
		}
		//���� ���ᰡ ���� �����Ҹ� �湮
		p += pq.top();
		pq.pop();

		cnt++;
	}
	cout << cnt << endl;
}