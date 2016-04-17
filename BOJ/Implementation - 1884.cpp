/*

������ ������ �ְ�, ���θ��� ����ᰡ ���� ��, ������ ��������
1�� ���ÿ��� N�� ���ñ��� ���� �ִ� �̵��Ÿ��� ���ϴ� ����

dp[i][j] => i��° ������ �԰� ���� j���� ������ ������ �ּ� �̵� �Ÿ�
			�� �ΰ� dp�� ���� �� �� �ִ�.

pq�� �̿��Ͽ� 1�� �������� �����Ͽ� N�� �������� ���� ª�� �Ÿ� ���� ����.
��, ������ ������ �����Ƿ� �ش� ���θ� �̿��ϴ� ���� ������ �������� ����
�� �� ������ �ش� ���δ� �̿����� �ʴ´�.

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

int k, n, r, s, d, l, t;
vector<pair<pair<int, int >, int > > graph[110];

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d%d%d", &k, &n, &r);

	for (int i = 0; i < r; i++) {
		scanf("%d%d%d%d", &s, &d, &l, &t);
		graph[s].push_back(make_pair(make_pair(d, l), t));
	}

	priority_queue < pair < pair<int, int >, int > > pq;
	pq.push(make_pair(make_pair(0, 0), 1));

	while (!pq.empty()) {

		//l�� �Ÿ�, t�� ���
		l = -pq.top().first.first, t = pq.top().first.second;
		d = pq.top().second;

		pq.pop();

		if (d == n) break;

		for (int i = 0; i < graph[d].size(); i++) {
			int there = graph[d][i].first.first;
			int len = graph[d][i].first.second;
			int cost = graph[d][i].second;

			//�ش� ���θ� �̿��ϴ� ���� �������� ���� �� �� ������ pq�� �ִ´�.
			if (cost + t <= k)
				pq.push(make_pair(make_pair(-(l + len), t + cost), there));
		}
	}
	printf("%d\n", d == n ? l : -1);
}