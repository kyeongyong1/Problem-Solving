/*
Lazy Propagation (게으른 전파, '나중에' 업데이트 하기)

Top-Bottom 방식인 Segment트리에서 업데이트를 나중에 하는 것을 말한다.
하위 레벨에 있는 노드에 대해서는 Lazy값만 주고, 나중에 그 노드에
'방문했을 때' 업데이트를 진행하는 방식이다.

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

//해당 노드에 방문했고, lazy값이 있을 때 업데이트를 해준다.
//업데이트를 한 후에는 자식노드에게 lazy값만 더해준다. (업데이트는 x)
void update_lazy(int node, int start, int end) {
	if (lazy[node] != 0) {
		//업데이트를 한다.
		tree[node] += lazy[node] * (end - start + 1);
		//리프 노드에 도달했을 경우
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}
//해당 구간에 대하여 업데이트를 한다.
void update_range(int node, int start, int end, int val) {

	//방문했으면 lazy값을 업데이트 해준다.
	update_lazy(node, start, end);

	//범위가 아니면 리턴
	if (LEFT > end || RIGHT < start) return;

	//범위안에 들어온다면
	if (LEFT <= start && end <= RIGHT) {

		//해당 노드에 더하고자 하는 값을 더한다.
		tree[node] += (ll)val*(end - start + 1);
		//업데이트는 나중에 할 것이므로 lazy값만 갱신시킨다.
		if (start != end) {
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}
		return;
	}
	//왼쪽노드, 오른쪽노드를 업데이트 한다.
	update_range(node * 2, start, (start + end) / 2, val);
	update_range(node * 2 + 1, (start + end) / 2 + 1, end, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
ll sum(int node, int start, int end) {

	//범위가 아니면 0을 리턴
	if (LEFT > end || RIGHT < start) return 0;
	
	//lazy를 업데이트 한다.
	update_lazy(node, start, end);

	//범위 안에 있는 노드라면 해당 노드를 리턴
	if (LEFT <= start && end <= RIGHT)
		return tree[node];

	//자식 노드들을 호출한다.
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