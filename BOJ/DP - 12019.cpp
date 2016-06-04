/*

동아리 방의 더러움은 사람이 a명 들어오고 나가면 a만큼 증가한다.
사람들이 느낀 불쾌감은 동아리 방의 더러움과 같고 현재 동아리 방의
더러움이 b이고 다녀간 사람이 c명 이라면 총 불쾌감은 b*c가 된다.

청소는 저녁에 모든 사람들이 다녀간 후에 하는데, 청소를 하고 나면
더러움이 0이 된다. 단, N일 중에 M번만 한다.

 DP 과정 
pos정보가 있어야 될 것 같았고, pos까지 왔을때, '언제' 청소했는지에
대한 정보가 있어야 될 것 같았다. 청소한 pos에 대해서 비트마스크를
생각했으나 N이 최대 100이라 비트마스크를 사용하면 테이블이 정의되지
않는다. 언제 청소했는지에 대한 정보를 알기 힘들다면 현재 위치까지
왔을때 더러움에 대한 정보가 필요할 것 같았다. 또, 청소 몇번 했는지에
대한 정보까지도 필요했다. 3개의 정보가 필요했고 그에 따라 
dp테이블을 정의했다. 

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
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const ll MOD = 1000007;
const int MAX_SIZE = 10000010;
const int INF = 0x3f3f3f3f;

int n, m, p, dp[105][2010][10];
vector<int> v;

int sol(int pos, int dirty, int scnt) {

	if (pos == n) {
		if (scnt == m) return 0;
		else return INF;
	}
	if (scnt > m) return INF;

	int &ret = dp[pos][dirty][scnt];
	if (ret != -1) return ret;

	//pos일날 불쾌감을 더해준다.
	ret = v[pos] * dirty;

	int a = INF, b = INF;
	//청소를 할수있다면, 청소를 하고 dirty는 0이다.
	if (scnt < m) a = sol(pos + 1, 0, scnt + 1);
	//청소를 안한다면 더러움이 증가한다.
	b = sol(pos + 1, dirty + v[pos], scnt);

	ret += min(a, b);
	return ret;
}
//경로 추적 하는 함수
void printL(int curSum, int pos, int dirty, int scnt) {

	//pos일에 느낀 불쾌감을 빼고
	curSum -= v[pos] * dirty;

	if (pos == n - 1) {
		if (scnt == m - 1) printf("%d ", pos + 1);
		return;
	}
	//청소를 한 테이블값과 안한 테이블값 중 남은 불쾌감 값과
	//같은 곳으로 재귀를 호출한다.
	if (curSum == dp[pos + 1][0][scnt + 1]) {
		printf("%d ", pos + 1);
		printL(curSum, pos + 1, 0, scnt + 1);
	}
	else
		printL(curSum, pos + 1, dirty + v[pos], scnt);
}
int main() {

	memset(dp, -1, sizeof(dp));

	scanf("%d %d", &n, &m);
	v.resize(n);

	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	int res = sol(0, 0, 0);
	printf("%d\n", res);
	printL(res, 0, 0, 0);
	printf("\n");
}