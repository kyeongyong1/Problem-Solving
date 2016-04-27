/*

길이 d만큼 떨어진 곳에 수도관을 설치할 것이고 p개의 파이프가 있을때
각각의 길이는 li, 용량은 ci 이다.
이때 수도관의 용량을 그것을 이루는 파이프들의 용량 중 최소값이고
수도관의 길이는 파이프들의 길이의 합이다. 이때 최대 수도관 용량을 구하는 문제

dp[i] -> 길이 i 까지 연결했을때, 최대 수도관 용량

*/

#include <iostream>
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
typedef unsigned long long ull;

const int MOD = 10007;
const int RETURN = 1061109567;
const int INF = 987654321;
const int MAX_SIZE = 100000 * 10;
const int MAX_NUM = 1000000010;
const ll INFF = 9876543212345;

int d, p, li, ci, dp[100010], cmp[100010];
vector<pair<int, int > > v;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	for (int j = 0; j < 100010; j++)
		dp[j] = INF;

	scanf("%d%d", &d, &p);
	//길이가 d라면 수도관 용량을 pq에 넣는다.
	priority_queue<int> pq;

	for (int i = 0; i < p; i++) {
		scanf("%d%d", &li, &ci);
		if (li == d) {
			pq.push(ci); continue;
		}
		v.push_back(make_pair(li, ci));
	}

	for (int i = 0; i < p; i++) {
		memset(cmp, 0x3f, sizeof(cmp));
		int l = v[i].first, c = v[i].second;

		//cmp[j] -> 길이 j까지 왔을 때, 수도관의 최소 용량
		for (int j = l; j <= d; j++) 
			if (dp[j - l] != INF) cmp[j] = min(dp[j - l], c);
		
		for (int j = l; j <= d; j++) {
			//길이 j까지 수도관을 설치할 수 없으면 continue
			if (cmp[j] == RETURN) continue;

			//dp[j]에 수도관의 최대 용량을 저장
			if (dp[j] != INF)
				dp[j] = max(dp[j], cmp[j]);
			else
				dp[j] = cmp[j];
			
			//d까지 왔다면 구하고자 하는 값이므로 pq에 push
			if (j == d)
				if (dp[j] != INF) pq.push(dp[j]);
		}

		//dp[l] 갱신
		if (dp[l] != INF) 
			dp[l] = max(dp[l], c);
		else
			dp[l] = c;
	}
	printf("%d\n", pq.top());

	return 0;
}