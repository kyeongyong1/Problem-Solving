/*

회사에서 사원을 채용하는데, 각각의 사원은 1차 시험과 2차 시험을 치르게 된다.
각각의 시험을 치르고 1위 부터 N위 까지 동석차 없이 결정된다.
이 때, 다른 모든 지원자와 비교했을 때 1차 시험과 2차 시험 성적 중 적어도 하나가
다른 지원자보다 떨어지지 않는 자만 선발한다는 원칙을 세웠다.
이 때 선발할 수 있는 최대 신입사원의 수는 얼마인지 출력하는 문제

거꾸로 생각하여 선발해서는 안되는 신입사원의 수를 계산하였다.
선발해서는 안되는 사원이란 1차 시험과 2차 시험 성적이 모두 '어떤 지원자' 보다
좋지 않은 경우이다. 1차 시험 성적이 좋은 순서대로 정렬한다. 1차 시험 성적이
좋은 순서부터 나쁜 순서까지 차례대로 볼 건데, 이 때 현재 보려고 하는 사원의
2차 시험 성적이 현재 까지 봤던 가장 성적이 좋은 2차 시험 성적 보다 좋지 않다면
현재 보고 있는 사원은 선발해서는 안된다. 왜냐하면 1차 시험 성적대로 정렬 했기 때문에
1차 시험 성적은 전에 봤던 사원보다 좋지 않을 것이기 때문이다.

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

int t, n, a, b;

int main() {

	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);
		vector<pair<int, int > > v;

		for (int i = 0; i < n; i++) {
			scanf("%d%d", &a, &b);
			v.push_back(make_pair(a, b));
		}
		sort(v.begin(), v.end());

		int minn = v[0].second;
		int cnt = 0;
		for (int i = 1; i < v.size(); i++) {
			if (minn < v[i].second) 
				cnt++;
			minn = min(minn, v[i].second);
		}
		printf("%d\n", n - cnt);
	}
}