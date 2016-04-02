/*

�� �δ��� ������� �ְ� ������ �־�����. ������ ���°�
1 i a ��� i�� �δ뿡 a���� ���ؾ� �ϰ�
2 i ��� i�� ������ �� �� �δ뿡 �ִ��� ����ؾ� �Ѵ�.

�ε��� Ʈ���� �̿��Ͽ� �� ������ ���ؼ� ������ ����� �� �ִ�.

*/

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <math.h>
#include <cstring>
using namespace std;

const int MAX_SIZE = 500000 * 4;
int a, b, c, n, m, tree[MAX_SIZE], size = 1;

void update(int pos, int val) {
	pos += size;
	tree[pos] += val, pos /= 2;
	while (pos) {
		tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
		pos /= 2;
	}
}
int read(int s) {
	
	//s�� ã�ƾ� �ϴ� �� ��° ����

	int num = 2;
	while (1) {
		if (size <= num && num <= size * 2 - 1)
			break;

		//�ε��� Ʈ������ �ش� ��尡 s���� ũ�ų� ���ٸ�
		//���� �ڽſ� ���� ����Ʈ���� ������� �� �ϳ��� �ش� ��ġ�̴�.
		if (tree[num] >= s)
			num *= 2;
		//s���� �۴ٸ� ������ �ڽĿ� ���� ����Ʈ����
		//������� �� �ϳ��� �ش� ��ġ�̴�. s�� ���� ���ش�.
		if (tree[num] < s) {
			s -= tree[num++];
		}
	}
	return num;
}
int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	ios::sync_with_stdio(false);

	cin >> n;

	while (size < n)
		size *= 2;

	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		update(i, a);
	}
	cin >> m;

	while (m--) {
		cin >> a;

		if (a == 1) {
			cin >> b >> c;
			update(b - 1, c);
		}
		else if (a == 2) {
			cin >> b;
			cout << read(b) - size + 1 << endl;
		}
	}
}