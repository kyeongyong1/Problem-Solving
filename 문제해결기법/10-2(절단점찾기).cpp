//절단점 찾기
//dfs함수 한번의 수행만으로 '절단점'을 찾는 알고리즘
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

int m, n, k, counter;

vector<int> graph[10010];
vector<int> discovery;
vector<bool> isCutVertex;

//dfs 
//return 값은 해당 vertex의 dfs방문 순서
int sol(int here, bool isroot) {

	//dfs 방문 순서를 저장
	discovery[here] = counter++;
	int ret = discovery[here];

	int children = 0;

	for (int i = 0; i < graph[here].size(); i++) {
		//방문되지 않았다면
		if (discovery[graph[here][i]] == -1) {
			children++;
			int subtree = sol(graph[here][i], 0);
			//루트가 아니면서, 해당 vertex 보다 자식 vertex중에 방문순서가 
			//더 느린 경우가 있다면 해당 vertex는 절단점 -> 해당 vertex로는 올 수 있는
			//경우가 없다는 말이므로.. 
			if (!isroot && subtree >= discovery[here])
				isCutVertex[here] = true;
			ret = min(ret, subtree);
		} //방문되었다면 자식 vertex중 방문순서가 빠른 값으로 갱신
		else
			ret = min(ret, discovery[graph[here][i]]);
	}
	//root라면 자식들이 2이상이면 해당 vertex는 절단점
	if (isroot) isCutVertex[here] = (children >= 2);
	return ret;
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	//ios::sync_with_stdio(false);

	cin >> m;

	while (m--) {
		counter = 0;
		for (int i = 0; i < 10010; i++)
			graph[i].clear();
		discovery.clear();
		discovery.resize(10010, -1);
		isCutVertex.clear();
		isCutVertex.resize(10010, 0);

		cin >> n >> k;
		//무향그래프 모델링
		for (int i = 0; i < k; i++) {
			int a, b; cin >> a >> b;
			graph[a].push_back(b), graph[b].push_back(a);
		}
		sol(0, 1);
		for (int i = 0; i < n; i++) {
			if (isCutVertex[i] == true) cout << i << " ";
		}
		cout << endl;
	}
}