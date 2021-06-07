#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
int main()
{
	int n, max, min, a;
	max = 1;
	min = 10000;
	scanf("%d", &n);
	while(n != 0){
		scanf("%d", &a);
		if (a > max)
			max = a;
		if (a < min)
			min = a;
		n --;		
	}
	printf ("%d", max - min);	
	return 0;
} 
