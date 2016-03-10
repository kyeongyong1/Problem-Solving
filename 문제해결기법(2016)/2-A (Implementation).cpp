/*
��� ���������� ��ո�ŭ�� ���� �ϸ� �ȴ�.
������� �� �������� �ʴ� ��쿡�� '���+1'��ŭ�� ����
�ؾ� �Ǵ� ���������� '��' �ִ�.
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
#include <cmath>
#include <set>
#include <math.h>
#include <cstring>
using namespace std;

int t, s, w;
vector<int> v;

int main()
{
	scanf("%d", &t);

	while (t--) {
		scanf("%d", &s);
		v.resize(s);

		int sum = 0;
		for (int i = 0; i < s; i++)
			scanf("%d", &v[i]), sum += v[i];

		//plusS�� ���+1 �� ���� �ؾ� �Ǵ� ���������� ��
		//gS�� ��պ��� Ŀ�� ���� �ִ� ���������� ��
		int plusS = sum%s, avg = sum / s, res = 0, gS = 0;

		for (int i = 0; i < s; i++) {
			if (v[i] > avg) gS++;
			else res += avg - v[i];
		}
		
		//�ؾ� �� ���� ��պ��� Ŀ�� ���� �ִ� ���������� ���+1 �� ���� �Ѵٰ� �����Ѵ�.
		//���+1 �� ���� �ؾ� �ϴ� ���������� �ִٸ� ������ ���������� �� ���̸�ŭ 1�� �� ���� �ؾ��Ѵ�.
		if (plusS > gS) res += plusS - gS;
		printf("%d\n", res);
	}
}