//brute force �ϸ� �ð� �ʰ� ����
//������ �ٸ� �˰����� �����Ͽ��� �Ѵ�
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
//v[i][j].first - > i,j �ε����κ��� ���ʹ����� ������ ��, '��������' ī��Ʈ�� ����
//v[i][j].second -> i,j �ε����κ��� �����ʹ����� ������ ��, '��������' ī��Ʈ�� ����
vector<pair<int, int> > v[502];

void sol(int row, int col) {

	int left = v[row][col].first, up = v[row][col].second;

	//row, col���κ��� ���ʹ������� �������� ī��Ʈ�� ����
	//index�� ��� ���캻��. 
	//��, �ش� ���̸� ���� �� �ִ� ���� ū ���簢���� '�غ�'�� �����ϴ� ���̴�.
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

		//input ó��
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

		//�ʱ�ȭ
		for (int i = 0; i < 502; i++)
			v[i].clear(), v[i].resize(502, make_pair(0, 0));

		//v[i][j] �ʱ�ȭ
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