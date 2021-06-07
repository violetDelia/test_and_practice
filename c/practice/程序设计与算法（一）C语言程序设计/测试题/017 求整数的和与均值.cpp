#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
int main()
{
	int n, sum, a;
	double av, an;
	sum = 0;
	scanf("%d", &n);
	an = double (n);
	while(n != 0){
		scanf("%d", &a);
		sum += a;
		av = (double (sum)) / an;
		n --;
	}
	printf ("%d %.5lf", sum, av);	
	return 0;
} 
