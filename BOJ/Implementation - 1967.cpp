/*

트리의 지름 중 가장 경로가 긴 트리의 지름을 출력하는 문제

*/


#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;

int n, mmax;
vector<pair<int, int > > graph[10010];

//here를 root로 하는 서브트리에서 자식노드를 서브트리의 루트로 하는 간선과
//here와 자식의 간선치를 더한 값 중 최댓값을 반환
int sol(int here) {

	int ret = 0;

	//here를 root로 하는 서브트리에서 자식노드를 서브트리의 루트로 하는 간선과
	//here와 자식의 간선치를 더한 값들의 집합
	vector<int> v;

	for (int i = 0; i < graph[here].size(); i++) {
		int there = graph[here][i].first, cost = graph[here][i].second;
		v.push_back(sol(there) + cost);
	}
	if (v.empty()) return 0;

	sort(v.begin(), v.end());
	//최댓값을 반환
	ret = v[v.size() - 1];

	//해당 here를 root로 하는 서브트리 중에서 트리의 지름이 나올 수 있는 후보이다.
	if (v.size() > 1)
		mmax = max(mmax, v[v.size() - 1] + v[v.size() - 2]);
	return ret;
}
int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b, c; cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
	}

	int res = sol(1);
	cout << max(res, mmax) << endl;
}