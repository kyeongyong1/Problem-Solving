/*

���� d��ŭ ������ ���� �������� ��ġ�� ���̰� p���� �������� ������
������ ���̴� li, �뷮�� ci �̴�.
�̶� �������� �뷮�� �װ��� �̷�� ���������� �뷮 �� �ּҰ��̰�
�������� ���̴� ���������� ������ ���̴�. �̶� �ִ� ������ �뷮�� ���ϴ� ����

dp[i] -> ���� i ���� ����������, �ִ� ������ �뷮

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
	//���̰� d��� ������ �뷮�� pq�� �ִ´�.
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

		//cmp[j] -> ���� j���� ���� ��, �������� �ּ� �뷮
		for (int j = l; j <= d; j++) 
			if (dp[j - l] != INF) cmp[j] = min(dp[j - l], c);
		
		for (int j = l; j <= d; j++) {
			//���� j���� �������� ��ġ�� �� ������ continue
			if (cmp[j] == RETURN) continue;

			//dp[j]�� �������� �ִ� �뷮�� ����
			if (dp[j] != INF)
				dp[j] = max(dp[j], cmp[j]);
			else
				dp[j] = cmp[j];
			
			//d���� �Դٸ� ���ϰ��� �ϴ� ���̹Ƿ� pq�� push
			if (j == d)
				if (dp[j] != INF) pq.push(dp[j]);
		}

		//dp[l] ����
		if (dp[l] != INF) 
			dp[l] = max(dp[l], c);
		else
			dp[l] = c;
	}
	printf("%d\n", pq.top());

	return 0;
}