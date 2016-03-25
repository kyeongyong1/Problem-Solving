/*

2���� Partial Sum ����

�÷����� ������ ���� ���� ���ڰ� �κ��� ��� 1�̶��
���� �밢����, ������ �밢����, ���� �밢���Ʒ�, ������ �밢���Ʒ���
���簢���� 1�� �����ؼ��� �ȵȴ�. ��ó���� �س��� Partial Sum�� �̿��ϸ�
����ð��� ���� �� �ִ�.

*/

#include <cstdio>

int n, psumO[2010][2010];
char dat[2010][2010];

bool isPo(int range) {
	if (range<1 || range >n) return false;
	return true;
}
int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		getchar();
		for (int j = 1; j <= n; j++)
			scanf("%c", &dat[i][j]);
	}
	//Psum ��ó��
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			psumO[i][j] = psumO[i - 1][j] + psumO[i][j - 1] - psumO[i - 1][j - 1] + (dat[i][j] - '0');
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dat[i][j] == '1') {
				int len = 1;

				while (1) {
					bool flag = false;
					int up = i - len, down = i + len, left = j - len, right = j + len;
					if (isPo(up) && isPo(down) && isPo(left) && isPo(right)) {
						if (dat[up][j] + dat[down][j] + dat[i][left] + dat[i][right] == 4 + 4 * '0') {
							int plus = len + 1;
							int leftUpSum = psumO[i - 1][j - 1] - psumO[i - len - 1][j - 1] - psumO[i - 1][j - len - 1] + psumO[i - len - 1][j - len - 1];
							int rightUpSum = psumO[i - 1][j - 1 + plus] - psumO[i - len - 1][j - 1 + plus] - psumO[i - 1][j - len - 1 + plus] + psumO[i - len - 1][j - len - 1 + plus];
							int leftDownSum = psumO[i - 1 + plus][j - 1] - psumO[i - len - 1 + plus][j - 1] - psumO[i - 1 + plus][j - len - 1] + psumO[i - len - 1 + plus][j - len - 1];
							int rightDownSum = psumO[i - 1 + plus][j - 1 + plus] - psumO[i - len - 1 + plus][j - 1 + plus] - psumO[i - 1 + plus][j - len - 1 + plus] + psumO[i - len - 1 + plus][j - len - 1 + plus];

							if (leftUpSum == 0 && rightUpSum == 0 && leftDownSum == 0 && rightDownSum == 0) {
								cnt++; len++; flag = true;
							}
						}
					}
					if (flag == false) break;
				}
			}
		}
	}
	printf("%d\n", cnt);
}