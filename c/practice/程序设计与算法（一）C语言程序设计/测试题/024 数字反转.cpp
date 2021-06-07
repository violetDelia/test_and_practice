#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
int main()
{
	long long n, m, r;
	m = r = 0;
	cin >> n;
	while (n % 10 == 0){
		n = n /10;
	} 
	while (n){
		r = n % 10;
		n = n / 10;
		m = m * 10 + r;
	}
	cout << m;
	return 0;
} 
/* */
