#include <iostream>
#include <iomanip>
#include <cstdio>

int max (long long, long long);
int min (long long, long long);

int main()
{
	long long a, b, n, m;
	scanf ("%lld %lld", &a, &b);
	n = max (a, b);
	m = min (a, b);
	
	while (n % m){
		long long k = n;
		n = m;
		m = k % n;	
	}
	printf ("%lld", m);
	return 0;
}
int max (long long a, long long b){
	if (a >= b)
		return a;
	else 
		return b;
}
int min (long long a, long long b){
	if (a >= b)
		return b;
	else 
		return a;
}
/*
#include <iostream>
#include <cstdio>
using namespace std;

int gcd(int a,int b)
{
	if( a%b == 0)
		return b;
	return gcd(b,a%b);
}

int main()
{
	int a,b;
	cin >> a >> b;
	cout << gcd(a,b);
	return 0;
}
*/
