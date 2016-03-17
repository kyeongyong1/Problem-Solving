/*
DP problem

dp[left][right] : �ֱٿ� 1�� �������� left���� �԰�, 
				  2�� �������� right���� ���� �� �ִ밪.

������ ����� �ϴµ� dp�Լ� ������ ����� �����ϰ� �б�� ������
� ���� �ּҰ����� �Ǵ��Ͽ� �׿� ���� ���� �Է��� �д�.
*/

#include <algorithm>
#include <functional>
#include <vector>
#include <map>    
#include <cstdio>
#include <string>
#include <queue>
#include <limits.h>
#include <stack>
#include <set>
#include <math.h>
#include <cstring>
using namespace std;

int n, w, x, y, dp[1010][1010];
vector<pair<int, int > > v;
pair<int, int > chase[1010][1010];

//�Ÿ��� ��ȯ
int cal(int idx1, int idx2) {
	return abs(v[idx1].first - v[idx2].first) + abs(v[idx1].second - v[idx2].second);
}

//���� 1�� �������� left���� �԰�, 2�� �������� right���� ���� �� �ִ밪
int sol(int left, int right) {

	if (pos == w + 2) return 0;

	//���� ���� �� ����� �� ���� ���·� �˾Ƴ� �� �ִ�.
	int pos = max(left, right) + 1;

	int &ret = dp[left][right];
	if (ret != -1) return ret;

	int a = sol(pos, right) + cal(left, pos);
	int b = sol(left, pos) + cal(right, pos);

	//1�� �������� ���� ��찡 �ּҰ��� ���
	if (a < b) {
		chase[left][right] = make_pair(pos, right);
		return ret = a;
	}
	else {
		chase[left][right] = make_pair(left, pos);
		return ret = b;
	}
}
void func(int left, int right) {

	int nl = chase[left][right].first, nr = chase[left][right].second;

	if (chase[left][right] == make_pair(0, 0)) return;
	int pos = max(left, right) + 1;
	
	//1�� �������� �̹� ����� ó���ߴٸ� 
	if (nl == pos) {
		printf("1\n");
		func(pos, right);
	}
	else {
		printf("2\n");
		func(left, pos);
	}
}
int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	memset(dp, -1, sizeof(dp));

	scanf("%d%d", &n, &w);
	//�ʱ⿡ 1�� �������� (1,1)�� �ְ�, 2�� �������� (n,n)�� �ִ�.
	v.push_back(make_pair(1, 1));
	v.push_back(make_pair(n, n));

	for (int i = 0; i < w; i++) {
		scanf("%d%d", &x, &y);
		v.push_back(make_pair(x, y));
	}
	printf("%d\n", sol(0, 1));
	func(0, 1);
}