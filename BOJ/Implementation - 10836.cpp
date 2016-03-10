/*
������ ���� ��Ģ�� ���� �ֹ����� �ڶ�� �� ������ ���� 
�ֹ����� ũ�⸦ ����ϴ� �����̴�.

�ֹ����� ���� ���� ����, ���� ���� ���� �ֹ������� �ڽ��� �ڶ�� ������
������ �����ϰ� ������ �ֹ������� ����, ���ʰ� ���� ����, ������ �ֹ�������
���Ͽ� ���� ���� �ڶ� ��ŭ �ڽŵ� �ڶ���.

�� �ϸ��� �ֹ����� ũ�⸦ ����ϴ� ���̴�. 
�̴� O(M^2 x N)�� �ð����⵵�� �ɸ��Ƿ� TL�̴�.

���ݸ� �� �����غ��� �� �ϸ��� ����� �ʿ� ���� ������ �ڶ�� �ֹ����鸸 ������ �� ���� ����� �ϰ� �� �Ŀ�
������ �ֹ������� ����ص� ������ �����Ѵ�. �� �ϸ��� �ֹ������� ����� �Ҷ����� ������ �ڶ�� �ֹ������� 
�ڶ�� ������ ������ ���� �ʰ�  ������ �ֹ������� ������ �ڶ�� �ֹ��������׸� ������ �ޱ� �����̴�.
������ �ֹ������� ����, ���� �밢����, ���� 3���� ��츦 ���Ѵ�. �� �� ���� ū���� '�׻� ����'�̴�.

�ð����⵵�� O(m)�̴�.

input ó���� �ణ ��ٷο �� ���ʿ����� �� ��������� ������� 0�� ����, 1�� ����, 2�� ���� �̷��� �־����Ƿ� �κ����� �̿��Ͽ���.
0�� ������ 1�� ������ ������ ��ġ�� 1�� ������Ű�� �� �迭�� �̿��Ͽ� �κ����� �ϰ� �Ǹ� �� ��ġ������ �������� �ֹ����� �ڶ� ������ �� �� �ִ�.

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
#include <math.h>
#include <cstring>
using namespace std;

int m, n, arr[710][710], temp[710][710], a, b, c, sum[1500], psum[1500];

int main()
{

	scanf("%d%d", &m, &n);

	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = 1;

	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &a, &b, &c);
		sum[a]++; sum[a + b]++;
	}
	psum[0] = sum[0];
	
	for (int i = 1; i < 2 * m - 1; i++)
		psum[i] = psum[i - 1] + sum[i];

	int idx = 0;
	for (int i = m - 1; i >= 0; i--)
		arr[i][0] += psum[idx++];
	for (int i = 1; i < m; i++)
		arr[0][i] += psum[idx++];

	for (int i = 1; i < m; i++) 
		for (int j = 1; j < m; j++) 
			arr[i][j] = arr[i - 1][j];
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}