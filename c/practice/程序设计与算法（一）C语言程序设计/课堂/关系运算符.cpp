#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a, n = 4;
	a = n > 4 && n < 5;cout<<a;
	a = n >= 2 && n < 5;cout<<a;
	a = 5 && 0;cout<<a;
	a = 4 && 1;cout<<a;
}
