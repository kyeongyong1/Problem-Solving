/*

DP����

���ο� ���̵� �޾Ƶ��̱� ���ؼ� �ڽ��� �󸮾�����̰ų�
�ڽ��� ģ�� �� �Ѹ��� �󸮾���Ͷ�� �����ϴ�.
��� ������ ���ο� ���̵� �����ϱ� ���ؼ� �ʿ��� �ּ�
�󸮾������ ���� ���ϴ� ����

���� �׷��� ���·� �־����� data�� Ʈ�����·� �𵨸��Ѵ�.

DP[i][j] i���� �ð�, �̶� i�� �󸮾�����̰ų� (j==1) 
�ƴ� �� (j==0) �ּ� �󸮾������ ��

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

//Ʈ�� ���·� �𵨸�
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

	//�ڽ��� �󸮾���Ͷ��
	if (ea == true) {
		//ģ���� �󸮾���Ϳ��� �ǰ� �ƴϿ��� �ȴ�.
		for (int i = 0; i < node[here].size(); i++) {
			int there = node[here][i];
			ret += min(sol(there, 0), sol(there, 1));
		}
		return ++ret;
	}
	else {
		//ģ���� ������ �󸮾���Ϳ��� �ȴ�.
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
	//Ʈ�����·� �𵨸�
	dfs(1);

	printf("%d \n", min(sol(1, 0), sol(1, 1)));
}