/*

Inversion sequence�� �־��� ��, �ش��ϴ� ������ ������ ���ϴ� ����
inversion sequence ������ i��° ���Ҵ� �������� i���� �ڿ�
�����鼭 i���� ���� ���� �����̴�. 

�ڿ��� ���� ���鼭 �ڸ��� �����ָ� �Ǵµ�, �ش� �ڸ��� ������ ���ϱ�
���Ͽ� �ε��� Ʈ���� �̿��Ͽ� ���� �Ͽ���. 

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

const int MAX_SIZE = 100000 * 4;

int n, tree[MAX_SIZE], a, tSize = 1;
vector<int> v, res;

void update(int pos, int val) {

	pos += tSize;
	tree[pos] += val;
	pos /= 2;
	while (pos) {
		tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
		pos /= 2;
	}
}
int read(int num) {
	int pos = 2;

	while (1) {
		if (pos >= tSize) {
			if (num == 2) 
				pos++;
			while (tree[pos] == 0) 
				pos++;
			break;
		}
		if (tree[pos] >= num)
			pos *= 2;
		else
			num -= tree[pos++];
	}
	return pos - tSize;

}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d", &n);
	while (tSize < n)
		tSize *= 2;

	v.resize(n), res.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	for (int i = 0; i < n; i++)
		update(i, 1);

	for (int i = n - 1; i >= 0; i--) {

		//�ش� �ڸ��� ������ ���ϰ�
		int idx = read(v[i] + 1);
		
		//�ش� �ڸ��� ����ߴٰ� ǥ���Ѵ�.
		update(idx, -1);
		res[idx] = i + 1;
	}
	for (int i = res.size() - 1; i >= 0; i--) 
		printf("%d ", res[i]);
	printf("\n");
}