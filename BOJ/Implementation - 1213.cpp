/*
어떤 문자열에 대해서 팰린드롬을 만들 수 있다면
사전순으로 앞서는 것을 출력하는 문제

팰린드롬 만들수 있는 경우
1. 모든 문자가 짝수개인 경우
 문자열 길이의 반은 알파벳 앞에서부터 짝수개의 반을 채우고
나머지는 알파벳 뒤에서부터 짝수개의 반을 채운다.

2. 홀수개의 문자가 1개뿐이고 나머지는 짝수개인 경우
 1번의 경우와 같고 다른점은 문자열 가운데에 홀수개의 문자
1개를 집어넣기만 하면 된다.
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
#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;

int alpha[27];
string str, sol;

bool p(int l, int r) {
	if (l >= r) return true;

	if (sol[l] == sol[r]) return p(l + 1, r - 1);
	return false;
}
int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		alpha[str[i] - 'A']++;
	}
	for (int i = 0; i <= 26; i++) {
		for (int j = 0; j < alpha[i] / 2; j++)
			sol.push_back(i + 'A');
	}
	for (int i = 0; i <= 26; i++) {
		if (alpha[i] % 2 == 1) sol.push_back(i + 'A');
		alpha[i] /= 2;
	}
	for (int i = 26; i >= 0; i--) {
		for (int j = 0; j < alpha[i]; j++)
			sol.push_back(i + 'A');
	}
	if (p(0, sol.size() - 1)) cout << sol << endl;
	else cout << "I'm Sorry Hansoo" << endl;
}