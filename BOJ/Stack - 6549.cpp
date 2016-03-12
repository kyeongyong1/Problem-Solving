/*
stack을 이용한 유명한 문제

어떠한 사각형들에 대해서 사각형을 막는 판자들의 번호를 각각
left[i], right[i]라고 한다.

i번 판자를 봤는데, 왼쪽에 자신보다 높은 판자들이 남아 있다면
그들의 최대 사각형을 자신이 막고 있는 경우이다. 이들 전부에 대해
최다 사각형의 넓이를 계산하고 이들을 지워 버린다. 스택에는 i번 판자
왼쪽에는 자신보다 낮은 판자만이 남아 있게 된다. 
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

typedef long long ll;

int n;
vector<int> h;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	while (1) {
		scanf("%d", &n);
		if (n == 0) break;

		h.resize(n);
		for (int i = 0; i < n; i++)
			scanf("%d", &h[i]);
		//남아있는 판자들에 대해서 계산해 주기 위해서 0을 마지막에 넣는다.
		h.push_back(0);

		stack<int> s;

		ll ret = 0;
		for (int i = 0; i < h.size(); i++) {

			//i번째 판자보다 크거나 같은 판자들에 대해 최대 사각형을 계산한다.
			while (!s.empty() && h[s.top()] >= h[i]) {

				//j는 left[i]가 된다.
				int j = s.top();
				s.pop();

				int width = -1;
				if (s.empty())
					width = i;
				else
					width = (i - s.top() - 1);
				
				ret = max(ret, (ll)h[j] * (ll)width);
			}
			s.push(i);
		}
		printf("%lld\n", ret);
	}
}