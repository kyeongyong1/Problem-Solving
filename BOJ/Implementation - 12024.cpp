/*

cycle�� 4�� ����� '����'�� ã���� �Ǵ� �����̴�.

bfs, dfs �������� ������� �غ��� TL�� �� ����
����� �׷����̹Ƿ�, �ش� �������� ��� ��������
���µ� ��ΰ� 2��� '���' �������� '�ش�' �������� ����
��ε� 2�̴�. �ش� �������� ��� �������� ���ٰ� ��� ��������
�ش� �������� ���� �Ǹ� cycle�� 4�� ��ΰ� �ȴ�.

cycle�� 4�� ��δ� ��ΰ� 2�� �� ������ ���ϴ� ���̴�.
����� ������ '����' �������� '����' �������� ���� ��� �� �ϳ���
���ϰ� '����' �������� '����' �������� �ö��� �ϳ� ������ ����
�����ϰ� �����ϸ� �ȴ�.

*/


#include <algorithm>
#include <vector>  
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <functional>
#include <set>
#include <tuple>
using namespace std;

typedef long long ll;
const int MOD = 100000;
const int MAX_SIZE = 10000010;
const int INF = 0x3f3f3f3f;

ll n, dist[252][252], sol[252][252];

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%lld", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%lld", &dist[i][j]);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//i, j ������ ����Ǿ� ������
			if (dist[i][j] == 0) continue;
			//j ������ ����� k ������ ã�´�.
			//i ������ k ������ ��ΰ� 2�̴�.
			for (int k = 0; k < n; k++) {
				if (dist[j][k] && k != i) sol[i][k]++;
			}
		}
	}

	ll res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (sol[i][j]) res += sol[i][j] * (sol[i][j] - 1);
		}
	}
	printf("%lld\n", res);
}