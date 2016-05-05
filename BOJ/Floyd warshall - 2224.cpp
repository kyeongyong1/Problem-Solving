/*

������ �־����� �� ������ ���ؼ� ����� �� �ִ� ������ ������
������ ����ϴ� ����

A => B �� ���踦 �迭�� �̿��Ͽ� �ʱ�ȭ �Ѵ�. 

A => B		 A => B
B => C ���  A => C
			 B => C

�� ��� ����ؾ� �Ѵ�. �̴� A �������� C �������� �� �� �ִ���
�������� ���ؼ� �����ϸ� �ȴ�. �̴� floyd warshall�� �̿��Ͽ� ������ �� �ִ�.

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