/*

�ش� �ε������� ���������� k�� ��ŭ ����� ������������
���ĵ� ���� ������ �ּ� Ƚ���� ���ϴ� ����

��� �ε����κ��� k�� ��ŭ ������ ���� �ϳ��� �����̶�� �����ϰ�
BFS�� ������ ���� ���� ���ĵ� ���� ������ �ּ� Ƚ���� ���� �� �ִ�.

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

		//�������� Ȯ��
		bool flag = true;
		for (int i = 1; i < s.size(); i++) {
			if (s[i - 1] >= s[i]) flag = false;
		}
		if (flag == true) {
			cout << cnt << endl; return 0;
		}
		//��� �ε����� ���� k�� ��ŭ �����´�.
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