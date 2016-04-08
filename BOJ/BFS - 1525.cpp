/*

현재 칸의 상태를 하나의 정점으로 하고 BFS를 돌린다.
그랬을 때 정리된 상태의 칸을 만났을 때,	해당 칸까지의
너비를 출력하는 방식으로 코드를 구현 하였다.


*/

#include <algorithm>
#include <functional>
#include <vector>
#include <map>    
#include <cstdio>
#include <queue>
#include <climits>
#include <stack>
#include <set>
#include <cmath>
#include <cstring>
#include <list>
using namespace std;

vector<char> od;
int dr[4] = { 1,0,-1,0 };
int dc[4] = { 0,1,0,-1 };
char ch = 0;
map<vector<char>, char> m;

bool ispossible(int r, int c) {
	if (r < 0 || c < 0 || r > 2 || c > 2) return false;
	return true;
}
int bfs(vector<char> d) {

	queue<vector<char>> q;
	q.push(d);
	m[d] = ch++;
	int cnt = 0;
	while (!q.empty()) {
		int Size = q.size();
		for (int i = 0; i < Size; i++) {
			vector<char> here = q.front();
			q.pop();

			bool flag = true;
			//해당 칸이 잘 정리된 칸인지 조사
			for (int j = 0; j < 8; j++) {
				if (here[j] != j + 1) flag = false;
			}
			if (flag == true) return cnt;
			int idx = -1;
			//옮길 수 있는 칸의 위치를 찾는다.
			for (int j = 0; j < 9; j++)
				if (here[j] == 9) idx = j;
			int hr = idx / 3, hc = idx % 3;

			for (int j = 0; j < 4; j++) {
				int nr = hr + dr[j], nc = hc + dc[j];
				if (ispossible(nr, nc)) {
					int nextidx = nr * 3 + nc;

					//위치를 바꿔주고
					swap(here[idx], here[nextidx]);
					//그 칸을 방문한 적이 없다면 q에 넣어준다.
					if (m.count(here) == 0) {
						m[here] = ch++;
						q.push(here);
					}
					//위치를 원래대로 바꿔 준다.
					swap(here[idx], here[nextidx]);
				}
			}
		}
		cnt++;
	}
	return -1;
}

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	od.resize(9);
	for (int i = 0; i < 9; i++) {
		scanf("%d", &od[i]);
		if (od[i] == 0) od[i] = 9;
	}
	printf("%d\n", bfs(od));

}