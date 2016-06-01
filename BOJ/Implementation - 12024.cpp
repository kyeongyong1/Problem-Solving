/*

cycle이 4인 경로의 '개수'를 찾으면 되는 문제이다.

bfs, dfs 여러가지 방법으로 해보고 TL이 난 문제
양방향 그래프이므로, 해당 정점에서 어느 정점까지
가는데 경로가 2라면 '어느' 정점에서 '해당' 정점까지 오는
경로도 2이다. 해당 정점에서 어느 정점까지 갔다가 어느 정점에서
해당 정점으로 오게 되면 cycle이 4인 경로가 된다.

cycle이 4인 경로는 경로가 2인 두 정점을 택하는 것이다.
경로의 개수는 '이쪽' 정점에서 '저쪽' 정점으로 가는 경로 중 하나를
택하고 '저쪽' 정점에서 '이쪽' 정점으로 올때는 하나 선택한 것을
제외하고 선택하면 된다.

*/


#include <algorithm>
#include <vector>  
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <functional>
#include <set>
#include <tuple>
using namespace std;

typedef long long ll;
const int MOD = 100000;
const int MAX_SIZE = 10000010;
const int INF = 0x3f3f3f3f;

ll n, dist[252][252], sol[252][252];

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%lld", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%lld", &dist[i][j]);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//i, j 정점이 연결되어 있으면
			if (dist[i][j] == 0) continue;
			//j 정점과 연결된 k 정점을 찾는다.
			//i 정점과 k 정점은 경로가 2이다.
			for (int k = 0; k < n; k++) {
				if (dist[j][k] && k != i) sol[i][k]++;
			}
		}
	}

	ll res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (sol[i][j]) res += sol[i][j] * (sol[i][j] - 1);
		}
	}
	printf("%lld\n", res);
}