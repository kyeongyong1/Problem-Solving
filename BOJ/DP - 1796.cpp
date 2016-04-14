/*

문자열 S가 있는데 문자열 S를 알파벳 순서대로 출력하려고 한다.
이때 커서를 왼쪽과 오른쪽으로 옮기는 키와, 해당 문자를 화면에
출력하는 키 3개가 있을 때, 키의 입력을 최소로 하는 값을 구하는 문제

dp[26][2]
dp[i][j] i가 0이면 'a', 25이면 'z' 일 때 i알파벳 까지 봤고 
		 s가 0이면 왼쪽에서 끝났을 때, 1이면 오른쪽에서 끝났을 때
		 의 최솟값이다.


*/

#include <algorithm>
#include <functional>
#include <vector>
#include <map>    
#include <cstdio>
#include <queue>
#include <climits>
#include <stack>
#include <set>
#include <cmath>
#include <cstring>
#include <list>
using namespace std;

int dp[26][2], strSize, cnt = 0;
char str[1010], stAl;
bool visited[26];

//시작위치, 끝나는위치, 알파벳 개수
struct Data {
	int stIdx, laIdx, cnt;
	Data() {};
	Data(int a, int b, int c) {
		stIdx = a, laIdx = b, cnt = c;
	}
};
Data d[26];

//s가 0이면 왼쪽에서 끝났을 때 최솟값
int sol(int al, int s) {

	if (al == 26) return 0;

	int &ret = dp[al][s];
	if (ret != -1) return ret;

	//다음 알파벳을 구한다.
	int nextal = -1;

	for (int i = al + 1; i < 26; i++) {
		if (visited[i] == true) {
			nextal = i; break;
		}
	}
	//해당 알파벳이 마지막 알파벳 이라면
	if (nextal == -1) 
		return ret = abs(d[al].laIdx - d[al].stIdx) + d[al].cnt;

	int nLeft = d[nextal].stIdx, nRight = d[nextal].laIdx;
	int cLeft = d[al].stIdx, cRight = d[al].laIdx;
	int Ccnt = d[al].cnt;
	
	//왼쪽에서 끝나는 경우에는 다음 알파벳이 왼쪽에서 끝나는 경우와
	//오른쪽에서 끝나는 경우 중 작은 값이 해당 함수의 ret 값이다.
	if (s == 0) {
		ret = min(sol(nextal, 0) + abs(nRight - cLeft) + abs(cRight - cLeft) + Ccnt
			, sol(nextal, 1) + abs(nLeft - cLeft) + abs(cRight - cLeft) + Ccnt);
	}
	else {
		ret = min(sol(nextal, 0) + abs(nRight - cRight) + abs(cRight - cLeft) + Ccnt,
			sol(nextal, 1) + abs(nLeft - cRight) + abs(cRight - cLeft) + Ccnt);
	}

	return ret;
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	memset(dp, -1, sizeof(dp));

	scanf("%s", &str);
	strSize = strlen(str);

	//가장 작은 알파벳
	stAl = -1;

	for (int i = 0; i < 26; i++) {
		int s = -1, l = -1, cnt = 0;
		for (int j = 0; j < strSize; j++) {
			if (str[j] == 'a' + i) {
				if (s == -1) s = j;
				l = j; cnt++;
			}
		}
		if (s != -1 && stAl == -1) stAl = i;
		if (s != -1) visited[i] = true;
		
		//해당 알파벳이 없다면 '전'의 알파벳의 시작위치, 끝나는위치로 초기화 한다.
		if (i == 0) 
			if (s + l == -2) s = 0, l = 0;
		else {
			if (s + l == -2) s = d[i - 1].stIdx, l = d[i - 1].laIdx;
		}
		d[i] = { s, l, cnt };
	}
	//첫번째 알파벳이 오른쪽에서 끝났을때, 왼쪽에서 끝났을때 최소값 중 작은값이 답
	printf("%d\n", min(sol(stAl, 0) + d[stAl].laIdx, sol(stAl, 1) + d[stAl].stIdx));
}