/*

���� ĭ�� ���¸� �ϳ��� �������� �ϰ� BFS�� ������.
�׷��� �� ������ ������ ĭ�� ������ ��,	�ش� ĭ������
�ʺ� ����ϴ� ������� �ڵ带 ���� �Ͽ���.


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
			//�ش� ĭ�� �� ������ ĭ���� ����
			for (int j = 0; j < 8; j++) {
				if (here[j] != j + 1) flag = false;
			}
			if (flag == true) return cnt;
			int idx = -1;
			//�ű� �� �ִ� ĭ�� ��ġ�� ã�´�.
			for (int j = 0; j < 9; j++)
				if (here[j] == 9) idx = j;
			int hr = idx / 3, hc = idx % 3;

			for (int j = 0; j < 4; j++) {
				int nr = hr + dr[j], nc = hc + dc[j];
				if (ispossible(nr, nc)) {
					int nextidx = nr * 3 + nc;

					//��ġ�� �ٲ��ְ�
					swap(here[idx], here[nextidx]);
					//�� ĭ�� �湮�� ���� ���ٸ� q�� �־��ش�.
					if (m.count(here) == 0) {
						m[here] = ch++;
						q.push(here);
					}
					//��ġ�� ������� �ٲ� �ش�.
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