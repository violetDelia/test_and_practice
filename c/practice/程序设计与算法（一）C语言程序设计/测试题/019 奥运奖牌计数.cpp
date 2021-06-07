#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
int main()
{
	int n, g, s, b, sum, sumg, sums, sumb;
	sum = sumg = sums = sumb = 0;
	scanf("%d", &n);
	while(n != 0){
		scanf("%d %d %d", &g, &s, &b);
		sumg += g;
		sums += s;
		sumb += b;
		sum = sumg + sums + sumb;
		n --;
	}
	printf ("%d %d %d %d", sumg, sums, sumb, sum);	
	return 0;
} 
