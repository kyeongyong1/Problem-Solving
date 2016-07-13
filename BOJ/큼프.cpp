#include <iostream>
#include <vector>

using namespace std;

//부분 일치 함수
//pi[i]=N[..i]의 접미사도 되고 접두사도 되는 문자열의 최대 길이
vector<int> getPartialMatch(const string& N) {
	int m = N.size();
	vector<int> pi(m, 0);
	int begin = 1, matched = 0;
	while (begin + matched<m) {
		if (N[begin + matched] == N[matched]) {
			matched++;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0)
				begin++;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}

//짚더미 H의 부분 문자열로 바늘 N이 출현하는 시작 위치들을 모두 반환 
//부분 일치 함수를 이용한 kmp 함수
vector<int> kmpSearch(const string& H, const string& N) {
	int n = H.size(), m = N.size();
	vector<int>ret;
	vector<int> pi = getPartialMatch(N);

	int begin = 0, matched = 0;
	while (begin <= n - m) {
		if (matched<m && H[begin + matched] == N[matched]) {
			matched++;
			if (matched == m) ret.push_back(begin);
		}
		else {
			if (matched == 0)
				begin++;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}

	return ret;
}
