/*

�ִ� �ѹ����� ���� �μ��� �̵��� �� ���� ��
�ִ� ��θ� ���ϴ� ����

data2[i][j][state] => state�� �߰��� �д�.
���� ��� state�� 0�϶� ���� i,j ���� ���µ� �ִ� �Ÿ� ���ٸ�
state�� 1�϶��� i,j ���� ���� �ѹ� �μ��� �� �ִ� �Ÿ��� �����Ѵ�.

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

typedef long long ll;

const ll MOD = 1000000007;
const int RETURN = 1061109567;
const int INF = 987654321;
const int MAX_SIZE = 500000 * 4;
const int MAX_NUM = 2000000010;
const ll INFF = 9876543212345;
const int MAX_V = 410;

int n, m, data1[1010][1010], data2[1010][1010][2];
char ch;

int dr[4] = { 1,0,-1,0 };
int dc[4] = { 0,1,0,-1 };

bool ispossible(int row, int col) {
	if (row < 1 || col < 1 || row == n + 1 || col == m + 1) return false;
	return true;
}
void bfs(int row, int col) {

	queue<pair<pair<int, int >, int > > q;
	q.push(make_pair(make_pair(row, col), 0));
	data2[row][col][0] = 1;

	while (!q.empty()) {

		int herer = q.front().first.first;
		int herec = q.front().first.second;
		int state = q.front().second;
		q.pop();

		for (int j = 0; j < 4; j++) {
			int nextr = herer + dr[j];
			int nextc = herec + dc[j];
			if (ispossible(nextr, nextc)) {
				//�̵��� �� �ִٸ�
				if (data1[nextr][nextc] == 0 && data2[herer][herec][state] + 1 < data2[nextr][nextc][state]) {
					q.push(make_pair(make_pair(nextr, nextc), state));
					data2[nextr][nextc][state] = data2[herer][herec][state] + 1;
				}
				//������� ���� �ѹ��� �Ⱥν���, ���� �ν��� �̵��� �Ŷ��
				if (data1[nextr][nextc] == 1 && state == 0 && data2[herer][herec][0] + 1 < data2[nextr][nextc][1]) {
					q.push(make_pair(make_pair(nextr, nextc), state + 1));
					data2[nextr][nextc][state + 1] = data2[herer][herec][state] + 1;
				}
			}
		}
	}
	int res = min(data2[n][m][0], data2[n][m][1]);
	if (res == INF) printf("-1\n");
	else printf("%d\n", res);
}

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d%d", &n, &m);

	getchar();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%c", &ch);
			if (ch == '0') data1[i][j] = 0;
			else data1[i][j] = 1;
		}
		getchar();
	}
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			for (int k = 0; k <= 1; k++)
				data2[i][j][k] = INF;
	bfs(1, 1);

}