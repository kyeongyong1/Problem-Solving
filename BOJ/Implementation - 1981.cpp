/*

�迭�� �־��� �� �� ���� ���� ���ļ� �̵��ϴµ�, �� �� ������ ���� ��
�ִ밪�� �ּҰ��� ���̰� �ּҰ� �Ǵ� ���� ����ϴ� ����

�迭�� �� ���� 200���� �۰ų� ���� ���� �ƴ� ����̹Ƿ�,
�ִ밪�� �ּҰ��� �����Ͽ� dfs�� Ǯ����.

*/

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>    
#include <cstdio>
#include <string>
#include <float.h>
#include <queue>
#include <cstring>
#include <math.h>
using namespace std;

int n, data[110][110];
bool visited[110][110];

int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };

bool ispossible(int r, int c) {
	if (r == -1 || c == -1 || r == n || c == n) return false;
	return true;
}
bool dfs(int r, int c, int minn, int maxx) {

	if (visited[r][c] == true || !ispossible(r, c))
		return false;
	if (data[r][c]<minn || data[r][c]>maxx) return false;

	if (r == n - 1 && c == n - 1) return true;
	visited[r][c] = true;

	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i], nc = c + dc[i];
		if (dfs(nr, nc, minn, maxx))
			return true;
	}

	return false;
}
int main()
{

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> data[i][j];

	int sol = 200;

	//�ִ밪�� �ּҰ��� ����
	for (int minn = 0; minn <= 200; minn++) {
		for (int maxx = minn; maxx <= 200; maxx++) {

			memset(visited, 0, sizeof(visited));
			if (dfs(0, 0, minn, maxx)) {
				sol = min(sol, maxx - minn);
			}
		}
	}
	cout << sol << endl;
}