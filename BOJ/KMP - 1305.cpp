/*

입력 받은 문자열에 대해서 접두사도 되고 접미사도 되는
최대 길이를 구한 다음 문자열의 크기에서 빼주면 광고의 길이 중
가장 짧은 것의 길이가 된다.

단순하게 구현하면 n은 백만이고 시간 복잡도는 O(n^2)이므로 TL이 난다. 
따라서 문자열을 찾는 빠른 알고리즘을 구현해야 한다.

KMP 알고리즘
다보지 않아도 알 수 있다. 본 정보를 이용한다. 

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

//pi[i]=N[..i]의 접미사도 되고 접두사도 되는 문자열의 최대 길이
vector<int> getPartialMatch(const string& N) {
	int m = N.size();
	vector<int> pi(m, 0);
	int begin = 1, matched = 0;

	//begin+matched 는 현재 보고있는 문자열의 index
	while (begin + matched<m) {

		if (N[begin + matched] == N[matched]) {
			matched++;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0)
				begin++;
			else {
				//begin 다음부터 볼 필요가 없고 접두사도 되고 접미사도 되는
				//최대 길이를 더한 만큼만 보면 된다.
				begin += matched - pi[matched - 1];
				//pi[matched-1]만큼 일치하는 것도 이미 알고 있기 때문에
				//그 뒤부터 살펴 보면 된다.
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