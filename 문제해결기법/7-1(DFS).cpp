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

//방향 배열
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

//값이 '1'이거나, 배열의 인덱스를 넘어가지 않는다면 방문한다
bool ispossible(int row, int col) {
	if (row == -1 || col == -1 || row == n || col == n || data[row][col] == '0') return false;
	return true;
}
int sol(int row, int col) {

	//방문 했으므로 0으로 표시(다음에 또 방문하는 것을 방지하기 위해)
	data[row][col] = '0';

	int	ret = 1;
	//현재 위치로부터 4방향을 조사한다
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

		//maxx값을 계속해서 갱신
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
