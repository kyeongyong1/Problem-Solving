/*
DisjoinSet를 이용
최소 비용을 구하는 문제이므로 크루스칼 알고리즘을 이용하여 구한다.

n이 10만이므로 각각에 대해서 그래프 모델링을 
하게 되면 TL이 난다. 

n개에 대해서 x, y, z 좌표 각각에 대하여 정렬을 수행한 후
'인접'한 좌표들에 대하여 정점들을 이어 준다.
크루스칼 알고리즘 자체가 그리디인데 위 방법도 그리디하게
가중치가 적은 것만 보겠다는 의미

시간복잡도 O(nlogn)에 해결 가능
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

	//그래프 모델링
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