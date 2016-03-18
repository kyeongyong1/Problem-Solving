/*

dp[left][right] -> left 부터 right까지 합치는데 드는 최소 비용

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

	//하나 남는 경우에는 합치지 않으니 값을 더해주지 않는다.
	if (right == left) return ret = 0;
	if (right - 1 == left) return ret = v[left] + v[right];

	ret = INF;

	int ri = psum[right], li;
	if (left == 0) li = 0;
	else li = psum[left - 1];

	//left부터 right까지 2부분으로 나눈 여러가지 경우의 수 중
	//가장 작은 값을 저장한다.
	for (int i = left; i < right; i++)
		ret = min(ret, sol(left, i) + sol(i + 1, right));

	//left부터 right까지 합치는 데 드는 비용을 더해준다.
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