#include<stdio.h>

main()
{
	int c, n;	
	c = 0;
	while ((n = getchar() )!= EOF){ 
		if (n == '\n')
			++c; 
		}
	printf("%d",c);
	
}
