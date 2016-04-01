/*

홍준이의 시야 범위가 M일때, 그 범위안에 가장 큰 광고판의 세기를
출력하는 문제이다. 시야의 범위는 현재 위치에서 앞뒤로 M칸까지 이다.

현재의 위치에서 광고판의 세기를 모두 multiset을 이용하여 가지고 있는다.
다음 위치가 되면 전 위치의 광고판의 세기를 지워주고 현재 위치 광고판의 
세기를 추가한다. 출력할때는 multiset에서 가장 큰 값을 뽑아 출력한다.

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

int n, m;
multiset<int> ms;
vector<int> v;

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d%d", &n, &m);
	v.resize(n);

	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	for (int i = 0; i < 2 * m - 1; i++) {
		if (i >= n) break;
		ms.insert(v[i]);
	}

	for (int i = m - 1; i < n - m + 1; i++) {

		//multiset에서 가장 큰 값
		auto it = ms.end(); it--;
		printf("%d ", *it);

		//전의 위치를 지워주고 다음 위치를 넣어준다.
		int pre = i - (m - 1), next = i + m;
		it = ms.lower_bound(v[pre]); ms.erase(it);
		if (next<n) ms.insert(v[next]);
	}
	printf("\n");


}