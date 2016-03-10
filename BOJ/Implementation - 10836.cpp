/*
다음과 같은 규칙에 의해 애벌레가 자라는 데 마지막 날의 
애벌레의 크기를 출력하는 문제이다.

애벌레는 제일 왼쪽 열과, 제일 위쪽 행의 애벌레들은 자신이 자라는 정도를
스스로 결정하고 나머지 애벌레들은 왼쪽, 왼쪽과 위쪽 사이, 위쪽의 애벌레들을
비교하여 가장 많이 자란 만큼 자신도 자란다.

매 일마다 애벌레의 크기를 계산하는 것이다. 
이는 O(M^2 x N)의 시간복잡도가 걸리므로 TL이다.

조금만 더 생각해보면 매 일마다 계산할 필요 없이 스스로 자라는 애벌레들만 마지막 날 까지 계산을 하고 난 후에
나머지 애벌레들을 계산해도 문제는 성립한다. 매 일마다 애벌레들을 계산을 할때에는 스스로 자라는 애벌레들은 
자라는 정도에 영향을 받지 않고  나머지 애벌레들은 스스로 자라는 애벌레들한테만 영향을 받기 때문이다.
나머지 애벌레들은 왼쪽, 왼쪽 대각선위, 위쪽 3가지 경우를 비교한다. 그 중 가장 큰값은 '항상 위쪽'이다.

시간복잡도는 O(m)이다.

input 처리가 약간 까다로운데 맨 왼쪽열부터 맨 위쪽행까지 순서대로 0의 개수, 1의 개수, 2의 개수 이렇게 주어지므로 부분합을 이용하였다.
0의 개수와 1의 개수가 끝나는 위치에 1씩 증가시키고 이 배열을 이용하여 부분합을 하게 되면 각 위치에서의 마지막날 애벌레가 자란 정도를 알 수 있다.

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

int m, n, arr[710][710], temp[710][710], a, b, c, sum[1500], psum[1500];

int main()
{

	scanf("%d%d", &m, &n);

	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = 1;

	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &a, &b, &c);
		sum[a]++; sum[a + b]++;
	}
	psum[0] = sum[0];
	
	for (int i = 1; i < 2 * m - 1; i++)
		psum[i] = psum[i - 1] + sum[i];

	int idx = 0;
	for (int i = m - 1; i >= 0; i--)
		arr[i][0] += psum[idx++];
	for (int i = 1; i < m; i++)
		arr[0][i] += psum[idx++];

	for (int i = 1; i < m; i++) 
		for (int j = 1; j < m; j++) 
			arr[i][j] = arr[i - 1][j];
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}