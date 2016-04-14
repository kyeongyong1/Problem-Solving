/*

���ڿ� S�� �ִµ� ���ڿ� S�� ���ĺ� ������� ����Ϸ��� �Ѵ�.
�̶� Ŀ���� ���ʰ� ���������� �ű�� Ű��, �ش� ���ڸ� ȭ�鿡
����ϴ� Ű 3���� ���� ��, Ű�� �Է��� �ּҷ� �ϴ� ���� ���ϴ� ����

dp[26][2]
dp[i][j] i�� 0�̸� 'a', 25�̸� 'z' �� �� i���ĺ� ���� �ð� 
		 s�� 0�̸� ���ʿ��� ������ ��, 1�̸� �����ʿ��� ������ ��
		 �� �ּڰ��̴�.


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

int dp[26][2], strSize, cnt = 0;
char str[1010], stAl;
bool visited[26];

//������ġ, ��������ġ, ���ĺ� ����
struct Data {
	int stIdx, laIdx, cnt;
	Data() {};
	Data(int a, int b, int c) {
		stIdx = a, laIdx = b, cnt = c;
	}
};
Data d[26];

//s�� 0�̸� ���ʿ��� ������ �� �ּڰ�
int sol(int al, int s) {

	if (al == 26) return 0;

	int &ret = dp[al][s];
	if (ret != -1) return ret;

	//���� ���ĺ��� ���Ѵ�.
	int nextal = -1;

	for (int i = al + 1; i < 26; i++) {
		if (visited[i] == true) {
			nextal = i; break;
		}
	}
	//�ش� ���ĺ��� ������ ���ĺ� �̶��
	if (nextal == -1) 
		return ret = abs(d[al].laIdx - d[al].stIdx) + d[al].cnt;

	int nLeft = d[nextal].stIdx, nRight = d[nextal].laIdx;
	int cLeft = d[al].stIdx, cRight = d[al].laIdx;
	int Ccnt = d[al].cnt;
	
	//���ʿ��� ������ ��쿡�� ���� ���ĺ��� ���ʿ��� ������ ����
	//�����ʿ��� ������ ��� �� ���� ���� �ش� �Լ��� ret ���̴�.
	if (s == 0) {
		ret = min(sol(nextal, 0) + abs(nRight - cLeft) + abs(cRight - cLeft) + Ccnt
			, sol(nextal, 1) + abs(nLeft - cLeft) + abs(cRight - cLeft) + Ccnt);
	}
	else {
		ret = min(sol(nextal, 0) + abs(nRight - cRight) + abs(cRight - cLeft) + Ccnt,
			sol(nextal, 1) + abs(nLeft - cRight) + abs(cRight - cLeft) + Ccnt);
	}

	return ret;
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	memset(dp, -1, sizeof(dp));

	scanf("%s", &str);
	strSize = strlen(str);

	//���� ���� ���ĺ�
	stAl = -1;

	for (int i = 0; i < 26; i++) {
		int s = -1, l = -1, cnt = 0;
		for (int j = 0; j < strSize; j++) {
			if (str[j] == 'a' + i) {
				if (s == -1) s = j;
				l = j; cnt++;
			}
		}
		if (s != -1 && stAl == -1) stAl = i;
		if (s != -1) visited[i] = true;
		
		//�ش� ���ĺ��� ���ٸ� '��'�� ���ĺ��� ������ġ, ��������ġ�� �ʱ�ȭ �Ѵ�.
		if (i == 0) 
			if (s + l == -2) s = 0, l = 0;
		else {
			if (s + l == -2) s = d[i - 1].stIdx, l = d[i - 1].laIdx;
		}
		d[i] = { s, l, cnt };
	}
	//ù��° ���ĺ��� �����ʿ��� ��������, ���ʿ��� �������� �ּҰ� �� �������� ��
	printf("%d\n", min(sol(stAl, 0) + d[stAl].laIdx, sol(stAl, 1) + d[stAl].stIdx));
}