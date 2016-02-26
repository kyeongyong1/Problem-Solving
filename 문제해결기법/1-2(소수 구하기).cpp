//에라토스테네스의 체 이용
//소수를 시간복잡도 O(nloglogn)에 구하는 알고리즘
//소수의 배수는 소수가 아니다를 이용

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_N = 12000000;
int pn[MAX_N];

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	for (int i = 2; i < MAX_N; i++) {
		//이 수가 2번 체크되었으면 소수 일 수 없으므로 
		if (pn[i] >= 2) continue;
		//i의 배수에 대해서 표시
		for (int j = i; j < MAX_N; j += i) {
			pn[j]++;
		}
	}

	int t;
	cin >> t;

	while (t--) {
		int cnt = 0;
		int n; cin >> n;

		//체크가 한번 된건 모두 소수
		for (int i = 2; i<n; i++)
			if (pn[i] == 1) cnt++;

		cout << cnt << endl;
	}
}