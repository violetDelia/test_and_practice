#include<iostream>
using namespace std;

#define num 100
int a[num] = {0,};
int main()
{		
	int n, m, x;
	m = 0;
	scanf ("%d", &n);
	for (int i = 0; i < n; i ++){
		cin >> a[i];
	}
	scanf ("%d", &x);
	for (int i = 0; i < n; i ++){
		if (a[i] == x){
			m ++;
		}
	}
	printf ("%d\n", m);

	return 0;	
}

	
 
/*��ͳ��ĳ��������Χ[L, R]�����������У�����2���ֵĴ�����
���������Χ[2, 22]������2����2�г�����1�Σ�����12�г���1�Σ�����20�г���1�Σ�����21�г���1�Σ�����22�г���2�Σ���������2�ڸ÷�Χ��һ��������6�Ρ�  */
