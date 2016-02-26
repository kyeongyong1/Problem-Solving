#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

int m, n, r;
bool visited[52];
//graph[i] i�л����� ������ ������ �л����� ����
vector<int> graph[52];
//rgraph[i] i�л����� ������ ���� �л����� ����
vector<int> rgraph[52];

int dfs(int here, bool reverse) {
	int ret = 0;
	if (reverse == 0) {
		//here�л����� ������ ������ �л����� ã�´�
		for (int i = 0; i < graph[here].size(); i++) {
			//�ش��л��� '����' �ʾҴٸ�
			if (visited[graph[here][i]] == false) {
				visited[graph[here][i]] = true;
				ret += dfs(graph[here][i], reverse) + 1;
			}
		}
	}
	else {
		for (int i = 0; i < rgraph[here].size(); i++) {
			if (visited[rgraph[here][i]] == false) {
				visited[rgraph[here][i]] = true;
				ret += dfs(rgraph[here][i], reverse) + 1;
			}
		}
	}
	return ret;
}
int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);

	cin >> m;
	while (m--) {
		cin >> n >> r;
		memset(graph, 0, sizeof(graph)), memset(rgraph, 0, sizeof(rgraph));

		for (int i = 0; i < r; i++) {
			int a, b;
			cin >> a >> b;
			graph[a - 1].push_back(b - 1), rgraph[b - 1].push_back(a - 1);
		}
		for (int i = 0; i < n; i++) {
			memset(visited, 0, sizeof(visited));
			cout << dfs(i, 1) << " ";
			memset(visited, 0, sizeof(visited));
			cout << dfs(i, 0) << endl;
		}
	}
}