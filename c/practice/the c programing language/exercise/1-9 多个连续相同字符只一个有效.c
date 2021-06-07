#include<stdio.h> 
#define zero 'a'
main()
{
	int c, last;
	
	c = getchar ();
	last = zero;
	 
	while (c != EOF){
		if (c != ' ' || last!= ' ')
		putchar(c);
		last = c;
	    c = getchar();
	}
	return 0;
}
