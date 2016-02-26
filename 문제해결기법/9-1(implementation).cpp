#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int k, f;
char ch;
string str;
//input 받는 벡터
vector<pair<int, char> > v;
//tree로 모델링 하기 위한 벡터
vector<pair<char, char> > tree;
//높이 저장하기 위한 배열
int arr[50];

//v를 빈도수에 대해서 정렬하고, 맨 뒤에 두가지 알파벳에 대하여
//tree에 push 해준다. 맨 뒤에 두가지 알파벳에 대한 빈도수를 더한 값을
//'idx'와 같이 v에 다시 넣어준다.
//tree에 빈도수가 작은 알파벳부터 쌓아 나간다.
//tree의 값이 알파벳이라면 해당 높이이고,
//tree의 값이 'idx'라면 '찾아가야하는 tree의 인덱스' 이다.

void settree(int idx, int cnt) {
	if (tree[idx].first >= 'a')
		arr[tree[idx].first - 'a'] = cnt;
	else if (tree[idx].first >= 0)
		settree(tree[idx].first, cnt + 1);

	if (tree[idx].second >= 'a')
		arr[tree[idx].second - 'a'] = cnt;
	else if (tree[idx].first >= 0)
		settree(tree[idx].second, cnt + 1);
}
int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	ios::sync_with_stdio(false);

	int m; cin >> m;
	while (m--) {

		memset(arr, 0, sizeof(arr));
		tree.clear();
		v.clear();

		cin >> k;

		for (int i = 0; i < k; i++) {
			cin >> f >> ch;
			v.push_back(make_pair(f, ch));
		}
		if (v.size() == 1) {
			cin >> str;
			cout << str.size() << endl;
			return 0;
		}
		int sum = 0, idx = 0;

		//tree 벡터에 input 재모델링
		while (v.size() != 1) {
			sum = 0;
			sort(v.begin(), v.end());
			reverse(v.begin(), v.end());

			tree.push_back(make_pair(v[v.size() - 1].second, v[v.size() - 2].second));
			sum = v[v.size() - 1].first + v[v.size() - 2].first;
			v.pop_back(), v.pop_back();
			v.push_back(make_pair(sum, idx++));
		}
		//깊이를 계산하여 arr배열에 저장
		settree(tree.size() - 1, 1);

		/*
		for (int i = 0; i < 26; i++)
			cout << arr[i] << " ";
		cout << endl;
		*/

		int ans = 0;
		cin >> str;
		for (int i = 0; i < str.size(); i++)
			ans += arr[str[i] - 'a'];

		cout << ans << endl;
	}
}