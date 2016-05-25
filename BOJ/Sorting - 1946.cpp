/*

ȸ�翡�� ����� ä���ϴµ�, ������ ����� 1�� ����� 2�� ������ ġ���� �ȴ�.
������ ������ ġ���� 1�� ���� N�� ���� ������ ���� �����ȴ�.
�� ��, �ٸ� ��� �����ڿ� ������ �� 1�� ����� 2�� ���� ���� �� ��� �ϳ���
�ٸ� �����ں��� �������� �ʴ� �ڸ� �����Ѵٴ� ��Ģ�� ������.
�� �� ������ �� �ִ� �ִ� ���Ի���� ���� ������ ����ϴ� ����

�Ųٷ� �����Ͽ� �����ؼ��� �ȵǴ� ���Ի���� ���� ����Ͽ���.
�����ؼ��� �ȵǴ� ����̶� 1�� ����� 2�� ���� ������ ��� '� ������' ����
���� ���� ����̴�. 1�� ���� ������ ���� ������� �����Ѵ�. 1�� ���� ������
���� �������� ���� �������� ���ʴ�� �� �ǵ�, �� �� ���� ������ �ϴ� �����
2�� ���� ������ ���� ���� �ô� ���� ������ ���� 2�� ���� ���� ���� ���� �ʴٸ�
���� ���� �ִ� ����� �����ؼ��� �ȵȴ�. �ֳ��ϸ� 1�� ���� ������� ���� �߱� ������
1�� ���� ������ ���� �ô� ������� ���� ���� ���̱� �����̴�.

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

int t, n, a, b;

int main() {

	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);
		vector<pair<int, int > > v;

		for (int i = 0; i < n; i++) {
			scanf("%d%d", &a, &b);
			v.push_back(make_pair(a, b));
		}
		sort(v.begin(), v.end());

		int minn = v[0].second;
		int cnt = 0;
		for (int i = 1; i < v.size(); i++) {
			if (minn < v[i].second) 
				cnt++;
			minn = min(minn, v[i].second);
		}
		printf("%d\n", n - cnt);
	}
}