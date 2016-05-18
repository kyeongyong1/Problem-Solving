/*

����� �־�����, ���� �� �ִ� ������ ���� ���� â�� 
�ٰ����� ũ�⸦ ����ϴ� ����

���� ��պ��� �������� ��, ���� �� �ִ� ������ ���� â�� �ٰ�����
'��ĥ'�� �Ѵ�. ������ ��պ��� �������� ��, ���� �� �ִ� ������ ����
â�� �ٰ����� '��ĥ'�� �Ѵ�. 2����ĥ �Ǿ� �ִ� ���� ���ϰ��� �ϴ�
������ ���� ���� â�� �ٰ����� ũ�Ⱑ �ȴ�.

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

int n, d[1010][1010];
vector<pair<int, int> > v;

int main() {

	scanf("%d", &n);
	v.resize(n);

	for (int i = 0; i < n; i++)
		scanf("%d%d", &v[i].first, &v[i].second);

	sort(v.begin(), v.end());

	//���� ����� ��ĥ
	for (int i = 0; i < v[0].second; i++)
		d[i][v[0].first]++;
	//������ ����� ��ĥ
	for (int i = 0; i < v.back().second; i++)
		d[i][v.back().first]++;

	//�� ���ʺ��� ���鼭 ��ĥ�� ������.
	int rh = v[0].second;
	for (int i = 1; i < v.size(); i++) {
		for (int j = v[i - 1].first; j < v[i].first; j++)
			for (int k = 0; k < rh; k++)
				d[k][j]++;
		rh = max(rh, v[i].second);
	}

	//�� �����ʺ��� ���鼭 ��ĥ�� ������.
	rh = v.back().second;
	for (int i = v.size() - 2; i >= 0; i--) {
		for (int j = v[i].first + 1; j < v[i + 1].first + 1; j++) 
			for (int k = 0; k < rh; k++) 
				d[k][j]++;
		rh = max(rh, v[i].second);
	}

	int res = 0;
	for (int i = 0; i < 1010; i++) 
		for (int j = 0; j < 1010; j++) 
			if (d[i][j] == 2) res++;
	printf("%d\n", res);
}