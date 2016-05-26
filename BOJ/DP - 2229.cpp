/*

조를 짜게 되는데 조가 잘 짜여진 정도의 최대값을 출력하는 문제이다.
각각의 조가 잘 짜여진 정도란 같은 조에 속하게 된 학생들의 가장 높은 점수와
가장 낮은 점수의 차이가 된다. 한명으로 조가 구성된 경우에는 그 조의 잘 짜여진
정도는 0이 된다. 전체적으로 조가 잘 짜여진 정도는 각각의 조가 잘 짜여진 정도의
합으로 나타낸다.

dp[i] => i+1 명까지 조가 잘짜여진 정도의 최대값

dp[i] = dp[i-k] + ((i-k+1 ~ i) 중 최대 점수과 최소 점수의 차이) (단, 1<=k<=i ) 
*/

#include <algorithm>
#include <vector>  
#include <cstdio>
#include <cstring>
using namespace std;

const int INF = 987654321;
int n, a, dp[1010];
vector<int> v;
int sol(int idx) {
	
	int &ret = dp[idx];
	if (ret != -1) return ret;
	
	int minn = INF, maxx = -INF;
	ret = 0;
	
	for (int i = idx - 1; i >= 0; i--) {
		minn = min(minn, v[i]), maxx = max(maxx, v[i]);
		ret = max(ret, sol(i) + maxx - minn);
	}
	
	return ret;
}
int main() {

	memset(dp, -1, sizeof(dp));
	
	scanf("%d", &n);
	v.resize(n);
	
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	printf("%d\n", sol(n));

}