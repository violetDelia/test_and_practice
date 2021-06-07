#include<iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

#define num 1000000
int pell[num];

int main()
{
	int n;
	pell[0] = 1;
	pell[1] = 2;
	for (int i = 2; i < num; i++)
		pell[i] = (2 * pell[i-1] + pell[i-2]) % 32767;
	cin >> n;
	for (int i = 0; i < n; i++){
		int k;
		cin >> k;
		cout << pell[k-1] << endl;
	}	
	return 0;
}
/*Pell����a1, a2, a3, ...�Ķ����������ģ�a1 = 1, a2 = 2, ... , an = 2 * an ? 1 + an - 2 (n > 2)��
����һ��������k��Ҫ��Pell���еĵ�k��ģ��32767�Ƕ��١�*/
