/*

아이스크림이 n개 있을때, 같이 먹으면 안되는 아이스크림의 쌍이
m개 주어진다. 이 때, 아이스크림을 맛있게 먹을 수 있는 방법의 수

전형적인 벡트레킹 문제

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

const ll MOD = 1000000007;
const int RETURN = 1061109567;
const int INF = 987654321;
const int MAX_SIZE = 100000 * 4;
const int MAX_NUM = 1000001;
const ll INFF = 9876543212345;
const int MAX_V = 410;

int n, m, a, b, nm[210][210], cnt = 0;
vector<int> v;
void sol(int ic) {

	if (v.size() == 3) {
		for (int i = 0; i < 3; i++) 
			for (int j = 0; j < 3; j++) 
				if (nm[v[i]][v[j]] == 1) return;
		cnt++;
		return;
	}
	for (int i = ic + 1; i <= n; i++) {
		v.push_back(i);
		sol(i);
		v.pop_back();
	}
}

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		nm[a][b] = 1, nm[b][a] = 1;
	}
	for (int i = 1; i <= n - 2; i++) {
		v.push_back(i);
		sol(i);
		v.pop_back();
	}

	printf("%d\n", cnt);
}