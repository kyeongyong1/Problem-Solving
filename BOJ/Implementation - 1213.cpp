/*
� ���ڿ��� ���ؼ� �Ӹ������ ���� �� �ִٸ�
���������� �ռ��� ���� ����ϴ� ����

�Ӹ���� ����� �ִ� ���
1. ��� ���ڰ� ¦������ ���
 ���ڿ� ������ ���� ���ĺ� �տ������� ¦������ ���� ä���
�������� ���ĺ� �ڿ������� ¦������ ���� ä���.

2. Ȧ������ ���ڰ� 1�����̰� �������� ¦������ ���
 1���� ���� ���� �ٸ����� ���ڿ� ����� Ȧ������ ����
1���� ����ֱ⸸ �ϸ� �ȴ�.
*/

#include <algorithm>
#include <functional>
#include <vector>
#include <map>    
#include <cstdio>
#include <string>
#include <queue>
#include <limits.h>
#include <stack>
#include <set>
#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;

int alpha[27];
string str, sol;

bool p(int l, int r) {
	if (l >= r) return true;

	if (sol[l] == sol[r]) return p(l + 1, r - 1);
	return false;
}
int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		alpha[str[i] - 'A']++;
	}
	for (int i = 0; i <= 26; i++) {
		for (int j = 0; j < alpha[i] / 2; j++)
			sol.push_back(i + 'A');
	}
	for (int i = 0; i <= 26; i++) {
		if (alpha[i] % 2 == 1) sol.push_back(i + 'A');
		alpha[i] /= 2;
	}
	for (int i = 26; i >= 0; i--) {
		for (int j = 0; j < alpha[i]; j++)
			sol.push_back(i + 'A');
	}
	if (p(0, sol.size() - 1)) cout << sol << endl;
	else cout << "I'm Sorry Hansoo" << endl;
}