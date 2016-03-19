/*

DP문제

새로운 아이디어를 받아들이기 위해서 자신이 얼리어답터이거나
자신의 친구 중 한명이 얼리어답터라면 가능하다.
모든 개인이 새로운 아이디어를 수용하기 위해서 필요한 최소
얼리어답터의 수를 구하는 문제

먼저 그래프 형태로 주어지는 data를 트리형태로 모델링한다.

DP[i][j] i까지 봤고, 이때 i가 얼리어답터이거나 (j==1) 
아닐 때 (j==0) 최소 얼리어답터의 수

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
#include <math.h>
#include <cstring>
using namespace std;

bool visited[1000010];
int n, u, v, dp[1000010][2];
vector< vector<int > > graph, node;

//트리 형태로 모델링
void dfs(int here) {

	visited[here] = true;

	for (int i = 0; i < graph[here].size(); i++) {
		int there = graph[here][i];

		if (visited[there] == true) continue;

		node[here].push_back(there);
		dfs(there);
	}
}
int sol(int here, bool ea) {

	int &ret = dp[here][ea];
	if (ret != -1) return ret;
	else if (node[here].empty()) return ret = ea ? 1 : 0;

	ret = 0;

	//자신이 얼리어답터라면
	if (ea == true) {
		//친구가 얼리어답터여도 되고 아니여도 된다.
		for (int i = 0; i < node[here].size(); i++) {
			int there = node[here][i];
			ret += min(sol(there, 0), sol(there, 1));
		}
		return ++ret;
	}
	else {
		//친구가 무조건 얼리어답터여야 된다.
		for (int i = 0; i < node[here].size(); i++) {
			int there = node[here][i];
			ret += sol(there, 1);
		}
		return ret;
	}
}

int main()
{

	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);

	node.resize(n + 1, vector<int>());
	graph.resize(n + 1, vector<int>());

	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d", &u, &v);
		graph[u].push_back(v), graph[v].push_back(u);
	}
	//트리형태로 모델링
	dfs(1);

	printf("%d \n", min(sol(1, 0), sol(1, 1)));
}