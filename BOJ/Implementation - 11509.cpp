/*

��� ǳ���� �Ͷ߸��� �ʿ��� �ּ� ������ ȭ���� ���ϴ� ����

arr[i] => i��° ���̿� ǳ���� �ִٴ� ���� ǥ��
���� ���̺��� +1 ���̿� ǳ���� �־����� �� ǳ���� �Ͷ߸���
���� ǳ���� �Ͷ߸� �� �ִ�. �ƴ� ��쿡�� ���� ������
ǳ���� �Ͷ߸��� ���ؼ� ���� ȭ���� ��� �Ѵ�.

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

int n, h, arr[1000010];

int main() {

	scanf("%d", &n);

	int res = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &h);
		if (arr[h + 1])
			arr[h + 1]--;
		else
			res++;
		arr[h]++;
	}
	printf("%d\n", res);
}