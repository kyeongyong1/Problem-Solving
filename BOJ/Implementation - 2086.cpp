/*

�Ǻ���ġ�� ������ ���ϴ� ���



( Fn+1  Fn   )  _  ( Fn   Fn-1 ) ( 1 1 )
( Fn    Fn-1 )  -  ( Fn-1 Fn-2 ) ( 1 0 ) �̴�
���� ��� ( 1 1 )
			( 1 0 ) �� n-1�� �����ϸ� Fn�� ���� �� �ִ�.

��� ���� �κа��� �̸� ���� ���� �Է¹��� ���� �������� ��ģ��.
�������� ��ģ �� 1�� �ڸ����� ���Ͽ� �ش� �κа��� ���� �ֱ⸸ 
�ϸ� Fn�� ���� �� �ִ�.

*/

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>    
#include <cstdio>
#include <string>
#include <queue>
#include <math.h>
#include <cstring>
using namespace std;

typedef unsigned long long ull;
const ull MOD = 1000000000;

struct mat {
	ull z_z = 0, z_o = 0, o_z = 0, o_o = 0;
};

mat matrix[110];
ull a, b;
string atr, btr;

mat cal(mat a, mat b) {

	mat c;
	c.z_z = ((a.z_z*b.z_z) % MOD + (a.z_o*b.o_z) % MOD) % MOD;
	c.z_o = ((a.z_z*b.z_o) % MOD + (a.z_o*b.o_o) % MOD) % MOD;
	c.o_z = ((a.o_z*b.z_z) % MOD + (a.o_o*b.o_z) % MOD) % MOD;
	c.o_o = ((a.o_z*b.z_o) % MOD + (a.o_o*b.o_o) % MOD) % MOD;

	return c;
}
int main()
{
	matrix[0].z_z = 1, matrix[0].z_o = 1, matrix[0].o_z = 1, matrix[0].o_o = 0;

	//�κа��� ��ó�� �Ѵ�.
	for (int i = 1; i < 110; i++)
		matrix[i] = cal(matrix[i - 1], matrix[i - 1]);

	cin >> a >> b;
	b++;

	//�������� ��ģ��.
	while (a)
		atr.push_back(a % 2 + '0'), a /= 2;
	while (b)
		btr.push_back(b % 2 + '0'), b /= 2;

	mat a, b;

	a.z_z = 1, a.z_o = 0, a.o_z = 0, a.o_o = 1;
	b.z_z = 1, b.z_o = 0, b.o_z = 0, b.o_o = 1;

	//1�� �ڸ����� ���Ͽ� �κа��� �����ش�.
	for (int i = 0; i < atr.size(); i++)
		if (atr[i] == '1')
			a = cal(a, matrix[i]);
	for (int i = 0; i < btr.size(); i++)
		if (btr[i] == '1')
			b = cal(b, matrix[i]);

	cout << (b.z_z - a.z_z + MOD) % MOD << endl;
}