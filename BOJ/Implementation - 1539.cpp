/*

�Է� ���� ������ ���� �˻� Ʈ���� �𵨸� �Ҳ���, ������
���̸� �� ���� ���� ���ϴ� ����

�Է��� ���� ������ ������ ���� ���´�. �̹��� insert�� ����
���� ���ѳ��� �迭 �߿��� ���ĵ� ��ġ�� ����ϴ�.
��������� Ʈ���� ��������� ���� �� �� ���� ������ �� ���߿�
�Է¹��� �� ������ Ʈ���� ����� ���� �ȴ�.

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

typedef long long ll;

const int INF = 987654321;
const ll INFF = 987654321213;
const ll MOD = 987654321;
const ll PLUS = 1000000;

int n, height[250010], a;
set<pair<int, int > > ms;

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	ll sum = 0;

	scanf("%d%d", &n, &a);
	ms.insert(make_pair(a, 0));
	height[a] = 1;

	for (int i = 1; i < n; i++) {
		scanf("%d", &a);

		auto it = ms.lower_bound(make_pair(a, -1));

		//�� ó���̳� �� ���̶�� ã���� �ϴ� ���� �����ϴ�.
		if (it == ms.begin())
			height[a] = height[(*it).first] + 1;
		else if (it == ms.end())
			height[a] = height[(*(--it)).first] + 1;
		else {
			auto pre = (--it); it++;

			//���߿� �Է¹��� �ε����� ��忡 �ڽ����� �����Ѵ�.
			if (pre->second > it->second)
				height[a] = height[pre->first] + 1;
			else
				height[a] = height[it->first] + 1;
		}

		sum += (ll)height[a];
		ms.insert(make_pair(a, i));
	}
	printf("%lld\n", sum + 1);
}