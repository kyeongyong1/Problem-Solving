//brute force 하면 시간 초과 나기
//때문에 다른 알고리즘을 생각하여야 한다
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

const int INF = 987654321;
int m, row, col, maxx;
int data[502][502];
//v[i][j].first - > i,j 인덱스로부터 왼쪽방향을 보았을 때, '연속적인' 카페트의 개수
//v[i][j].second -> i,j 인덱스로부터 오른쪽방향을 보았을 때, '연속적인' 카페트의 개수
vector<pair<int, int> > v[502];

void sol(int row, int col) {

	int left = v[row][col].first, up = v[row][col].second;

	//row, col으로부터 왼쪽방향으로 연속적인 카페트에 대한
	//index를 모두 살펴본다. 
	//즉, 해당 높이를 가질 수 있는 가장 큰 직사각형의 '밑변'을 조사하는 것이다.
	for (int i = 0; i < up; i++) {
		int cur = 1;
		for (int j = 1; j<left; j++) {
			if (v[row][col - j].second<i + 1) break;
			cur++;
		}
		maxx = max(maxx, (i + 1)*cur);
	}
}
int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	ios::sync_with_stdio(false);

	cin >> m;
	while (m--) {
		maxx = 0;
		memset(data, 0, sizeof(data));
		cin >> row >> col;

		//input 처리
		for (int i = 0; i < row; i++) {
			int cnt = 0;
			do {
				int a; cin >> a;
				cnt += a;
				char ch; cin >> ch;
				if (ch == 'e') {
					for (int j = cnt - a; j < cnt; j++)
						data[i][j] = 0;
				}
				else {
					for (int j = cnt - a; j < cnt; j++)
						data[i][j] = 1;
				}
			} while (cnt != col);
		}

		//초기화
		for (int i = 0; i < 502; i++)
			v[i].clear(), v[i].resize(502, make_pair(0, 0));

		//v[i][j] 초기화
		for (int i = 1; i <= row; i++) {
			for (int j = 1; j <= col; j++) {
				if (data[i - 1][j - 1] == 1) {
					v[i][j].second = (v[i - 1][j].second + 1);
					v[i][j].first = (v[i][j - 1].first + 1);
				}
			}
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (data[i][j] == 1) {
					sol(i + 1, j + 1);
				}
			}
		}
		cout << maxx << endl;
	}
}