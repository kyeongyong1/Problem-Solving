/*

주어진 배열을 압축하는 문제
단순한 재귀 문제

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
#include <string>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

char arr[70][70];

int white = 0, blue = 0;

bool iswhite(int row, int col, int length)
{
	for (int i = row; i<row + length; i++)
		for (int j = col; j<col + length; j++)
			if (arr[i][j] == '0') {
				return false;
			}
	return true;
}
bool isblue(int row, int col, int length)
{
	for (int i = row; i<row + length; i++)
		for (int j = col; j<col + length; j++)
			if (arr[i][j] == '1') {
				return false;
			}
	return true;
}
void sol(int row, int col, int length)
{
	if (length == 1) {
		cout << arr[row][col];
		return;
	}
	if (iswhite(row, col, length)) {
		cout << "1";
		return;
	}
	if (isblue(row, col, length)) {
		cout << "0";
		return;
	}
	cout << "(";
	sol(row, col, length / 2);
	sol(row, col + length / 2, length / 2);
	sol(row + length / 2, col, length / 2);
	sol(row + length / 2, col + length / 2, length / 2);
	cout << ")";
}
int main()
{

	int n; cin >> n;

	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
			cin >> arr[i][j];

	sol(0, 0, n);
	cout << endl;
}