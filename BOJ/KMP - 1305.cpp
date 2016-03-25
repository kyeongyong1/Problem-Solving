/*

�Է� ���� ���ڿ��� ���ؼ� ���λ絵 �ǰ� ���̻絵 �Ǵ�
�ִ� ���̸� ���� ���� ���ڿ��� ũ�⿡�� ���ָ� ������ ���� ��
���� ª�� ���� ���̰� �ȴ�.

�ܼ��ϰ� �����ϸ� n�� �鸸�̰� �ð� ���⵵�� O(n^2)�̹Ƿ� TL�� ����. 
���� ���ڿ��� ã�� ���� �˰����� �����ؾ� �Ѵ�.

KMP �˰���
�ٺ��� �ʾƵ� �� �� �ִ�. �� ������ �̿��Ѵ�. 

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
#include <string>
#include <iostream>
using namespace std;

int n;
string str;

//pi[i]=N[..i]�� ���̻絵 �ǰ� ���λ絵 �Ǵ� ���ڿ��� �ִ� ����
vector<int> getPartialMatch(const string& N) {
	int m = N.size();
	vector<int> pi(m, 0);
	int begin = 1, matched = 0;

	//begin+matched �� ���� �����ִ� ���ڿ��� index
	while (begin + matched<m) {

		if (N[begin + matched] == N[matched]) {
			matched++;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0)
				begin++;
			else {
				//begin �������� �� �ʿ䰡 ���� ���λ絵 �ǰ� ���̻絵 �Ǵ�
				//�ִ� ���̸� ���� ��ŭ�� ���� �ȴ�.
				begin += matched - pi[matched - 1];
				//pi[matched-1]��ŭ ��ġ�ϴ� �͵� �̹� �˰� �ֱ� ������
				//�� �ں��� ���� ���� �ȴ�.
				matched = pi[matched - 1];
			}
		}

	}
	return pi;
}
int main() {

	scanf("%d", &n); cin >> str;

	vector<int> res = getPartialMatch(str);
	printf("%d\n", n - res[n - 1]);
}