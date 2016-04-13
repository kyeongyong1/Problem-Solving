/*

Inversion sequence가 주어질 때, 해당하는 원래의 수열을 구하는 문제
inversion sequence 수열의 i번째 원소는 수열에서 i보다 뒤에
나오면서 i보다 작은 수의 개수이다. 

뒤에서 부터 보면서 자리를 정해주면 되는데, 해당 자리를 빠르게 구하기
위하여 인덱스 트리를 이용하여 구현 하였다. 

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

const int MAX_SIZE = 100000 * 4;

int n, tree[MAX_SIZE], a, tSize = 1;
vector<int> v, res;

void update(int pos, int val) {

	pos += tSize;
	tree[pos] += val;
	pos /= 2;
	while (pos) {
		tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
		pos /= 2;
	}
}
int read(int num) {
	int pos = 2;

	while (1) {
		if (pos >= tSize) {
			if (num == 2) 
				pos++;
			while (tree[pos] == 0) 
				pos++;
			break;
		}
		if (tree[pos] >= num)
			pos *= 2;
		else
			num -= tree[pos++];
	}
	return pos - tSize;

}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d", &n);
	while (tSize < n)
		tSize *= 2;

	v.resize(n), res.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	for (int i = 0; i < n; i++)
		update(i, 1);

	for (int i = n - 1; i >= 0; i--) {

		//해당 자리를 빠르게 구하고
		int idx = read(v[i] + 1);
		
		//해당 자리를 사용했다고 표시한다.
		update(idx, -1);
		res[idx] = i + 1;
	}
	for (int i = res.size() - 1; i >= 0; i--) 
		printf("%d ", res[i]);
	printf("\n");
}