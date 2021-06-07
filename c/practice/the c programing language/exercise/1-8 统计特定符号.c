#include<stdio.h>

main()
{
	int c, n, m, p;	
	
	c = 0;
	m = 0;
	p = 0;
	
	while ((n = getchar() )!= EOF){ 
		if (n == '\n')
			++c; 
		if (n == ' ')
			++m; 
		if (n == '\t')
			++p; 	
		}
	printf("%d个换行符，%d个空格，%d个制表符", c, m, p);
	
}
