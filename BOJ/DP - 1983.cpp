/*

�� ���� �迭�� �־�����, ���� ��ġ������ �� �迭�� ���� ����
���� ũ�� �Ǵ� ���� ����ϴ� �����̴�.

�̶�, ĭ�� ����ִ� ĭ���� �� �� �ִµ� �̶��� ���� 0�� �ȴ�.
����, �迭�� ������ ���� ���Ѿ� �Ѵ�.

*/

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>    
#include <cstdio>
#include <string>
#include <queue>
#include <limits.h>
#include <stack>
#include <math.h>
#include <cstring>
using namespace std;

const int RETURN = 1061109567;
const int INF = 987654321;

int n, a, dp[410][410][410];
vector<int> v1, v2;

//���� pos��° ��ġ�̰�, ù��° �迭�� idx1 index���� �԰�
//�ι�° �迭�� idx2 index ���� ���� �� �ִ밪
int sol(int pos, int idx1, int idx2) {

	if (pos == n) {
		if (idx1 == v1.size() && idx2 == v2.size())
			return 0;
		return -INF;
	}

	int &ret = dp[pos][idx1][idx2];
	if (ret != RETURN) return ret;

	ret = -INF;

	//idx1�� ���� ���� �ʾ��� ��
	if (idx1<v1.size()) ret = max(ret, sol(pos + 1, idx1 + 1, idx2));
	//idx2�� ���� ���� �ʾ��� ��
	if (idx2<v2.size()) ret = max(ret, sol(pos + 1, idx1, idx2 + 1));
	//idx1, idx2�� �������� ��
	if (idx1<v1.size() && idx2<v2.size()) ret = max(ret, sol(pos + 1, idx1 + 1, idx2 + 1) + v1[idx1] * v2[idx2]);

	if (idx1 == v1.size() && idx2 == v2.size()) ret = 0;

	return ret;
}
int main()
{

	memset(dp, 0x3f, sizeof(dp));

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == 0) continue;
		v1.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == 0) continue;
		v2.push_back(a);
	}
	cout << sol(0, 0, 0) << endl;
}