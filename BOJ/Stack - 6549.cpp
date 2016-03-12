/*
stack�� �̿��� ������ ����

��� �簢���鿡 ���ؼ� �簢���� ���� ���ڵ��� ��ȣ�� ����
left[i], right[i]��� �Ѵ�.

i�� ���ڸ� �ôµ�, ���ʿ� �ڽź��� ���� ���ڵ��� ���� �ִٸ�
�׵��� �ִ� �簢���� �ڽ��� ���� �ִ� ����̴�. �̵� ���ο� ����
�ִ� �簢���� ���̸� ����ϰ� �̵��� ���� ������. ���ÿ��� i�� ����
���ʿ��� �ڽź��� ���� ���ڸ��� ���� �ְ� �ȴ�. 
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

typedef long long ll;

int n;
vector<int> h;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	while (1) {
		scanf("%d", &n);
		if (n == 0) break;

		h.resize(n);
		for (int i = 0; i < n; i++)
			scanf("%d", &h[i]);
		//�����ִ� ���ڵ鿡 ���ؼ� ����� �ֱ� ���ؼ� 0�� �������� �ִ´�.
		h.push_back(0);

		stack<int> s;

		ll ret = 0;
		for (int i = 0; i < h.size(); i++) {

			//i��° ���ں��� ũ�ų� ���� ���ڵ鿡 ���� �ִ� �簢���� ����Ѵ�.
			while (!s.empty() && h[s.top()] >= h[i]) {

				//j�� left[i]�� �ȴ�.
				int j = s.top();
				s.pop();

				int width = -1;
				if (s.empty())
					width = i;
				else
					width = (i - s.top() - 1);
				
				ret = max(ret, (ll)h[j] * (ll)width);
			}
			s.push(i);
		}
		printf("%lld\n", ret);
	}
}