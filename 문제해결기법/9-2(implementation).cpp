#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <map>
#include <cstdio>
using namespace std;

char ch;
string str;
int m;
vector<int> signal;

//모든 경우를 다 본다
bool sol(int idx, int length) {

	if (idx + length >= signal.size()) return true;

	if (signal[idx] == signal[idx + length])
		return sol(idx + 1, length);
	else return false;
}
int main()
{

#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	//ios::sync_with_stdio(false);

	cin >> m;
	getchar();

	while (m--) {
		signal.clear();
		str.clear();

		getline(cin, str);

		//input 처리하여 signal 벡터에 저장
		int num = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == ' ') {
				signal.push_back(num);
				num = 0; continue;
			}
			num *= 10;
			num += str[i] - '0';
		}

		for (int len = 1; len <= signal.size(); len++) {
			if (sol(0, len)) {
				for (int j = 0; j < len; j++)
					cout << signal[j] << " ";
				cout << endl;
				break;
			}
		}
	}
}
