/*
Greedy 방법

번호가 느린 마을에 박스를 배송하는 것보다
번호가 빠른 마을에 박스를 배송하는 것이 최선의 선택
트럭이 최대 용량이 있기 때문

도착하는 번호의 마을이 같다면 시작하는 마을의 번호가 빠른 마을을
선택하는 것이 최선

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

//arr[i] -> 현재까지 i번 마을에 배송하는 박스의 최대 개수
int n, c, m, arr[2010];

struct inf {
	int a, b, t;
};
inf inff[10010];

bool cmp(inf x, inf z) {
	if (x.b != z.b) return x.b < z.b;
	return x.a > z.a;
}

int main(int argc, char** argv) {

	scanf("%d%d%d", &n, &c, &m);

	for (int i = 0; i < m; i++) 
		scanf("%d%d%d", &inff[i].a, &inff[i].b, &inff[i].t);
	
	//도착 마을의 번호가 빠른 순서대로 정렬
	sort(inff, inff + m, cmp);

	int res = 0;
	for (int i = 0; i < m; i++) {
		int temp = 0;

		//a마을부터 b마을까지 가는데 최대 박스의 수를 계산
		for (int j = inff[i].a; j < inff[i].b; j++) 
			if (arr[j]>temp) temp = arr[j];

		//배송할 수 있는 최대 박스의 수 계산
		int v = min(c - temp, inff[i].t);
		for (int j = inff[i].a; j < inff[i].b; j++) 
			arr[j] += v;
		
		res += v;
	}
	printf("%d\n", res);

	return 0;
}