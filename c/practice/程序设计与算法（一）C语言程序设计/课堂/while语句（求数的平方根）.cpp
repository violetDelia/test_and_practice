#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	double n, xn, lastxn; 
	scanf ("%lf",&n);
	xn = n / 2.0;
	lastxn = 0.0;
	while (lastxn - xn > 0.001 || lastxn - xn < - 0.001){
		lastxn = xn;
		xn = (xn + n / xn) / 2;
		printf ("%lf\n", xn);
	}
	printf ("xn = %lf", xn);
}
