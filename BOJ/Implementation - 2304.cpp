/*

기둥이 주어질때, 만들 수 있는 면적이 가장 작은 창고 
다각형의 크기를 출력하는 문제

왼쪽 기둥부터 시작했을 때, 만들 수 있는 면적이 작은 창고 다각형에
'색칠'을 한다. 오른쪽 기둥부터 시작했을 때, 만들 수 있는 면적이 작은
창고 다각형에 '색칠'을 한다. 2번색칠 되어 있는 곳이 구하고자 하는
면적이 가장 작은 창고 다각형의 크기가 된다.

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

int n, d[1010][1010];
vector<pair<int, int> > v;

int main() {

	scanf("%d", &n);
	v.resize(n);

	for (int i = 0; i < n; i++)
		scanf("%d%d", &v[i].first, &v[i].second);

	sort(v.begin(), v.end());

	//왼쪽 기둥을 색칠
	for (int i = 0; i < v[0].second; i++)
		d[i][v[0].first]++;
	//오른쪽 기둥을 색칠
	for (int i = 0; i < v.back().second; i++)
		d[i][v.back().first]++;

	//맨 왼쪽부터 보면서 색칠해 나간다.
	int rh = v[0].second;
	for (int i = 1; i < v.size(); i++) {
		for (int j = v[i - 1].first; j < v[i].first; j++)
			for (int k = 0; k < rh; k++)
				d[k][j]++;
		rh = max(rh, v[i].second);
	}

	//맨 오른쪽부터 보면서 색칠해 나간다.
	rh = v.back().second;
	for (int i = v.size() - 2; i >= 0; i--) {
		for (int j = v[i].first + 1; j < v[i + 1].first + 1; j++) 
			for (int k = 0; k < rh; k++) 
				d[k][j]++;
		rh = max(rh, v[i].second);
	}

	int res = 0;
	for (int i = 0; i < 1010; i++) 
		for (int j = 0; j < 1010; j++) 
			if (d[i][j] == 2) res++;
	printf("%d\n", res);
}