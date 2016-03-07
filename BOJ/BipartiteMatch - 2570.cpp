/*
������ ĭ ��� �밢���̶�� �����غ���.
�밢������ ������ �ִ� �� ĭ���� �ϳ��� �����
�� �������� �ִ� �ϳ��� ����� ���� �� �ְ� �ȴ�.

�� ĭ�� ����� ������ �� ĭ�� �����ϴ� �� ���� ����
(�ϳ��� ĭ���� �׻� �ΰ��� ������ ����) ���� �� �̻�
����� ���� �� ���� �ȴ�. ���� ����� ���� �ٴ� ����
'�� �� ������ ���� ������Ű�� ��'�̶�� �ؼ��� �� �ִ�.

�� ������ ���� ���Ұ� ���� �� �� ������ �������� �����Ͽ�
�׷����� �𵨸��� �ϰ�, ���� ������ �� ������ ���� ���Ҹ�
���� �� ����. ���� �̺� �׷����� �ȴ�.

�� �׷����� �̺� ��Ī�� ũ��� 'ü���ǿ� ��ġ�� �� �ִ� 
����� �ִ� ��'�� �ȴ�.
*/
#include <algorithm>
#include <functional>
#include <vector>
#include <map>    
#include <cstdio>
#include <queue>
#include <limits.h>
#include <stack>
#include <stdio.h>
#include <set>
#include <math.h>
#include <cstring>
using namespace std;

int n, m, r, c, arr[110][110], id[2][110][110], cnt[2];
int aMatch[2000], bMatch[2000];
bool visited[2000];

int dr[2] = { 1, 1 };
int dc[2] = { 1, -1 };

vector<int> graph[2000];

bool ispossible(int row, int col) {
	if (row<1 || col<1 || row>n || col>n || arr[row][col] == 1) return false;
	return true;
}
void modeLing() {

	memset(id, -1, sizeof(id));

	//�� ������ ���Ͽ� ������ �밢���Ʒ�, ���� �밢���Ʒ���
	//�����ְ� ���� ��ȣ�� �ο��Ѵ�.
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				//��ֹ��� �ƴϰ� ��ȣ�� �ο����� �ʾҴٸ�
				if (arr[j][k] == 0 && id[i][j][k] == -1) {
					int cr = j, cc = k;
					//�����ش�.
					while (ispossible(cr, cc)) {
						id[i][cr][cc] = cnt[i];
						cr += dr[i], cc += dc[i];
					}
					cnt[i]++;
				}
			}
		}
	}

	//�� ĭ�鿡 ���ؼ� �� ������ �̺� �׷����� �𵨸��Ѵ�.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == 0) {
				graph[id[0][i][j]].push_back(id[1][i][j]);
			}
		}
	}
}
bool dfs(int a) {
	if (visited[a]) return false;
	visited[a] = true;

	for (int i = 0; i < graph[a].size(); i++) {
		int b = graph[a][i];
		//b�� ��ġ�� �ȵǾ��ų� b�� ��ġ�� a�� �ٸ� b`�� ��ġ�� �� �ִٸ�
		if (bMatch[b] == -1 || dfs(bMatch[b])) {
			aMatch[a] = b;
			bMatch[b] = a;
			return true;
		}
	}
	return false;
}
int bPm() {

	memset(aMatch, -1, sizeof(aMatch));
	memset(bMatch, -1, sizeof(bMatch));

	int size = 0;

	for (int i = 0; i < cnt[0]; i++) {
		memset(visited, 0, sizeof(visited));
		//����� ��ġ �� �� �ִٸ�
		if (dfs(i)) size++;
	}
	return size;
}
int main() {

	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; i++) {
		scanf("%d%d", &r, &c);
		arr[r][c] = 1;
	}
	modeLing();
	int res = bPm();
	printf("%d\n", res);
}