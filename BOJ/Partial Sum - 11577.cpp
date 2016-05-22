/*

������ ������, �� ���� ������ Ű�ų� ���� ���ӵ� k����
���� ��ΰ� ������ �ȴ�. (on->off , off->on)

��� ������ �� �� �ִ� �ּ����� ���� Ƚ���� ����ϴ� �����̴�.
�ܼ��ϰ� �����ϸ� n�� 100,000�̰� k�� 100,000�̹Ƿ� TL�� ���.

���� ���� ������ ������ ��, ���������� k���� ������ �����ٴ�
ǥ�ø� 'partial sum'�� �̿��Ͽ� �����Ͽ���. �׷��� �Ǹ� 
�ð����⵵ O(n)���� �� ������ �ذ��� �� �ִ�.

���� index�� ���� +1 ���ְ� ������ index+1�� ���� -1 ���ָ�
partial sum�� �����ϰ� �Ǹ� ������ ��� ���������� �� �� �ִ�.

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