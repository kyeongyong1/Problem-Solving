/*

좀 생각해봐야 하는 구현 문제

N개의 추를 사용해 1이상 M이하의 무게를 만들 수 있다고 하면
N+1번째로 가벼운 추의 무게가 M+1보다 작거나 같으면 N+1번째 추를 사용하여
'( M + (N+1)추의 무게 )' 를 만들 수 있다. 

*/


#include <algorithm>
#include <functional>
#include <vector>
#include <map>    
#include <cstdio>
#include <queue>
#include <limits.h>
#include <stack>
#include <stdio.h>
#include <set>
#include <math.h>
#include <cstring>
using namespace std;

int n, m, cur;
vector<int> v;

int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		v.push_back(m);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		//i번째 추의 무게가 현재까지 만들 수 있는 추의 무게 M에서 1
		//더한것 보다 작거나 같다면
		if (cur + 1 >= v[i])
			cur += v[i];
		else
			break;
	}
	printf("%d\n", cur + 1);
	return 0;
}