/*

모든 풍선을 터뜨리는 필요한 최소 개수의 화살을 구하는 문제

arr[i] => i번째 높이에 풍선이 있다는 것을 표시
현재 높이보다 +1 높이에 풍선이 있었으면 그 풍선을 터뜨리고
현재 풍선을 터뜨릴 수 있다. 아닌 경우에는 현재 높이의
풍선을 터뜨리기 위해서 새로 화살을 써야 한다.

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

int n, h, arr[1000010];

int main() {

	scanf("%d", &n);

	int res = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &h);
		if (arr[h + 1])
			arr[h + 1]--;
		else
			res++;
		arr[h]++;
	}
	printf("%d\n", res);
}