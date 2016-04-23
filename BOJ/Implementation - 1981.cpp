/*

배열이 주어질 때 몇 개의 수를 거쳐서 이동하는데, 이 때 지나간 수들 중
최대값과 최소값의 차이가 최소가 되는 값을 출력하는 문제

배열의 각 수는 200보다 작거나 같은 음이 아닌 양수이므로,
최대값과 최소값을 강제하여 dfs를 풀었다.

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

	//최대값과 최소값을 강제
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