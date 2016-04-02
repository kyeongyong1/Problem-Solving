/*

각 부대의 군사수가 있고 쿼리가 주어진다. 쿼리의 형태가
1 i a 라면 i번 부대에 a명을 더해야 하고
2 i 라면 i번 군인이 몇 번 부대에 있는지 출력해야 한다.

인덱스 트리를 이용하여 각 쿼리에 대해서 빠르게 대답할 수 있다.

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
	
	//s는 찾아야 하는 몇 번째 군인

	int num = 2;
	while (1) {
		if (size <= num && num <= size * 2 - 1)
			break;

		//인덱스 트리에서 해당 노드가 s보다 크거나 같다면
		//왼쪽 자신에 대한 서브트리의 리프노드 중 하나가 해당 위치이다.
		if (tree[num] >= s)
			num *= 2;
		//s보다 작다면 오른쪽 자식에 대한 서브트리의
		//리프노드 중 하나가 해당 위치이다. s의 값을 빼준다.
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