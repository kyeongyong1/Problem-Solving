#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int n, m, idx = 0;
string str1, str2, rel;
//입력받은 이름에 대하여 차례대로 정수값을 부여하기 위한 map
map<string, int> Hash;
//vector<int> graph[100010];
//부모를 저장하기 위한 배열
int parent[100010];
//세대를 표시하기 위한 배열
int gen[100010];

//부모는 자녀보다 1세대 크다
//형제들은 같은 세대이다

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	ios::sync_with_stdio(false);

	cin >> n; n--;
	cin >> str1;
	Hash[str1] = idx++;
	gen[Hash[str1]] = 0;

	while (n--) {
		cin >> str1 >> str2 >> rel;
		Hash[str2] = idx++;

		int a = Hash[str1], b = Hash[str2];
		//부모라면
		if (rel == "부모") {
			parent[a] = b;
			//graph[b].push_back(a);
			gen[b] = gen[a] + 1;
		}
		//형제라면
		else if (rel == "형제") {
			int c = parent[a];
			parent[b] = c;
			//graph[c].push_back(b);
			gen[b] = gen[a];
		}
		//자녀라면
		else {
			parent[b] = a;
			//graph[a].push_back(b);
			gen[b] = gen[a] - 1;
		}
	}

	cin >> m;
	while (m--) {
		int cnt = 0;
		cin >> str1 >> str2;
		int a = Hash[str1], b = Hash[str2];

		//같은 세대가 나올때까지
		while (gen[a] != gen[b]) {
			if (gen[a] < gen[b])
				a = parent[a], cnt++;
			else
				b = parent[b], cnt++;
		}
		//같은 부모가 나올때까지 계속 올라간다
		while (a != b) {
			a = parent[a], b = parent[b];
			cnt += 2;
		}
		cout << cnt << endl;
	}
}