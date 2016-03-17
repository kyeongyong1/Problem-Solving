/*
DP problem

dp[left][right] : 최근에 1번 경찰차가 left까지 왔고, 
				  2번 경찰차는 right까지 왔을 때 최대값.

추적도 해줘야 하는데 dp함수 내에서 계산을 각각하고 분기로 나눠서
어떤 값이 최소값인지 판단하여 그에 따른 값을 입력해 둔다.
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

//거리를 반환
int cal(int idx1, int idx2) {
	return abs(v[idx1].first - v[idx2].first) + abs(v[idx1].second - v[idx2].second);
}

//현재 1번 경찰차는 left까지 왔고, 2번 경찰차는 right까지 왔을 때 최대값
int sol(int left, int right) {

	if (pos == w + 2) return 0;

	//현재 봐야 할 사건은 두 개의 상태로 알아낼 수 있다.
	int pos = max(left, right) + 1;

	int &ret = dp[left][right];
	if (ret != -1) return ret;

	int a = sol(pos, right) + cal(left, pos);
	int b = sol(left, pos) + cal(right, pos);

	//1번 경찰차가 가는 경우가 최소값인 경우
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
	
	//1번 경찰차가 이번 사건을 처리했다면 
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
	//초기에 1번 경찰차는 (1,1)에 있고, 2번 경찰차는 (n,n)에 있다.
	v.push_back(make_pair(1, 1));
	v.push_back(make_pair(n, n));

	for (int i = 0; i < w; i++) {
		scanf("%d%d", &x, &y);
		v.push_back(make_pair(x, y));
	}
	printf("%d\n", sol(0, 1));
	func(0, 1);
}