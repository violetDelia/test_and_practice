#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	double f = 9.14;
	int n = (int) f;
	f = n / 2;
	cout<<f<<endl;
	f = double(n) / 2;
	cout<<f<<endl;
	return 0;
}
