#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int n, m, idx = 0;
string str1, str2, rel;
//�Է¹��� �̸��� ���Ͽ� ���ʴ�� �������� �ο��ϱ� ���� map
map<string, int> Hash;
//vector<int> graph[100010];
//�θ� �����ϱ� ���� �迭
int parent[100010];
//���븦 ǥ���ϱ� ���� �迭
int gen[100010];

//�θ�� �ڳຸ�� 1���� ũ��
//�������� ���� �����̴�

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
		//�θ���
		if (rel == "�θ�") {
			parent[a] = b;
			//graph[b].push_back(a);
			gen[b] = gen[a] + 1;
		}
		//�������
		else if (rel == "����") {
			int c = parent[a];
			parent[b] = c;
			//graph[c].push_back(b);
			gen[b] = gen[a];
		}
		//�ڳ���
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

		//���� ���밡 ���ö�����
		while (gen[a] != gen[b]) {
			if (gen[a] < gen[b])
				a = parent[a], cnt++;
			else
				b = parent[b], cnt++;
		}
		//���� �θ� ���ö����� ��� �ö󰣴�
		while (a != b) {
			a = parent[a], b = parent[b];
			cnt += 2;
		}
		cout << cnt << endl;
	}
}