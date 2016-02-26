//�����佺�׳׽��� ü �̿�
//�Ҽ��� �ð����⵵ O(nloglogn)�� ���ϴ� �˰���
//�Ҽ��� ����� �Ҽ��� �ƴϴٸ� �̿�

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_N = 12000000;
int pn[MAX_N];

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	for (int i = 2; i < MAX_N; i++) {
		//�� ���� 2�� üũ�Ǿ����� �Ҽ� �� �� �����Ƿ� 
		if (pn[i] >= 2) continue;
		//i�� ����� ���ؼ� ǥ��
		for (int j = i; j < MAX_N; j += i) {
			pn[j]++;
		}
	}

	int t;
	cin >> t;

	while (t--) {
		int cnt = 0;
		int n; cin >> n;

		//üũ�� �ѹ� �Ȱ� ��� �Ҽ�
		for (int i = 2; i<n; i++)
			if (pn[i] == 1) cnt++;

		cout << cnt << endl;
	}
}