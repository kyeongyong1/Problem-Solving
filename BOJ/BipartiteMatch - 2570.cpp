/*
단위를 칸 대신 대각선이라고 생각해보자.
대각선으로 연속해 있는 빈 칸들을 하나로 묶어보면
한 묶음에는 최대 하나의 비숍만을 놓을 수 있게 된다.

한 칸에 비숍을 놓으면 이 칸을 포함하는 두 개의 묶음
(하나의 칸에는 항상 두개의 묶음이 존재) 에는 더 이상
비숍을 놓을 수 없게 된다. 따라서 비숍을 놓는 다는 말은
'이 두 묶음을 서로 대응시키는 것'이라고 해석할 수 있다.

두 묶음에 공통 원소가 있을 때 두 정점을 간선으로 연결하여
그래프로 모델링을 하고, 같은 방향의 두 묶음은 공통 원소를
가질 수 없다. 따라서 이분 그래프가 된다.

이 그래프의 이분 매칭의 크기는 '체스판에 배치할 수 있는 
비숍의 최대 수'가 된다.
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

	//각 정점에 대하여 오른쪽 대각선아래, 왼쪽 대각선아래를
	//묶어주고 각각 번호를 부여한다.
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				//장애물이 아니고 번호가 부여되지 않았다면
				if (arr[j][k] == 0 && id[i][j][k] == -1) {
					int cr = j, cc = k;
					//묶어준다.
					while (ispossible(cr, cc)) {
						id[i][cr][cc] = cnt[i];
						cr += dr[i], cc += dc[i];
					}
					cnt[i]++;
				}
			}
		}
	}

	//각 칸들에 대해서 두 묶음을 이분 그래프로 모델링한다.
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
		//b가 매치가 안되었거나 b를 매치한 a가 다른 b`를 매치할 수 있다면
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
		//비숍을 배치 할 수 있다면
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