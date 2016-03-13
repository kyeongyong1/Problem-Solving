/*
Lazy Propagation (������ ����, '���߿�' ������Ʈ �ϱ�)

Top-Bottom ����� SegmentƮ������ ������Ʈ�� ���߿� �ϴ� ���� ���Ѵ�.
���� ������ �ִ� ��忡 ���ؼ��� Lazy���� �ְ�, ���߿� �� ��忡
'�湮���� ��' ������Ʈ�� �����ϴ� ����̴�.

*/

#include <algorithm>
#include <functional>
#include <vector>
#include <map>    
#include <cstdio>
#include <queue>
#include <limits.h>
#include <stack>
#include <set>
#include <math.h>
#include <cstring>
#include <list>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const int RETURN = 1061109567;
const int INF = 987654321;
const int MAX_SIZE = 1000000 * 4;
const int MAX_NUM = 1000001;
const ll INFF = 9876543212345;
const int MAX_V = 410;

int n, m, k, a, b, c, LEFT, RIGHT, d;
ll tree[MAX_SIZE], lazy[MAX_SIZE], Size = 1;

//�ش� ��忡 �湮�߰�, lazy���� ���� �� ������Ʈ�� ���ش�.
//������Ʈ�� �� �Ŀ��� �ڽĳ�忡�� lazy���� �����ش�. (������Ʈ�� x)
void update_lazy(int node, int start, int end) {
	if (lazy[node] != 0) {
		//������Ʈ�� �Ѵ�.
		tree[node] += lazy[node] * (end - start + 1);
		//���� ��忡 �������� ���
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}
//�ش� ������ ���Ͽ� ������Ʈ�� �Ѵ�.
void update_range(int node, int start, int end, int val) {

	//�湮������ lazy���� ������Ʈ ���ش�.
	update_lazy(node, start, end);

	//������ �ƴϸ� ����
	if (LEFT > end || RIGHT < start) return;

	//�����ȿ� ���´ٸ�
	if (LEFT <= start && end <= RIGHT) {

		//�ش� ��忡 ���ϰ��� �ϴ� ���� ���Ѵ�.
		tree[node] += (ll)val*(end - start + 1);
		//������Ʈ�� ���߿� �� ���̹Ƿ� lazy���� ���Ž�Ų��.
		if (start != end) {
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}
		return;
	}
	//���ʳ��, �����ʳ�带 ������Ʈ �Ѵ�.
	update_range(node * 2, start, (start + end) / 2, val);
	update_range(node * 2 + 1, (start + end) / 2 + 1, end, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
ll sum(int node, int start, int end) {

	//������ �ƴϸ� 0�� ����
	if (LEFT > end || RIGHT < start) return 0;
	
	//lazy�� ������Ʈ �Ѵ�.
	update_lazy(node, start, end);

	//���� �ȿ� �ִ� ����� �ش� ��带 ����
	if (LEFT <= start && end <= RIGHT)
		return tree[node];

	//�ڽ� ������ ȣ���Ѵ�.
	return sum(node * 2, start, (start + end) / 2) + sum(node * 2 + 1, (start + end) / 2 + 1, end);
}

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d%d%d", &n, &m, &k);

	while (n > Size)
		Size *= 2;

	for (int i = 0; i < n; i++)
		scanf("%d", &tree[i + Size]);
	for (int i = Size - 1; i >= 1; i--)
		tree[i] = tree[i * 2] + tree[i * 2 + 1];

	for (int i = 0; i < m + k; i++) {
		scanf("%d%d%d", &a, &b, &c);
		LEFT = b - 1, RIGHT = c - 1;

		if (a == 1) {
			scanf("%d", &d);
			update_range(1, 0, Size - 1, d);
		}
		else {
			printf("%lld\n", sum(1, 0, Size - 1));
		}
	}
}