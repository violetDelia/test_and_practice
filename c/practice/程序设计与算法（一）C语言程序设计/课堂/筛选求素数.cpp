#include<iostream>
#include<cstdio>
#include<math.h>
#define num 1000
using namespace std;
char a[num+1];
int main()
{
	for (int i = 2; i <= num; i++)
		a[i] = 1;
	for (int i = 2; i <= num; i ++){
		if (a[i])
			for (int j = 2 * i; j <= num; j += i)
				a[j] = 0;
	}
	for (int i = 1; i <= num; i++)
		if (a[i])
			cout << i << endl;
	return 0;
		
	
}

	
 
/*��ͳ��ĳ��������Χ[L, R]�����������У�����2���ֵĴ�����
���������Χ[2, 22]������2����2�г�����1�Σ�����12�г���1�Σ�����20�г���1�Σ�����21�г���1�Σ�����22�г���2�Σ���������2�ڸ÷�Χ��һ��������6�Ρ�  */
