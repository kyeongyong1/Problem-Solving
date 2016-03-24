/*

SCC(Strongly Connected Components) ������ ������Ʈ
���� �׷������� ���ǵȴ�.

�� ���� u�� v�� ���� �� �������� ���� ��ΰ� ��� ���� ��
�� ������ ���� SCC�� ���� �ִٰ� �Ѵ�.

�� ������ ���ؼ� DFS�� ���� ���д� Ʈ���� ����µ� �� ��
�� ���д� Ʈ���� ������ �ڸ��⸸ �ϸ� SCC�� �и��� �� �ִ�.

1. v���� u�� ���� ��ΰ� ���� �� Ʈ�� ���� (u,v)�� �ڸ���.
2. ���� ���� �� SCC�� �����ִ� ������ ��� ���� ���� (u,v)�� �ڸ���.

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

	//here ������ �߰� ������ ����
	int ret = discovered[here] = vertexCounter++;
	//SCC�� �������� stack, here�� �ļյ��� st�� ����.
	st.push(here);

	for (int i = 0; i < graph[here].size(); i++) {
		int there = graph[here][i];

		//�湮���� �ʾҰų�
		if (discovered[there] == -1)
			ret = min(ret, scc(there));
		//SCC�� �������� �ʴٸ�
		else if (sccId[there] == -1)
			ret = min(ret, discovered[there]);
	}
	//�θ�� �ö󰡴� ������ ���ٸ� SCC�� �����ش�.
	if (ret == discovered[here]) {
		while (true) {
			int t = st.top();
			st.pop();
			sccId[t] = sccCounter;
			//here�������� ���� SCC�� �����ش�.
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