/*

명제가 주어지고 이 명제에 대해서 증명될 수 있는 명제의 개수와
명제를 출력하는 문제

A => B 의 관계를 배열을 이용하여 초기화 한다. 

A => B		 A => B
B => C 라면  A => C
			 B => C

를 모두 출력해야 한다. 이는 A 정점에서 C 정점으로 갈 수 있는지
없는지에 대해서 조사하면 된다. 이는 floyd warshall를 이용하여 구현할 수 있다.

*/

#include <algorithm>
#include <vector>  
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;

int n, dist[55][55];

int main() {

	memset(dist, 0x3f, sizeof(dist));

	scanf("%d", &n);

	while (n--) {

		getchar();

		char ch1, ch2[3], ch3;
		scanf("%c %s %c", &ch1, &ch2, &ch3);

		int n1 = ch1 <= 'Z' ? ch1 - 'A' : ch1 - 'a' + 26;
		int n2 = ch3 <= 'Z' ? ch3 - 'A' : ch3 - 'a' + 26;

		if (n1 == n2) continue;
		dist[n1][n2] = 1;
	}

	for (int i = 0; i < 52; i++)
		for (int j = 0; j < 52; j++)
			for (int k = 0; k < 52; k++)
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);

	int cnt = 0;
	for (int i = 0; i < 52; i++) {
		for (int j = 0; j < 52; j++) {
			if (i == j) continue;
			if (dist[i][j] != 0x3f3f3f3f) cnt++;
		}
	}
	printf("%d\n", cnt);

	for (int i = 0; i < 52; i++) {
		for (int j = 0; j < 52; j++) {
			if (i == j) continue;
			if (dist[i][j] != 0x3f3f3f3f) {

				char temp1 = 'A', temp2 = 'A';
				if (i >= 26) temp1 = 'a' - 26;
				if (j >= 26) temp2 = 'a' - 26;
				printf("%c => %c\n", i + temp1, j + temp2);
			}
		}
	}
}