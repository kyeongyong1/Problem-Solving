/*

�� �����غ��� �ϴ� ���� ����

N���� �߸� ����� 1�̻� M������ ���Ը� ���� �� �ִٰ� �ϸ�
N+1��°�� ������ ���� ���԰� M+1���� �۰ų� ������ N+1��° �߸� ����Ͽ�
'( M + (N+1)���� ���� )' �� ���� �� �ִ�. 

*/


#include <algorithm>
#include <functional>
#include <vector>
#include <map>    
#include <cstdio>
#include <queue>
#include <limits.h>
#include <stack>
#include <stdio.h>
#include <set>
#include <math.h>
#include <cstring>
using namespace std;

int n, m, cur;
vector<int> v;

int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		v.push_back(m);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		//i��° ���� ���԰� ������� ���� �� �ִ� ���� ���� M���� 1
		//���Ѱ� ���� �۰ų� ���ٸ�
		if (cur + 1 >= v[i])
			cur += v[i];
		else
			break;
	}
	printf("%d\n", cur + 1);
	return 0;
}