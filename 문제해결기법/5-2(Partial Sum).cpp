//partial sum, DP ���̵�� �̿�
//���簢�� ���·�'��' 
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int main(void)
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	ios::sync_with_stdio(false);

	int m; cin >> m;

	while (m--) {
		//dp[i][j] -> (0,0) �� ���� �� ���������� �ϰ� (i,j) �� ������ �Ʒ� ���������� 
		//            �ϴ� ���簢���� �ش��ϴ� ������ ����
		int p, q, data[510][510], dp[510][510];
		memset(data, 0, sizeof(data));
		memset(dp, 0, sizeof(dp));
		cin >> p >> q;

		for (int i = 1; i <= p; i++) {
			for (int j = 1; j <= q; j++) {
				cin >> data[i][j];
				//dp���̺��� ä���.
				dp[i][j] = data[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
			}
		}

		int maxx = 0;

		//���簢���� ������ ���ϴ� �˰���
		for (int i = 1; i <= p; i++) 
			for (int j = 1; j <= q; j++) 
				for (int k = 1; k < min(i, j); k++) 
					maxx = max(maxx, dp[i][j] - dp[i - k][j] - dp[i][j - k] + dp[i - k][j - k]);
		
		cout << maxx << endl;
	}
}