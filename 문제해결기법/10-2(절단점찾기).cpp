//������ ã��
//dfs�Լ� �ѹ��� ���ุ���� '������'�� ã�� �˰���
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
//return ���� �ش� vertex�� dfs�湮 ����
int sol(int here, bool isroot) {

	//dfs �湮 ������ ����
	discovery[here] = counter++;
	int ret = discovery[here];

	int children = 0;

	for (int i = 0; i < graph[here].size(); i++) {
		//�湮���� �ʾҴٸ�
		if (discovery[graph[here][i]] == -1) {
			children++;
			int subtree = sol(graph[here][i], 0);
			//��Ʈ�� �ƴϸ鼭, �ش� vertex ���� �ڽ� vertex�߿� �湮������ 
			//�� ���� ��찡 �ִٸ� �ش� vertex�� ������ -> �ش� vertex�δ� �� �� �ִ�
			//��찡 ���ٴ� ���̹Ƿ�.. 
			if (!isroot && subtree >= discovery[here])
				isCutVertex[here] = true;
			ret = min(ret, subtree);
		} //�湮�Ǿ��ٸ� �ڽ� vertex�� �湮������ ���� ������ ����
		else
			ret = min(ret, discovery[graph[here][i]]);
	}
	//root��� �ڽĵ��� 2�̻��̸� �ش� vertex�� ������
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
		//����׷��� �𵨸�
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