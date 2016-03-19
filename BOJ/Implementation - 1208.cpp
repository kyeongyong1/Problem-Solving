/*

N개의 정수로 이루어진 집합이 있을 때, 부분집합의 
원소의 개수의 합이 S가 되는 경우의 수를 구하는 문제.

N이 40 이기 때문에, 2^40 인 단순 재귀를 돌려서는 TL이다.

N을 반으로 나눈 후에, 각각의 부분집합의 합을 가지고 있는 벡터를 구한다.
한 벡터의 원소를 res[i] 라고 하면 다른 벡터의 원소가 S-res[i]값이 
있다면 합이 S가 되는 경우의 수가 1개 있는 것이다.

한 벡터는 백만 개의 원소를 갖는다. 다른 벡터의 원소 S-res[i]를 찾을때는
이분 탐색을 이용하여 logn에 Search를 하면 시간안에 해결 가능하다.

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

int n, s, a;
vector<int> v1, v2, res1, res2;

void func1(int idx, int sum) {
	if (idx == v1.size()) {
		res1.push_back(sum); return;
	}
	func1(idx + 1, sum), func1(idx + 1, sum + v1[idx]);
}
void func2(int idx, int sum) {
	if (idx == v2.size()) {
		res2.push_back(sum); return;
	}
	func2(idx + 1, sum), func2(idx + 1, sum + v2[idx]);
}
int main() {

	scanf("%d%d", &n, &s);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (i % 2 == 0) v1.push_back(a);
		else v2.push_back(a);
	}
	//부분집합 원소의 합을 갖는 두 개의 벡터를 생성한다.
	func1(0, 0), func2(0, 0);

	//이분 탐색을 위해 정렬을 한다.
	sort(res2.begin(), res2.end());

	ll res = 0;
	
	for (int i = 0; i < res1.size(); i++) {
		res += (ll)(upper_bound(res2.begin(), res2.end(), s - res1[i])
			- lower_bound(res2.begin(), res2.end(), s - res1[i]));
	}
	//공집합인 경우 제외한다.
	if (s == 0) res--;
	printf("%lld\n", res);
}