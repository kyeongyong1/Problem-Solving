#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	ios::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		//������ �ڸ����� ���� �������� '�̸�' ����
		int arr[10000];
		memset(arr, 0, sizeof(arr));
		int num; cin >> num;
		int len; cin >> len;
		string str; cin >> str;
		reverse(str.begin(), str.end());

		//(A*B) % C = A%C*B%C �̿��ϱ� ���� ó��
		arr[1] = 1;
		for (int i = 2; i <= len; i++)
			arr[i] = (2 * arr[i - 1]) % num;
		int ret = 0;

		//(A + B) % C = A%C + B%C
		for (int i = 0; i < str.size(); i++) {
			ret += ((str[i] - '0')*arr[i + 1]) % num;
			ret %= num;
		}
		cout << ret << endl;
	}
}
