/*

너비가 일정한 노트에 이름을 쓸건데, 각 줄의 끝에 남는 
칸 수의 제곱의 합이 최소가 되는 값을 출력하는 문제

dp[i][j] -> i번째 글자까지 봤고 현재 행에서 j칸이 남았을 때 최소값

LEN=i번째 글자의 길이

dp[i][j] = min(dp[i-1][j-LEN], dp[i-1][m-LEN]+(남은 칸 수의 제곱)) 

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