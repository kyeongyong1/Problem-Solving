#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int m, n, maxx;
char data[510][510];

//���� �迭
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

//���� '1'�̰ų�, �迭�� �ε����� �Ѿ�� �ʴ´ٸ� �湮�Ѵ�
bool ispossible(int row, int col) {
	if (row == -1 || col == -1 || row == n || col == n || data[row][col] == '0') return false;
	return true;
}
int sol(int row, int col) {

	//�湮 �����Ƿ� 0���� ǥ��(������ �� �湮�ϴ� ���� �����ϱ� ����)
	data[row][col] = '0';

	int	ret = 1;
	//���� ��ġ�κ��� 4������ �����Ѵ�
	for (int i = 0; i < 4; i++) {
		if (ispossible(row + dx[i], col + dy[i])) {
			ret += sol(row + dx[i], col + dy[i]);
		}
	}
	return ret;
}
int main(void)
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	//ios::sync_with_stdio(false);
	cin >> m;
	while (m--) {
		cin >> n;
		maxx = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> data[i][j];

		//maxx���� ����ؼ� ����
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (data[i][j] == '1') {
					maxx = max(maxx, sol(i, j));
				}
			}
		}
		cout << maxx << endl;
	}
}
