#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a = 10;
	int b = 3;
	double d = a/b; // a/b ��ֵҲ�����ͣ���ֵ��3
	cout << d << endl; //��� 3
	d = 5/2; //d��ֵ��Ϊ2.0
	cout << d << endl; //��� 2
	d = 5/2.0; 
	cout << d << endl; //��� 2.5
	d = (double)a/b;
	cout << d << endl; //��� 3.33333
	return 0;
}
