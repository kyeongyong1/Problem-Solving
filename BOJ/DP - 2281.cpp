/*

�ʺ� ������ ��Ʈ�� �̸��� ���ǵ�, �� ���� ���� ���� 
ĭ ���� ������ ���� �ּҰ� �Ǵ� ���� ����ϴ� ����

dp[i][j] -> i��° ���ڱ��� �ð� ���� �࿡�� jĭ�� ������ �� �ּҰ�

LEN=i��° ������ ����

dp[i][j] = min(dp[i-1][j-LEN], dp[i-1][m-LEN]+(���� ĭ ���� ����)) 

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
#include <math.h>
#include <cstring>
using namespace std;

int n, m, a, dp[1010][1010];
vector<int> v;

int cal(int r_v) {
	return r_v*r_v;
}
int sol(int pos, int remain_value) {

	int name_length = v[pos] + 1;
	//if (remain_value == m) name_length--;

	int &ret = dp[pos][remain_value];
	if (ret != -1) return ret;

	if (pos == n - 1) {
		if (remain_value >= name_length)
			return ret = 0;
		else
			return ret = cal(remain_value);
	}
	ret = 0;

	if (remain_value - name_length >= 0)
		ret = min(sol(pos + 1, remain_value - name_length), sol(pos + 1, m - (name_length - 1)) + cal(remain_value));
	else ret = sol(pos + 1, m - (name_length - 1)) + cal(remain_value);

	return ret;
}

int main()
{
	cin >> n >> m;

	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < n; i++) 
		cin >> a, v.push_back(a);
	
	cout << sol(1, m - (v[0])) << endl;
}