/*

입력 받을 때마다 이진 검색 트리를 모델링 할껀데, 각각의
높이를 다 더한 값을 구하는 문제

입력을 받을 때마다 정렬을 시켜 놓는다. 이번에 insert할 값은
정렬 시켜놓은 배열 중에서 정렬될 위치는 명백하다.
어느쪽으로 트리가 만들어지는 지는 둘 중 비교한 다음에 더 나중에
입력받은 값 밑으로 트리가 만들어 지게 된다.

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

typedef long long ll;

const int INF = 987654321;
const ll INFF = 987654321213;
const ll MOD = 987654321;
const ll PLUS = 1000000;

int n, height[250010], a;
set<pair<int, int > > ms;

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	ll sum = 0;

	scanf("%d%d", &n, &a);
	ms.insert(make_pair(a, 0));
	height[a] = 1;

	for (int i = 1; i < n; i++) {
		scanf("%d", &a);

		auto it = ms.lower_bound(make_pair(a, -1));

		//맨 처음이나 맨 끝이라면 찾고자 하는 노드는 유일하다.
		if (it == ms.begin())
			height[a] = height[(*it).first] + 1;
		else if (it == ms.end())
			height[a] = height[(*(--it)).first] + 1;
		else {
			auto pre = (--it); it++;

			//나중에 입력받은 인덱스의 노드에 자식으로 연결한다.
			if (pre->second > it->second)
				height[a] = height[pre->first] + 1;
			else
				height[a] = height[it->first] + 1;
		}

		sum += (ll)height[a];
		ms.insert(make_pair(a, i));
	}
	printf("%lld\n", sum + 1);
}