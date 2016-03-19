/*

N���� ������ �̷���� ������ ���� ��, �κ������� 
������ ������ ���� S�� �Ǵ� ����� ���� ���ϴ� ����.

N�� 40 �̱� ������, 2^40 �� �ܼ� ��͸� �������� TL�̴�.

N�� ������ ���� �Ŀ�, ������ �κ������� ���� ������ �ִ� ���͸� ���Ѵ�.
�� ������ ���Ҹ� res[i] ��� �ϸ� �ٸ� ������ ���Ұ� S-res[i]���� 
�ִٸ� ���� S�� �Ǵ� ����� ���� 1�� �ִ� ���̴�.

�� ���ʹ� �鸸 ���� ���Ҹ� ���´�. �ٸ� ������ ���� S-res[i]�� ã������
�̺� Ž���� �̿��Ͽ� logn�� Search�� �ϸ� �ð��ȿ� �ذ� �����ϴ�.

*/

#include <algorithm>
#include <functional>
#include <vector>
#include <map>    
#include <cstdio>
#include <queue>
#include <limits.h>
#include <stack>
#include <set>
#include <math.h>
#include <cstring>
#include <list>
using namespace std;

typedef long long ll;

int n, s, a;
vector<int> v1, v2, res1, res2;

void func1(int idx, int sum) {
	if (idx == v1.size()) {
		res1.push_back(sum); return;
	}
	func1(idx + 1, sum), func1(idx + 1, sum + v1[idx]);
}
void func2(int idx, int sum) {
	if (idx == v2.size()) {
		res2.push_back(sum); return;
	}
	func2(idx + 1, sum), func2(idx + 1, sum + v2[idx]);
}
int main() {

	scanf("%d%d", &n, &s);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (i % 2 == 0) v1.push_back(a);
		else v2.push_back(a);
	}
	//�κ����� ������ ���� ���� �� ���� ���͸� �����Ѵ�.
	func1(0, 0), func2(0, 0);

	//�̺� Ž���� ���� ������ �Ѵ�.
	sort(res2.begin(), res2.end());

	ll res = 0;
	
	for (int i = 0; i < res1.size(); i++) {
		res += (ll)(upper_bound(res2.begin(), res2.end(), s - res1[i])
			- lower_bound(res2.begin(), res2.end(), s - res1[i]));
	}
	//�������� ��� �����Ѵ�.
	if (s == 0) res--;
	printf("%lld\n", res);
}