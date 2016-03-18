/*

dp[left][right] -> left ���� right���� ��ġ�µ� ��� �ּ� ���

*/

#include <iostream>
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

const int INF = 987654321;

int t, k, psum[510], a, dp[510][510];
vector<int> v;

int sol(int left, int right) {

	int &ret = dp[left][right];
	if (ret != -1) return ret;

	//�ϳ� ���� ��쿡�� ��ġ�� ������ ���� �������� �ʴ´�.
	if (right == left) return ret = 0;
	if (right - 1 == left) return ret = v[left] + v[right];

	ret = INF;

	int ri = psum[right], li;
	if (left == 0) li = 0;
	else li = psum[left - 1];

	//left���� right���� 2�κ����� ���� �������� ����� �� ��
	//���� ���� ���� �����Ѵ�.
	for (int i = left; i < right; i++)
		ret = min(ret, sol(left, i) + sol(i + 1, right));

	//left���� right���� ��ġ�� �� ��� ����� �����ش�.
	ret += ri - li;
	return ret;
}
int main()
{
	scanf("%d", &t);
	while (t--) {

		v.clear();
		memset(dp, -1, sizeof(dp));

		scanf("%d", &k);
		for (int i = 0; i < k; i++) 
			scanf("%d", &a), v.push_back(a);
		
		psum[0] = v[0];
		for (int i = 1; i < k; i++)
			psum[i] = v[i] + psum[i - 1];

		printf("%d \n", sol(0, k - 1));
	}
}