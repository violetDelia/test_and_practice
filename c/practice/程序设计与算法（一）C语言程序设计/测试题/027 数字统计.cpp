#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
int main()
{
	int a, b, t;
	cin >> a >> b;
	for	(int i = a; i <= b ; i ++){
		for (int j = i; j; j /= 10){
			if (j % 10 == 2)
				t++;
		}
	}
	cout << t;
}
/*
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int L,R;
	int total = 0;
	cin >> L >> R; 

	for(int i = L; i <= R; ++i) {
		int n = i;
		while(n) {
			if( n % 10 == 2)
				++ total;
			n /= 10;				
		}
	}
	cout << total ;
	return 0;
}
*/
	
 
/*��ͳ��ĳ��������Χ[L, R]�����������У�����2���ֵĴ�����
���������Χ[2, 22]������2����2�г�����1�Σ�����12�г���1�Σ�����20�г���1�Σ�����21�г���1�Σ�����22�г���2�Σ���������2�ڸ÷�Χ��һ��������6�Ρ�  */
