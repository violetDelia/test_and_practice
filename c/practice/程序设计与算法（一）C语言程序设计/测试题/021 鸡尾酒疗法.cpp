#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
int main()
{
	int n, asum, a, bsum, b;
	double aa, bb;
	scanf ("%d", &n);
	scanf ("%d %d",&asum, &a);
	aa = a / double (asum);
		while(n != 1){
		scanf ("%d %d",&bsum, &b);
		bb = b / double (bsum);
		if (aa - bb > 0.05)
			printf ("worse\n") ;
			else if (aa - bb < - 0.05)
			printf ("better\n") ;
			else printf("same\n");
			n--;
		}
	return 0;
} 
