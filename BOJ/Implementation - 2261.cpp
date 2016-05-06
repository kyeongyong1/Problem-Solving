/*

2차원 평면상에 n개의 점들이 주어졌을때, 가장 가까운
두 점의 거리를 구하는 문제

*/

#include <algorithm>
#include <functional>
#include <vector>
#include <map>    
#include <cstdio>
#include <queue>
#include <limits.h>
#include <stack>
#include <set>
#include <math.h>
#include <cstring>
#include <list>
#include <string>
#include <iostream>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const int RETURN = 1061109567;
const int INF = 987654321;
const int MAX_SIZE = 500000 * 4;
const int MAX_NUM = 1000001;
const ll INFF = 9876543212345;
const int MAX_V = 410;

struct Point {
	int x, y;
	Point() {}
	Point(int xx, int yy) {
		x = xx, y = yy;
	}
	bool operator < (const Point &v) const {
		if (y == v.y)
			return x < v.x;
		else
			return y < v.y;
	}
};
bool cmp(const Point &a, const Point &b) {
	return a.x < b.x;
}
int n, a, b;
vector<Point> v;
//s는 거리가 ans 이하 일 수도 있는 후보들, y값 기준으로 정렬
set<Point> s;

int dist(const Point &a, const Point &b) {
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}
int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		v.push_back(Point(a, b));
	}
	sort(v.begin(), v.end(), cmp);

	
	int ans = dist(v[0], v[1]);
	s.insert(v[0]); s.insert(v[1]);
	int start = 0;

	for (int i = 2; i < n; i++) {
		int herex = v[i].x;
		int herey = v[i].y;

		//현재까지 구한 거리의 최소값인 ans보다 x좌표의 차이의 거리가
		//더 크다면 후보들을 줄여 나간다. 
		while (start < i) {
			auto it = v[start];
			int x = it.x - herex;
			if (x*x > ans)
				s.erase(it), start++;
			else
				break;
		}
		//후보 점들 중에 y좌표가 현재 herey+d, herey-d 사이에 있는
		//점들만 살펴 보겠다.
		int d = (int)sqrt(double(ans)) + 1;
		auto lower = s.lower_bound(Point(-100001, herey - d));
		auto upper = s.upper_bound(Point(100001, herey + d));
		for (auto it = lower; it != upper; it++) {
			int dd = dist(v[i], *it);
			ans = min(dd, ans);
		}
		s.insert(v[i]);
	}
	printf("%d\n", ans);

}