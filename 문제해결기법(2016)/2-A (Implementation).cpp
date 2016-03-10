/*
모든 스머프들은 평균만큼의 일을 하면 된다.
평균으로 딱 떨어지지 않는 경우에는 '평균+1'만큼의 일을
해야 되는 스머프들이 '더' 있다.
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
#include <cmath>
#include <set>
#include <math.h>
#include <cstring>
using namespace std;

int t, s, w;
vector<int> v;

int main()
{
	scanf("%d", &t);

	while (t--) {
		scanf("%d", &s);
		v.resize(s);

		int sum = 0;
		for (int i = 0; i < s; i++)
			scanf("%d", &v[i]), sum += v[i];

		//plusS는 평균+1 의 일을 해야 되는 스머프들의 수
		//gS는 평균보다 커서 일을 주는 스머프들의 수
		int plusS = sum%s, avg = sum / s, res = 0, gS = 0;

		for (int i = 0; i < s; i++) {
			if (v[i] > avg) gS++;
			else res += avg - v[i];
		}
		
		//해야 할 일이 평균보다 커서 일을 주는 스머프들이 평균+1 의 일을 한다고 생각한다.
		//평균+1 의 일을 해야 하는 스머프들이 있다면 나머지 스머프들이 그 차이만큼 1씩 더 일을 해야한다.
		if (plusS > gS) res += plusS - gS;
		printf("%d\n", res);
	}
}