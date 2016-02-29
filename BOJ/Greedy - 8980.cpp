/*
Greedy ���

��ȣ�� ���� ������ �ڽ��� ����ϴ� �ͺ���
��ȣ�� ���� ������ �ڽ��� ����ϴ� ���� �ּ��� ����
Ʈ���� �ִ� �뷮�� �ֱ� ����

�����ϴ� ��ȣ�� ������ ���ٸ� �����ϴ� ������ ��ȣ�� ���� ������
�����ϴ� ���� �ּ�

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

//arr[i] -> ������� i�� ������ ����ϴ� �ڽ��� �ִ� ����
int n, c, m, arr[2010];

struct inf {
	int a, b, t;
};
inf inff[10010];

bool cmp(inf x, inf z) {
	if (x.b != z.b) return x.b < z.b;
	return x.a > z.a;
}

int main(int argc, char** argv) {

	scanf("%d%d%d", &n, &c, &m);

	for (int i = 0; i < m; i++) 
		scanf("%d%d%d", &inff[i].a, &inff[i].b, &inff[i].t);
	
	//���� ������ ��ȣ�� ���� ������� ����
	sort(inff, inff + m, cmp);

	int res = 0;
	for (int i = 0; i < m; i++) {
		int temp = 0;

		//a�������� b�������� ���µ� �ִ� �ڽ��� ���� ���
		for (int j = inff[i].a; j < inff[i].b; j++) 
			if (arr[j]>temp) temp = arr[j];

		//����� �� �ִ� �ִ� �ڽ��� �� ���
		int v = min(c - temp, inff[i].t);
		for (int j = inff[i].a; j < inff[i].b; j++) 
			arr[j] += v;
		
		res += v;
	}
	printf("%d\n", res);

	return 0;
}