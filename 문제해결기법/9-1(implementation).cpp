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
//input �޴� ����
vector<pair<int, char> > v;
//tree�� �𵨸� �ϱ� ���� ����
vector<pair<char, char> > tree;
//���� �����ϱ� ���� �迭
int arr[50];

//v�� �󵵼��� ���ؼ� �����ϰ�, �� �ڿ� �ΰ��� ���ĺ��� ���Ͽ�
//tree�� push ���ش�. �� �ڿ� �ΰ��� ���ĺ��� ���� �󵵼��� ���� ����
//'idx'�� ���� v�� �ٽ� �־��ش�.
//tree�� �󵵼��� ���� ���ĺ����� �׾� ������.
//tree�� ���� ���ĺ��̶�� �ش� �����̰�,
//tree�� ���� 'idx'��� 'ã�ư����ϴ� tree�� �ε���' �̴�.

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

		//tree ���Ϳ� input ��𵨸�
		while (v.size() != 1) {
			sum = 0;
			sort(v.begin(), v.end());
			reverse(v.begin(), v.end());

			tree.push_back(make_pair(v[v.size() - 1].second, v[v.size() - 2].second));
			sum = v[v.size() - 1].first + v[v.size() - 2].first;
			v.pop_back(), v.pop_back();
			v.push_back(make_pair(sum, idx++));
		}
		//���̸� ����Ͽ� arr�迭�� ����
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