#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
int main()
{
	long long a;
	cin >> a;
	
	while (a > 1){
		if (a % 2){
			cout << a << "*3+1=" << a*3+1 << endl;
			a = a * 3 + 1;
		}else{
			cout << a << "/2=" << a / 2 <<endl;
			a = a / 2;
		}		
	}
	cout << "End";
	return 0;
} 
/* ��ν�ǹȲ��룬��ָ��������һ������������������������3��1�������ż���������2���õ��Ľ���ٰ������������ظ������������ܹ��õ�1���磬�ٶ���ʼ����Ϊ5��������̷ֱ�Ϊ16��8��4��2��1�� 
����Ҫ������һ������������������õ�1�Ĺ����������*/
