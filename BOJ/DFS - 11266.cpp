/*

절단점을 찾는 문제

DFS를 정점의 개수에 대해서 돌리고 컴포넌트가 
나눠졌는지 확인하면 된다.

좀 더 효율적인 방법으로 DFS를 한번만 돌고서 절단점 
인지 아닌지 확인할 수 있다.

해당 정점의 자식들을 루트로 하는 서브트리 중에서
해당 정점의 선조로 올라 갈 수 있는 간선이 존재하면
해당 정점은 절단점이다. 

루트의 경우는 무조건 절단점이라고 생각하기 쉬운데
자식이 1이하 이면 절단점이 아니다.
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

//정점을 루트로 가지는 서브트리 중 가장 빠르게 
//발견된 정점의 발견순서이다.
int sol(int here, bool isroot) {

	int child = 0;

	//현재 정점에 대해서 발견순서를 저장한다.
	discovered[here] = counter++;
	int ret = discovered[here];

	for (int i = 0; i < graph[here].size(); i++) {
		int there = graph[here][i];

		//그 정점을 방문하지 않았다면
		if (discovered[there] == -1) {
			child++;

			//there을 루트로 가지는 서브트리에서 가장 빠른 발견 순서를 반환
			int subtree = sol(there, false);

			//subtree의 정점 중 here의 선조로 올라 갈 수 있는 간선이 
			//없다면 해당 here 정점은 절단점이다.
			if (!isroot&& subtree >= discovered[here])
				isCurv[here] = true;

			ret = min(ret, subtree);
		}
		else
			ret = min(ret, discovered[there]);

	}
	//루트의 경우 자식이 2 이상일 경우에만 절단점 이다.
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