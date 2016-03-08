/*
����� ��ġ�� �־����� ����� ���� �� �ִ�
sprinkler�� ��ġ�� �־����µ� ���� �ȿ� �ִ� 
����� ��� ���� �� ������, �����ִ� �����
���� ����ϴ� ����

����� ���� 100,000 �̰� sprinkler�� ���� 20,000 �̴�.
�ϳ��� sprinkler�� ���ؼ� ��� ����� ���� �ȿ� �ִ���
Ȯ���Ѵٸ� TL�� ����.

sprinkler�� '���� �ȿ� ������' ����� �����Ѵ�.
map �ڷᱸ���� ����Ͽ� key���� ����� x�� value���� ����� y����
�� ������ �� '���� �ȿ� ������ x��(key��)'�� ���Ͽ� '���� �ȿ� ������
y��(value��)��'���� �����Ѵ�.
*/
#include <algorithm>
#include <functional>
#include <vector>
#include <map>    
#include <cstdio>
#include <queue>
#include <climits>
#include <stack>
#include <set>
#include <cmath>
#include <cstring>
#include <list>
using namespace std;

int g, x, m, r;
double y;
map<int, vector<double> > Hash;

int main() {

	scanf("%d", &g);
	for (int i = 0; i < g; i++) {
		scanf("%d%lf", &x, &y);
		Hash[x].push_back(y);
	}
	//���ϴ� y���� logn���� ã�� ���� �����Ѵ�.
	for (int i = 0; i <= 10000; i++)
		if (Hash.count(i) != 0)
			sort(Hash[i].begin(), Hash[i].end());

	int cnt = 0;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%lf%d", &x, &y, &r);

		//���� �ȿ� ������ x���� ã�´�.
		auto it = Hash.lower_bound(x - r);

		while (it != Hash.end() && (*it).first <= x + r) {
			
			if ((*it).first < x - r) {
				it++; continue;
			}

			int curX = (*it).first;
			double curY = y - sqrt(r*r - abs(curX - x)*abs(curX - x));
			double endY = y + sqrt(r*r - abs(curX - x)*abs(curX - x));

			//���� �ȿ� ������ y���� ã�´�.
			auto it2 = lower_bound(Hash[curX].begin(), Hash[curX].end(), curY);

			//x���� ���Ͽ� ��� y������ ���캻��.
			while (it2 != Hash[curX].end() && *it2 <= endY) {
				if (*it2 < curY) {
					it2++; continue;
				}
				cnt++; it2 = Hash[curX].erase(it2);
			}
			it++;
		}
		if (Hash.count(x) == 0)
			Hash.erase(x);
	}
	printf("%d\n", g - cnt);
}