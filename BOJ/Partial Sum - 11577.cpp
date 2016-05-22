/*

전구가 있을때, 한 개의 전구를 키거나 끄면 연속된 k개의
전구 모두가 반전이 된다. (on->off , off->on)

모든 전구를 끌 수 있는 최소한의 조작 횟수를 출력하는 문제이다.
단순하게 구현하면 n이 100,000이고 k도 100,000이므로 TL이 뜬다.

따라서 현재 전구를 눌렀을 때, 오른쪽으로 k개의 전구가 켜졌다는
표시를 'partial sum'을 이용하여 구현하였다. 그렇게 되면 
시간복잡도 O(n)으로 이 문제를 해결할 수 있다.

시작 index의 값을 +1 해주고 끝나는 index+1의 값을 -1 해주면
partial sum을 누적하게 되면 전구가 몇번 눌러졌는지 알 수 있다.

*/

#include <vector>  
#include <cstdio>
using namespace std;

int n, k, psum[100010];
vector<int> v;

int main() {
	scanf("%d %d", &n, &k);
	v.resize(n + 1);

	for (int i = 1; i <= n; i++)
		scanf("%d", &v[i]);

	int cnt = 0;
	for (int i = 1; i <= n - k + 1; i++) {
		psum[i] += psum[i - 1];
		if ((psum[i] + v[i]) % 2 == 1) {
			if (i + k < (n + 2)) psum[i + k]--;
			psum[i]++, cnt++;
		}
	}
	for (int i = n - k + 2; i <= n; i++) {
		psum[i] += psum[i - 1];
		if ((psum[i] + v[i]) % 2 == 1) {
			printf("Insomnia\n"); return 0;
		}
	}
	printf("%d\n", cnt);
}