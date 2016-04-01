/*

ȫ������ �þ� ������ M�϶�, �� �����ȿ� ���� ū �������� ���⸦
����ϴ� �����̴�. �þ��� ������ ���� ��ġ���� �յڷ� Mĭ���� �̴�.

������ ��ġ���� �������� ���⸦ ��� multiset�� �̿��Ͽ� ������ �ִ´�.
���� ��ġ�� �Ǹ� �� ��ġ�� �������� ���⸦ �����ְ� ���� ��ġ �������� 
���⸦ �߰��Ѵ�. ����Ҷ��� multiset���� ���� ū ���� �̾� ����Ѵ�.

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

int n, m;
multiset<int> ms;
vector<int> v;

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d%d", &n, &m);
	v.resize(n);

	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	for (int i = 0; i < 2 * m - 1; i++) {
		if (i >= n) break;
		ms.insert(v[i]);
	}

	for (int i = m - 1; i < n - m + 1; i++) {

		//multiset���� ���� ū ��
		auto it = ms.end(); it--;
		printf("%d ", *it);

		//���� ��ġ�� �����ְ� ���� ��ġ�� �־��ش�.
		int pre = i - (m - 1), next = i + m;
		it = ms.lower_bound(v[pre]); ms.erase(it);
		if (next<n) ms.insert(v[next]);
	}
	printf("\n");


}