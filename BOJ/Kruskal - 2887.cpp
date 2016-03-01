/*
DisjoinSet�� �̿�
�ּ� ����� ���ϴ� �����̹Ƿ� ũ�罺Į �˰����� �̿��Ͽ� ���Ѵ�.

n�� 10���̹Ƿ� ������ ���ؼ� �׷��� �𵨸��� 
�ϰ� �Ǹ� TL�� ����. 

n���� ���ؼ� x, y, z ��ǥ ������ ���Ͽ� ������ ������ ��
'����'�� ��ǥ�鿡 ���Ͽ� �������� �̾� �ش�.
ũ�罺Į �˰��� ��ü�� �׸����ε� �� ����� �׸����ϰ�
����ġ�� ���� �͸� ���ڴٴ� �ǹ�

�ð����⵵ O(nlogn)�� �ذ� ����
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

int n, a, b, c;

struct Data {
	int x, y, z;
	Data() {}
	Data(int a, int b, int c) {
		x = a, y = b, z = c;
	}
};
vector<Data> v;
vector<pair<pair<int, int >, int > > res;

struct DisjoinSet {
	vector<int> parent, rank;
	DisjoinSet() {}
	DisjoinSet(int n) {
		parent.resize(n), rank.resize(n);
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	int find(int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	void merge(int u, int v) {
		u = find(u), v = find(v);
		if (u == v) return;

		if (rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		if (rank[u] == rank[v]) rank[v]++;
	}
};
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &a, &b, &c);
		v.push_back(Data(a, b, c));
	}

	//�׷��� �𵨸�
	vector<pair<int, int > > s(n);
	
	for (int i = 0; i < n; i++)
		s[i].first = v[i].x, s[i].second = i;
	sort(s.begin(), s.end());
	for (int i = 1; i < s.size(); i++)
		res.push_back(make_pair(make_pair(abs(s[i - 1].first - s[i].first), s[i - 1].second), s[i].second));

	for (int i = 0; i < n; i++)
		s[i].first = v[i].y, s[i].second = i;
	sort(s.begin(), s.end());
	for (int i = 1; i < s.size(); i++)
		res.push_back(make_pair(make_pair(abs(s[i - 1].first - s[i].first), s[i - 1].second), s[i].second));

	for (int i = 0; i < n; i++)
		s[i].first = v[i].z, s[i].second = i;
	sort(s.begin(), s.end());
	for (int i = 1; i < s.size(); i++)
		res.push_back(make_pair(make_pair(abs(s[i - 1].first - s[i].first), s[i - 1].second), s[i].second));

	sort(res.begin(), res.end());

	DisjoinSet SP_tree(n);

	int ret = 0;
	for (int i = 0; i < res.size(); i++) {
		int cost = res[i].first.first;
		int u_idx = res[i].first.second;
		int v_idx = res[i].second;

		if (SP_tree.find(u_idx) == SP_tree.find(v_idx))
			continue;
		SP_tree.merge(u_idx, v_idx);
		ret += cost;
	}
	printf("%d\n", ret);
}