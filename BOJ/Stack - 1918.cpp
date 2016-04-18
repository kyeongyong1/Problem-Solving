/*

���� ǥ��� ���
������ �̿��� �⺻ ����

�켱 ������ �̿��Ѵ�.

*/

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <math.h>
#include <cstring>
using namespace std;

stack<char> s;
char ch;

int main()
{
	ios::sync_with_stdio(false);

	while (cin >> ch) {

		//�ǿ����ڴ� �ٷ� ���
		if ('A' <= ch && ch <= 'Z') {
			cout << ch; continue;
		}
		//������ ��ȣ�� ���Դٸ� �����ϴ� ��ȣ�� ���� ������ ���
		if (ch == ')') {
			while (s.top() != '(') {
				cout << s.top(); s.pop();
			}
			s.pop(); continue;
		}
		//�����ϴ� ��ȣ�� ���ÿ� �־��ش�.
		if (ch == '(') {
			s.push(ch); continue;
		}
		//+�� -��� �����ϴ� ��ȣ�� ���� ������ ����Ѵ�.
		if (ch == '+' || ch == '-') {
			while (!s.empty() && s.top() != '(') {
				cout << s.top(); s.pop();
			}
			s.push(ch);
		}
		//*�� /��� �����ϴ� ��ȣ, +, -�� ���ö����� ����Ѵ�.
		else {
			while (!s.empty() && s.top() != '(' && s.top() != '+' && s.top() != '-') {
				cout << s.top(); s.pop();
			}
			s.push(ch);
		}
	}

	while (!s.empty()) {
		if (s.top() == '(') {
			s.pop(); continue;
		}
		cout << s.top(), s.pop();
	}
	cout << endl;

}