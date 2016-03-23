/*

�������� ã�� ����

DFS�� ������ ������ ���ؼ� ������ ������Ʈ�� 
���������� Ȯ���ϸ� �ȴ�.

�� �� ȿ������ ������� DFS�� �ѹ��� ���� ������ 
���� �ƴ��� Ȯ���� �� �ִ�.

�ش� ������ �ڽĵ��� ��Ʈ�� �ϴ� ����Ʈ�� �߿���
�ش� ������ ������ �ö� �� �� �ִ� ������ �����ϸ�
�ش� ������ �������̴�. 

��Ʈ�� ���� ������ �������̶�� �����ϱ� ���
�ڽ��� 1���� �̸� �������� �ƴϴ�.
*/

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>    
#include <cstdio>
#include <cstring>
using namespace std;

int n, k, v, e, a, b, counter, res;
bool isCurv[10010];
int discovered[10010];
vector<int> graph[10010];

//������ ��Ʈ�� ������ ����Ʈ�� �� ���� ������ 
//�߰ߵ� ������ �߰߼����̴�.
int sol(int here, bool isroot) {

	int child = 0;

	//���� ������ ���ؼ� �߰߼����� �����Ѵ�.
	discovered[here] = counter++;
	int ret = discovered[here];

	for (int i = 0; i < graph[here].size(); i++) {
		int there = graph[here][i];

		//�� ������ �湮���� �ʾҴٸ�
		if (discovered[there] == -1) {
			child++;

			//there�� ��Ʈ�� ������ ����Ʈ������ ���� ���� �߰� ������ ��ȯ
			int subtree = sol(there, false);

			//subtree�� ���� �� here�� ������ �ö� �� �� �ִ� ������ 
			//���ٸ� �ش� here ������ �������̴�.
			if (!isroot&& subtree >= discovered[here])
				isCurv[here] = true;

			ret = min(ret, subtree);
		}
		else
			ret = min(ret, discovered[there]);

	}
	//��Ʈ�� ��� �ڽ��� 2 �̻��� ��쿡�� ������ �̴�.
	if (isroot) isCurv[here] = (child > 1);
	return ret;
}

int main()
{
	scanf("%d %d", &v, &e);
	memset(discovered, -1, sizeof(discovered));

	for (int i = 0; i < e; i++) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b); graph[b].push_back(a);
	}

	for (int i = 1; i <= v; i++)
		if (discovered[i] == -1)
			sol(i, 1);

	for (int i = 1; i <= v; i++)
		if (isCurv[i])
			res++;
	printf("%d \n", res);

	for (int i = 1; i <= v; i++)
		if (isCurv[i])
			printf("%d ", i);
	printf("\n");
	return 0;
}