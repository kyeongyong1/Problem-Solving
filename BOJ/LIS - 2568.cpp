/*
A전봇대의 위치 순서대로 정렬을 한다.
정렬한 순서에 대하여 B전봇대의 LIS를 찾으면 되는 문제이다.

n이 100,000이므로, n^2 시간복잡도를 가진 LIS 코드를 작성하면 TL이 난다.

nlogn 시간복잡도를 가진 효율적인 LIS이다.
lis벡터는 더 많은 최장 증가 수열을 만들 수 있는 후보를 가지고 있는 배열이다.
최장 증가 수열도 뽑아내야 하는 문제이므로, parent벡터를 이용하였다.

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

int n;
vector<pair<int, int > > v;
bool visited[500001];

int main() {

	scanf("%d", &n);
	v.resize(n);
	vector<int> parent(500001, -1);

	for (int i = 0; i < n; i++)
		scanf("%d%d", &v[i].first, &v[i].second);
	//A전봇대 위치 번호대로 정렬한다.
	sort(v.begin(), v.end());

	vector<int> lis;
	lis.push_back(v[0].second);

	for (int i = 1; i < n; i++) {
		if (lis.back() < v[i].second) {
			parent[v[i].second] = lis.back();
			lis.push_back(v[i].second);
		}
		else {
			auto it = lower_bound(lis.begin(), lis.end(), v[i].second);
			*it = v[i].second;
			if (it != lis.begin()) {
				parent[v[i].second] = *(--it);
			}
		}
	}
	printf("%d\n", n - lis.size());

	int cur = lis.back();
	for (int i = 0; i < lis.size(); i++) {
		visited[cur] = true;
		cur = parent[cur];
	}
	for (int i = 0; i < n; i++) {
		if (visited[v[i].second] == true) continue;
		printf("%d\n", v[i].first);
	}
}