/*

SCC(Strongly Connected Components) 강결합 컴포넌트
방향 그래프에서 정의된다.

두 정점 u와 v에 대해 양 방향으로 가는 경로가 모두 있을 때
두 정점은 같은 SCC에 속해 있다고 한다.

한 정점에 대해서 DFS를 돌려 스패닝 트리를 만드는데 이 때
이 스패닝 트리를 적절히 자르기만 하면 SCC를 분리할 수 있다.

1. v에서 u로 가는 경로가 없을 때 트리 간선 (u,v)를 자른다.
2. 교차 간선 중 SCC로 묶여있는 정점일 경우 교차 간선 (u,v)를 자른다.

*/

#include <algorithm>
#include <vector>  
#include <cstdio>
#include <stack>
#include <stdio.h>
using namespace std;

int v, e, a, b;
vector<int> graph[10010], p[10010], sccId, discovered;
int sccCounter, vertexCounter;
stack<int> st;

int scc(int here) {

	//here 정점의 발견 순서를 저장
	int ret = discovered[here] = vertexCounter++;
	//SCC로 묶기위한 stack, here의 후손들은 st에 들어간다.
	st.push(here);

	for (int i = 0; i < graph[here].size(); i++) {
		int there = graph[here][i];

		//방문하지 않았거나
		if (discovered[there] == -1)
			ret = min(ret, scc(there));
		//SCC로 묶여있지 않다면
		else if (sccId[there] == -1)
			ret = min(ret, discovered[there]);
	}
	//부모로 올라가는 간선이 없다면 SCC로 묶어준다.
	if (ret == discovered[here]) {
		while (true) {
			int t = st.top();
			st.pop();
			sccId[t] = sccCounter;
			//here정점까지 같은 SCC로 묶어준다.
			if (t == here) break;
		}
		sccCounter++;
	}
	return ret;
}

vector<int> tarjanSCC() {
	sccId = discovered = vector<int>(v + 1, -1);
	for (int i = 1; i <= v; i++) {
		if (discovered[i] == -1) scc(i);
	}
	return sccId;
}
int main() {

	scanf("%d%d", &v, &e);

	for (int i = 0; i < e; i++) {
		scanf("%d%d", &a, &b);
		graph[a].push_back(b);
	}
	vector<int> res = tarjanSCC();

	printf("%d\n", sccCounter);

	for (int i = 1; i < res.size(); i++) {
		p[res[i]].push_back(i);
	}
	for (int i = 1; i < res.size(); i++) {

		if (sccId[i] == -1) continue;
		int hereId = res[i];
		sccId[i] = -1;
		printf("%d ", i);

		sort(p[hereId].begin(), p[hereId].end());

		for (int j = 1; j < p[hereId].size(); j++) {
			printf("%d ", p[hereId][j]);
			sccId[p[hereId][j]] = -1;
		}
		printf("-1\n");
	}
}