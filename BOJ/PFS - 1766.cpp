/*

N���� ������ ��� Ǯ��� �Ǵµ�
�Է¿� ���� ���� Ǫ�� ������ ���� ������ �ְ�,
�� ��ȣ�� ������ �� ��ȣ�� �������� ���� Ǯ��� �ȴ�.

3���� ������ �����ϸ鼭 �������� Ǯ��� �ɶ� Ǯ ������
������ ����ϴ� �����̴�.

deg��� �迭�� �̿��Ͽ� �켱������ �����Ѵ�.
��, deg[i]�� i�� ������ Ǯ�� ���ؼ� ���� Ǯ��� ��
������ ���� �����Ͽ� deg[i]�� 0�� �ɶ��� ��μ� Ǯ �� �ְԲ� �Ѵ�.

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

int n, m, a, b;
vector<int> graph[32010];
int deg[32010];

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		graph[a].push_back(b);
		deg[b]++;
	}
	priority_queue<int> pq;

	//deg�� 0�� ������ Ǯ �� �ְ�, �� ��ȣ���� 
	//Ǯ��� �ǹǷ� pq�� �ִ´�.
	for (int i = 1; i <= n; i++)
		if (deg[i] == 0) pq.push(-i);

	while (!pq.empty()) {
		int here = -pq.top();
		pq.pop();
		printf("%d ", here);

		for (int i = 0; i < graph[here].size(); i++) {
			int there = graph[here][i];
			deg[there]--;
			//deg�� 0�̶�� �ش� ������ Ǯ �� �����Ƿ� pq�� �ִ´�.
			if (deg[there] == 0)
				pq.push(-there);
		}
	}
	printf("\n");
}