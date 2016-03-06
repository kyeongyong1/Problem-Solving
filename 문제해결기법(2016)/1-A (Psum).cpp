/*
������ �־����� ���� ���̿� ��� ��ĥ�� �Ѵ�.
k�� ��ĥ�� ������ ã�� �����̴�. 
�޸� ������ 2mb�̱� ������ 10,000,000���� 
�ܼ� �κ����� �̿��ϱ⿡�� ������ �ִ�.
�κ����� �� �ȶ��ϰ� ����Ͽ���.

���Ϳ� �������� ���������� �����Ͽ� �־��־�
2n���� ���� �κ����� ����Ͽ���.
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

int t, n, k, a, b;
vector<pair<int, int > > v;

int main() {

	scanf("%d", &t);

	while (t--) {
		scanf("%d%d", &n, &k);

		//�������� 1, ���������� -1
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &a, &b);
			v.push_back(make_pair(a, 1));
			v.push_back(make_pair(b + 1, -1));
		}
		sort(v.begin(), v.end());
		int cur = 0;
		vector<int> res;
		bool flag = false;
		for (int i = 0; i < v.size(); i++) {
			cur += v[i].second;

			//�����ϴ� ������ set�Ǿ� �ְ�, ���� ������ ��ĥ�� Ƚ����
			//k+1�̰ų� k-1�̶�� �� �� ���������� ������ �����̴�.
			if (abs(cur - k) == 1 && flag == true) {
				res.push_back(v[i].first - 1);
				flag = false;
			}
			//�����ϴ� ������ ã�´�.
			if (i != v.size() - 1 && v[i].first != v[i + 1].first && cur == k) {
				res.push_back(v[i].first);
				flag = true;
			}
		}
		//�����ϴ� ������ ������ ������ res�� ���ʴ�� �־��� ������
		//����Ҷ��� 2���� ����� �ش�.
		for (int i = 0; i < res.size(); i += 2) {
			printf("%d %d\n", res[i], res[i + 1]);
		}
		v.clear();
	}
}