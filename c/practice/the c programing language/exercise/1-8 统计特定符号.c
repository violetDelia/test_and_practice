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
	printf("%d�����з���%d���ո�%d���Ʊ��", c, m, p);
	
}
