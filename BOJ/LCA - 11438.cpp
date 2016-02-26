/*
LCA (Lowest Common Ancestor)
두 노드의 가장 가까운 공통 조상 노드를 찾는 문제

루트노드의 세대는 0이라고 하고, 그 자식 노드의 세대는 1
이런 식으로 세대를 지정하여 문제를 해결하면 시간안에 해결하지 못한다.

루트를 기준으로 preorder를 수행한다. 


*/


#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

const int INF = 987654321;
const int MAX_SIZE = 100000 * 10;

//Num은 정점의 번호, order은 전위 순회의 발견 순서
//num_order -> Num to Order     order_num -> Order to Num
//
int n, m, tree[MAX_SIZE], size = 1, a, b, num_order[100010], order_num[100010], order, find_num[100010];
vector<int> input[100010], porder;
bool visited[100010];

void preorder(int here) {

	visited[here] = true;
	order_num[order] = here;
	num_order[here] = order++;

	find_num[here] = porder.size();
	porder.push_back(num_order[here]);

	for (int i = 0; i < input[here].size(); i++) {
		int there = input[here][i];
		if (visited[there] == false) {
			preorder(there);
			porder.push_back(num_order[here]);
		}
	}
}
void update(int pos, int val) {

	pos += size, tree[pos] = val;
	pos /= 2;
	while (pos) {
		tree[pos] = min(tree[pos * 2], tree[pos * 2 + 1]);
		pos /= 2;
	}
}
int read(int lo, int hi) {

	lo += size, hi += size;

	int ret = INF;
	while (lo <= hi) {
		if (lo % 2 == 1) ret = min(ret, tree[lo++]);
		if (hi % 2 == 0) ret = min(ret, tree[hi--]);
		lo /= 2, hi /= 2;
	}
	return ret;
}
int main()
{
	memset(tree, 0x3f, sizeof(tree));

	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d", &a, &b);
		input[a].push_back(b); input[b].push_back(a);
	}

	preorder(1);

	while (size < porder.size())
		size *= 2;

	for (int i = 0; i < porder.size(); i++)
		update(i, porder[i]);

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		a = find_num[a], b = find_num[b];
		if (a>b) swap(a, b);
		printf("%d \n", order_num[read(a, b)]);
	}
	return 0;
}