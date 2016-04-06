/*

Bubble Sort �� step�� �� ������ Sort�� �Ϸ� �Ǿ������� 
�迭�� �ڸ��� ��ĭ�� �ٰ����� �ȴ�. 

������ �Է¹��� data�� index�� ���ĵ� �迭�� index�� ���Ͽ�
�ε��� ���̰� ���� ū ���� ������ �����̴�.

*/

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>    
#include <cstdio>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int n, data[500010];
vector<int> v;
int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> data[i]; v.push_back(data[i]);
	}
	sort(v.begin(), v.end());

	int sol = 0;

	for (int i = 0; i < n; i++) {
		vector<int>::iterator it;

		it = lower_bound(v.begin(), v.end(), data[i]);
		sol = max(sol, i - (it - v.begin()));
		v[it - v.begin()]--;
	}
	cout << sol + 1 << endl;

}