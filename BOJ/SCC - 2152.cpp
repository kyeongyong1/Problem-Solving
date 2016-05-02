/*

S�� ���ÿ��� T�� ���÷� �̵��� ��, 
�湮�� �� �ִ� �ִ� ���ø� ����ϴ� ����
��, �װ��δ� ������ �̿��� ���� �ְ�, ���� ���ø�
������ �湮�� �� �ִµ� 1���� ����.

�׷����� �𵨸��� �� �� SCC�� �����ش�. �̶� �� ���ÿ���
�ٸ� ���÷� �̵��� ��, �ٸ� SCC��� ������ SCC�� ���� ������
��ŭ �湮�� �� �ִ�. 

*/

#include <algorithm>
#include <vector>  
#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;

const int INF = 987654321;

int v, e, a, b, s, t, cnt;
vector<int> graph[10010], sccId, discovered, order, scc2num[10010], tree[10010];
int sccCounter, vertexCounter;
stack<int> st;
bool visited[10010];

int scc(int here) {

	int ret = discovered[here] = vertexCounter++;
	st.push(here);

	for (int i = 0; i < graph[here].size(); i++) {
		int there = graph[here][i];

		if (discovered[there] == -1)
			ret = min(ret, scc(there));
		else if (sccId[there] == -1)
			ret = min(ret, discovered[there]);
	}
	if (ret == discovered[here]) {
		while (true) {
			cnt++;
			int t = st.top();
			st.pop();
			sccId[t] = sccCounter;
			scc2num[sccCounter].push_back(t);
			if (t == here) break;
		}
		order.push_back(here);
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
//SCC�� �ϳ��� �������� ���� �𵨸��� �Ѵ�.
void modeling(int here) {

	visited[here] = true;
	int curScc = sccId[here];

	for (int i = 0; i < graph[here].size(); i++) {
		int there = graph[here][i];

		//���� SCC��� �Լ� ȣ�⸸ ���ش�.
		if (sccId[there] == curScc) 
			if (visited[there] == false) modeling(there);
		//�ٸ� SCC��� �Լ� ȣ���, �������� �����Ѵ�.
		else {
			if (visited[there] == false) modeling(there);
			tree[curScc].push_back(sccId[there]);
		}
	}
}
//���� here���� ���� ���� t���� ����, �湮�� �� �ִ� ���� ���� �ִ밪
int dfs(int here) {

	if (sccId[t] == here) {
		return scc2num[here].size();
	}
	int ret = -INF;
	for (int i = 0; i < tree[here].size(); i++) {
		int there = tree[here][i];
		if (visited[there] == true) continue;
		visited[there] = true;
		ret = max(ret, int(dfs(there) + scc2num[here].size()));
		visited[there] = false;
	}
	return ret;

}
int main() {

	scanf("%d%d%d%d", &v, &e, &s, &t);

	for (int i = 0; i < e; i++) {
		scanf("%d%d", &a, &b);
		graph[a].push_back(b);
	}
	vector<int> res = tarjanSCC();

	memset(visited, 0, sizeof(visited));
	for (int i = 1; i <= v; i++) {
		if (visited[i] == false) {
			visited[i] = true;
			modeling(i);
			visited[i] = false;
		}
	}
	if (sccId[s] == sccId[t])
		printf("%d\n", scc2num[sccId[s]].size());
	else {
		memset(visited, 0, sizeof(visited));
		visited[sccId[s]] = true;
		int sol = dfs(sccId[s]);
		printf("%d\n", sol < -INF + 1000000 ? 0 : sol);
	}
}