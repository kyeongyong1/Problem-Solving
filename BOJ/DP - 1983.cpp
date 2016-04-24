/*

두 개의 배열이 주어질때, 같은 위치에서의 두 배열의 곱의 합이
가장 크게 되는 값을 출력하는 문제이다.

이때, 칸을 비어있는 칸으로 둘 수 있는데 이때는 곱이 0이 된다.
따라서, 배열의 순서는 유지 시켜야 한다.

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

const int RETURN = 1061109567;
const int INF = 987654321;

int n, a, dp[410][410][410];
vector<int> v1, v2;

//현재 pos번째 위치이고, 첫번째 배열의 idx1 index까지 왔고
//두번째 배열의 idx2 index 까지 왔을 때 최대값
int sol(int pos, int idx1, int idx2) {

	if (pos == n) {
		if (idx1 == v1.size() && idx2 == v2.size())
			return 0;
		return -INF;
	}

	int &ret = dp[pos][idx1][idx2];
	if (ret != RETURN) return ret;

	ret = -INF;

	//idx1을 선택 하지 않았을 때
	if (idx1<v1.size()) ret = max(ret, sol(pos + 1, idx1 + 1, idx2));
	//idx2를 선택 하지 않았을 때
	if (idx2<v2.size()) ret = max(ret, sol(pos + 1, idx1, idx2 + 1));
	//idx1, idx2를 선택했을 때
	if (idx1<v1.size() && idx2<v2.size()) ret = max(ret, sol(pos + 1, idx1 + 1, idx2 + 1) + v1[idx1] * v2[idx2]);

	if (idx1 == v1.size() && idx2 == v2.size()) ret = 0;

	return ret;
}
int main()
{

	memset(dp, 0x3f, sizeof(dp));

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == 0) continue;
		v1.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == 0) continue;
		v2.push_back(a);
	}
	cout << sol(0, 0, 0) << endl;
}