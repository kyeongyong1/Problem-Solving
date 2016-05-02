/*

S번 도시에서 T번 도시로 이동할 때, 
방문할 수 있는 최대 도시를 출력하는 문제
단, 항공로는 여러번 이용할 수도 있고, 같은 도시를
여러번 방문할 수 있는데 1번만 센다.

그래프로 모델링을 한 후 SCC로 묶어준다. 이때 한 도시에서
다른 도시로 이동할 때, 다른 SCC라면 각각의 SCC에 속한 정점들
만큼 방문할 수 있다. 

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
//SCC를 하나의 정점으로 보고 모델링을 한다.
void modeling(int here) {

	visited[here] = true;
	int curScc = sccId[here];

	for (int i = 0; i < graph[here].size(); i++) {
		int there = graph[here][i];

		//같은 SCC라면 함수 호출만 해준다.
		if (sccId[there] == curScc) 
			if (visited[there] == false) modeling(there);
		//다른 SCC라면 함수 호출과, 간선으로 연결한다.
		else {
			if (visited[there] == false) modeling(there);
			tree[curScc].push_back(sccId[there]);
		}
	}
}
//현재 here에서 도착 도시 t까지 갈때, 방문할 수 있는 도시 수의 최대값
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