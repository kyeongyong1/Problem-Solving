/*
'k��°' �ִ� ��θ� ����ؾ� �ϴ� ����

�Ϲ����� ���ͽ�Ʈ�� �˰����� �ణ �����Ѵ�.
���ͽ�Ʈ�� �Լ� �ȿ��� dist �迭 ������ ���� ���Ҹ�
priorityQueue�� �̿��Ͽ� �����Ѵ�.

*/

#include <algorithm>
#include <functional>
#include <vector>
#include <map>    
#include <cstdio>
#include <string>
#include <queue>
#include <limits.h>
#include <stack>
#include <set>
#include <math.h>
#include <cstring>
using namespace std;

const int INF = 987654321;

int n, m, k, a, b, c;
vector<pair<int, int > > graph[1010];

//k��° �ִ� ��θ� ��ȯ�ϴ� �Լ�
vector<priority_queue<int > > dijkstra(int s) {

	//dist�迭 ���� ���Ҵ� pq�̴�.
	vector<priority_queue<int> > dist(n + 1);
	priority_queue<pair<int, int > > pq;
	pq.push(make_pair(0, s));
	dist[s].push(0);

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[here].size(); i++) {
			int there = graph[here][i].first;
			int nextdist = graph[here][i].second + cost;

			//������� there�� �ִܰ�ΰ� k���� ��ã�Ҵٸ� ���� �ִܰ�θ�
			//�־��ְ� �ִܰ�ΰ� k����� �ִܰ�ΰ� ���� ū���� ���Ͽ�
			//���� ��쿡�� �ִܰ�θ� �־��ش�.
			int kdist = dist[there].size() == k ? dist[there].top() : INF;

			if (nextdist<kdist) {
				//���� dist[there]�� pq�� size�� k�� ���.. k���� ������Ų��.
				if (kdist != INF) dist[there].pop();
				//nextdist�� push
				dist[there].push(nextdist);
				pq.push(make_pair(-nextdist, there));
			}
		}
	}
	return dist;
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);

	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		graph[a].push_back(make_pair(b, c));
	}

	vector<priority_queue<int > > v = dijkstra(1);

	for (int i = 1; i < v.size(); i++) {
		int a = v[i].size() == k ? v[i].top() : -1;
		printf("%d\n", a);
	}
}