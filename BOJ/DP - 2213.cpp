/*

�׷����� ������ �κ� ���� �߿��� �������� ���� �������� ������
�� �κ� ������ ���� �����̶�� �ϴµ� �̶� �ִ� ���� ������ ���ϴ� �����̴�.

������ ����ġ�� �־�����.

DP[i][j] i��° ���� ������ �� ������ ���� ������ (j==1)
Ȥ�� ���� ���� �ʾ����� (j==0) ����ġ ���� �ִ밪


nx[i][j] ���� ������ i���̰�, ���°� j�϶� ������° ���¸� pair������ ����
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

int n, a, b, dp[10010][2];
vector<int> w, graph[10010], tree[10010];
bool visited[10010];
vector<int> s;
vector<pair<int, int > > nx[10010][2];

int sol(int here, int choice) {

	int &ret = dp[here][choice];
	if (ret != -1) return ret;

	ret = 0;

	//���縦 �����ϴ� �Ŷ�� ����ġ�� �����ش�.
	if (choice == 1) ret += w[here];

	for (int i = 0; i < tree[here].size(); i++) {
		int there = tree[here][i];

		//���縦 ������ �����̶�� ���� ������ ���� ���Ѵ�.
		if (choice == 1) {
			ret += sol(there, 0);
			nx[here][1].push_back(make_pair(there, 0));
		}
		else {

			//���� ������ �������� �ʾҴٸ� ���� ������ �����ϰų�
			//�������� �ʾƵ� �ȴ�.
			int a = sol(there, 0), b = sol(there, 1);
			if (a > b) {
				nx[here][0].push_back(make_pair(there, 0));
				ret += a;
			}
			else {
				nx[here][0].push_back(make_pair(there, 1));
				ret += b;
			}

		}
	}
	return ret;
}
//Ʈ���� �𵨸��Ѵ�.
void modeling(int here) {

	visited[here] = true;
	for (int i = 0; i < graph[here].size(); i++) {
		int there = graph[here][i];
		if (visited[there] == false) {
			modeling(there);
			tree[here].push_back(there);
		}
	}
}
void chase(int here, int choice) {

	//���縦 �����ϴ� �Ŷ�� s���Ϳ� �־��ش�.
	if (choice) s.push_back(here);
	for (int i = 0; i < nx[here][choice].size(); i++) {
		int there = nx[here][choice][i].first;
		int nextch = nx[here][choice][i].second;
		chase(there, nextch);
	}
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	w.resize(n + 1);
	for (int i = 1; i <= n; i++)
		scanf("%d", &w[i]);

	while (scanf("%d%d", &a, &b) != EOF) {
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	modeling(1);
	vector<int> res;

	int maxx = max(sol(1, 0), sol(1, 1));

	if (maxx == sol(1, 0))
		chase(1, 0);
	else
		chase(1, 1);

	printf("%d\n", maxx);
	sort(s.begin(), s.end());
	for (int i = 0; i < s.size(); i++)
		printf("%d ", s[i]);
	printf("\n");
}