//오토마타 기초문제
//몇개의 vertex에서 계속 '반복' 한다
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

//point[b][position] -> 현재 position 에서 신호가 b일 때 가는 vertex
int point[2][9] = {
	7, 2, 3, 3, 7, 6, 3, 8, 8,
	1, 8, 8, 4, 5, 5, 0, 0, 8
};
int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	ios::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		string str; cin >> str;
		//0번 vertex부터 시작
		int position = 0;

		for (int i = 0; i < str.size(); i++) {
			position = point[str[i] - '0'][position];
		}
		//0,4,5에 있을때에만 원하는 패턴
		if (position == 0 || position == 4 || position == 5)
			cout << "I" << endl;
		else cout << "N" << endl;
	}
}
