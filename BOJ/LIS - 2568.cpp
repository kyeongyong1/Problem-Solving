/*
A�������� ��ġ ������� ������ �Ѵ�.
������ ������ ���Ͽ� B�������� LIS�� ã���� �Ǵ� �����̴�.

n�� 100,000�̹Ƿ�, n^2 �ð����⵵�� ���� LIS �ڵ带 �ۼ��ϸ� TL�� ����.

nlogn �ð����⵵�� ���� ȿ������ LIS�̴�.
lis���ʹ� �� ���� ���� ���� ������ ���� �� �ִ� �ĺ��� ������ �ִ� �迭�̴�.
���� ���� ������ �̾Ƴ��� �ϴ� �����̹Ƿ�, parent���͸� �̿��Ͽ���.

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

int n;
vector<pair<int, int > > v;
bool visited[500001];

int main() {

	scanf("%d", &n);
	v.resize(n);
	vector<int> parent(500001, -1);

	for (int i = 0; i < n; i++)
		scanf("%d%d", &v[i].first, &v[i].second);
	//A������ ��ġ ��ȣ��� �����Ѵ�.
	sort(v.begin(), v.end());

	vector<int> lis;
	lis.push_back(v[0].second);

	for (int i = 1; i < n; i++) {
		if (lis.back() < v[i].second) {
			parent[v[i].second] = lis.back();
			lis.push_back(v[i].second);
		}
		else {
			auto it = lower_bound(lis.begin(), lis.end(), v[i].second);
			*it = v[i].second;
			if (it != lis.begin()) {
				parent[v[i].second] = *(--it);
			}
		}
	}
	printf("%d\n", n - lis.size());

	int cur = lis.back();
	for (int i = 0; i < lis.size(); i++) {
		visited[cur] = true;
		cur = parent[cur];
	}
	for (int i = 0; i < n; i++) {
		if (visited[v[i].second] == true) continue;
		printf("%d\n", v[i].first);
	}
}