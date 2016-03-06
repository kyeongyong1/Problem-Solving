/*
구간이 주어지고 구간 사이에 모두 색칠을 한다.
k번 색칠한 구간을 찾는 문제이다. 
메모리 제한이 2mb이기 때문에 10,000,000까지 
단순 부분합을 이용하기에는 제한이 있다.
부분합을 좀 똑똑하게 계산하였다.

벡터에 시작점과 끝나는점을 구별하여 넣어주어
2n개만 보고 부분합을 계산하였다.
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
using namespace std;

int t, n, k, a, b;
vector<pair<int, int > > v;

int main() {

	scanf("%d", &t);

	while (t--) {
		scanf("%d%d", &n, &k);

		//시작점은 1, 끝나는점은 -1
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &a, &b);
			v.push_back(make_pair(a, 1));
			v.push_back(make_pair(b + 1, -1));
		}
		sort(v.begin(), v.end());
		int cur = 0;
		vector<int> res;
		bool flag = false;
		for (int i = 0; i < v.size(); i++) {
			cur += v[i].second;

			//시작하는 구간이 set되어 있고, 현재 구간의 색칠한 횟수가
			//k+1이거나 k-1이라면 그 전 구간까지가 끝나는 구간이다.
			if (abs(cur - k) == 1 && flag == true) {
				res.push_back(v[i].first - 1);
				flag = false;
			}
			//시작하는 구간을 찾는다.
			if (i != v.size() - 1 && v[i].first != v[i + 1].first && cur == k) {
				res.push_back(v[i].first);
				flag = true;
			}
		}
		//시작하는 구간과 끝나는 구간을 res에 차례대로 넣었기 때문에
		//출력할때는 2개씩 출력해 준다.
		for (int i = 0; i < res.size(); i += 2) {
			printf("%d %d\n", res[i], res[i + 1]);
		}
		v.clear();
	}
}