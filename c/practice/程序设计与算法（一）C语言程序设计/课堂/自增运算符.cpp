#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a, b = 5;
	b ++;//b=6
	++ b;//b=7
	a = b ++;//8,
	cout << a <<","<< b << endl;
	a = ++ b;//9
	cout << a <<","<< b << endl;
	return 0;	
} 
