/*

Bubble Sort 한 step을 할 때마다 Sort가 완료 되었을때의 
배열의 자리에 한칸씩 다가가게 된다. 

정답은 입력받은 data의 index와 정렬된 배열의 index를 비교하여
인덱스 차이가 가장 큰 것이 문제의 정답이다.

*/

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>    
#include <cstdio>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int n, data[500010];
vector<int> v;
int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> data[i]; v.push_back(data[i]);
	}
	sort(v.begin(), v.end());

	int sol = 0;

	for (int i = 0; i < n; i++) {
		vector<int>::iterator it;

		it = lower_bound(v.begin(), v.end(), data[i]);
		sol = max(sol, i - (it - v.begin()));
		v[it - v.begin()]--;
	}
	cout << sol + 1 << endl;

}