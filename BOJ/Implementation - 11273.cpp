/*
고블린의 위치가 주어지고 고블린을 잡을 수 있는
sprinkler의 위치도 주어지는데 범위 안에 있는 
고블린은 모두 잡을 수 있을때, 남아있는 고블린의
수를 출력하는 문제

고블린의 수는 100,000 이고 sprinkler의 수는 20,000 이다.
하나의 sprinkler에 대해서 모든 고블린이 범위 안에 있는지
확인한다면 TL이 난다.

sprinkler의 '범위 안에 들어오는' 고블린만 조사한다.
map 자료구조를 사용하여 key값은 고블린의 x값 value값은 고블린의 y값들
을 저장한 후 '범위 안에 들어오는 x값(key값)'에 대하여 '범위 안에 들어오는
y값(value값)들'만을 조사한다.
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

int g, x, m, r;
double y;
map<int, vector<double> > Hash;

int main() {

	scanf("%d", &g);
	for (int i = 0; i < g; i++) {
		scanf("%d%lf", &x, &y);
		Hash[x].push_back(y);
	}
	//원하는 y값을 logn만에 찾기 위해 정렬한다.
	for (int i = 0; i <= 10000; i++)
		if (Hash.count(i) != 0)
			sort(Hash[i].begin(), Hash[i].end());

	int cnt = 0;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%lf%d", &x, &y, &r);

		//범위 안에 들어오는 x값을 찾는다.
		auto it = Hash.lower_bound(x - r);

		while (it != Hash.end() && (*it).first <= x + r) {
			
			if ((*it).first < x - r) {
				it++; continue;
			}

			int curX = (*it).first;
			double curY = y - sqrt(r*r - abs(curX - x)*abs(curX - x));
			double endY = y + sqrt(r*r - abs(curX - x)*abs(curX - x));

			//범위 안에 들어오는 y값을 찾는다.
			auto it2 = lower_bound(Hash[curX].begin(), Hash[curX].end(), curY);

			//x값에 대하여 모든 y값들을 살펴본다.
			while (it2 != Hash[curX].end() && *it2 <= endY) {
				if (*it2 < curY) {
					it2++; continue;
				}
				cnt++; it2 = Hash[curX].erase(it2);
			}
			it++;
		}
		if (Hash.count(x) == 0)
			Hash.erase(x);
	}
	printf("%d\n", g - cnt);
}