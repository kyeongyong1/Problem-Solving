/*

Ʈ���� �� ������ ��ĥ�Ϸ��� �ϴµ�, i(1<=i<=n) �� ����� ĥ�� ������
i�� ��ŭ�� ����� ���. �� ������ �� ������ ���� �ٸ� ����� ĥ�ؾ� 
�Ѵٰ� �Ҷ� ��ü �������� ��ĥ�ϴµ� ��� �ּ� ����� ���ϴ� ����

4���� ���� ������ ��� ������ ĥ�ϴµ� �ּ� ����� ���� �� �ִ�.
3���� ���� ���� ��� �� ���� ���� �� �̿��ؼ� ĥ���� �� �ּ��� ��찡 �ִ�.

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
#include <string>
#include <iostream>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const ll MOD = 1000000007;
const ll PLUS = 1000000;

int n, dp[100010][5], a, b;
vector<int> graph[100010], tree[100010], v;
bool visited[100010];
vector<pair<int, int > > vv;

void modeling(int here) {

	visited[here] = true;

	for (int i = 0; i < graph[here].size(); i++) {
		int there = graph[here][i];
		if (visited[there] == false) {
			modeling(there);
			tree[here].push_back(there);
		}
	}
}
int sol(int here, int color) {

	int &ret = dp[here][color];
	if (ret != -1) return ret;

	ret = color;
	int minn;

	for (int i = 0; i < tree[here].size(); i++) {
		int there = tree[here][i];

		minn = INF;
		//�ڽ� ������ 4���� ������ ĥ�ϴ� �� ��
		//���� ���� ���� ���Ѵ�.
		for (int j = 1; j <= 4; j++) {
			if (j == color) continue;
			minn = min(minn, sol(there, j));
		}
		ret += minn;
	}
	return ret;
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	memset(dp, -1, sizeof(dp));

	scanf("%d", &n);


	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a, &b);
		v.push_back(a), v.push_back(b);
		vv.push_back(make_pair(a, b));
	}

	//��ǥ ������ �ؾ� �Ѵ�.
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < vv.size(); i++) {
		a = vv[i].first, b = vv[i].second;
		int aidx = lower_bound(v.begin(), v.end(), a) - v.begin();
		int bidx = lower_bound(v.begin(), v.end(), b) - v.begin();
		graph[aidx].push_back(bidx); graph[bidx].push_back(aidx);
	}

	//Ʈ�� ���·� �𵨸��Ѵ�.
	modeling(1);

	//��Ʈ ������ 1,2,3,4 �� ���� ����� ĥ�� ���� �ּҰ� ��
	//���� ���� ���� ���̴�.
	int minn = min(sol(1, 1), sol(1, 2));
	minn = min(minn, sol(1, 3));
	minn = min(minn, sol(1, 4));
	printf("%d\n", minn);
}