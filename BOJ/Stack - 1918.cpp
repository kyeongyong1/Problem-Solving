/*

후위 표기식 출력
스택을 이용한 기본 문제

우선 순위를 이용한다.

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

		//피연산자는 바로 출력
		if ('A' <= ch && ch <= 'Z') {
			cout << ch; continue;
		}
		//닫히는 괄호가 나왔다면 시작하는 괄호가 나올 때까지 출력
		if (ch == ')') {
			while (s.top() != '(') {
				cout << s.top(); s.pop();
			}
			s.pop(); continue;
		}
		//시작하는 괄호는 스택에 넣어준다.
		if (ch == '(') {
			s.push(ch); continue;
		}
		//+나 -라면 시작하는 괄호가 나올 때까지 출력한다.
		if (ch == '+' || ch == '-') {
			while (!s.empty() && s.top() != '(') {
				cout << s.top(); s.pop();
			}
			s.push(ch);
		}
		//*나 /라면 시작하는 괄호, +, -가 나올때까지 출력한다.
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