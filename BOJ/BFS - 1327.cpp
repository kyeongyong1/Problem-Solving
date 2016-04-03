/*

해당 인덱스부터 오른쪽으로 k개 만큼 뒤집어서 오름차순으로
정렬된 수를 만나는 최소 횟수를 구하는 문제

모든 인덱스로부터 k개 만큼 뒤집은 것을 하나의 정점이라고 생각하고
BFS를 돌리면 가장 먼저 정렬된 수를 만나는 최소 횟수를 구할 수 있다.

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

const int INF = 987654321;

int n, k, minn;
string str;
bool visited[90000010];

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	//ios::sync_with_stdio(false);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		char ch; cin >> ch;
		str.push_back(ch);
	}
	// str, cnt
	queue<pair< string, int > > q;
	q.push(make_pair(str, 0));

	while (!q.empty()) {

		string s = q.front().first;
		int cnt = q.front().second;
		q.pop();

		//오름차순 확인
		bool flag = true;
		for (int i = 1; i < s.size(); i++) {
			if (s[i - 1] >= s[i]) flag = false;
		}
		if (flag == true) {
			cout << cnt << endl; return 0;
		}
		//모든 인덱스로 부터 k개 만큼 뒤집는다.
		for (int i = 0; i<str.size(); i++) {
			if (i + k>str.size()) break;
			reverse(s.begin() + i, s.begin() + i + k);
			if (visited[stoi(s)] == false) {
				visited[stoi(s)] = true;
				q.push(make_pair(s, cnt + 1));
			}
			reverse(s.begin() + i, s.begin() + i + k);
		}
	}
	cout << "-1" << endl;
}