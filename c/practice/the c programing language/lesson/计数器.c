#include<stdio.h>

main()
{
	long c;	
	c = 0;
	while (getchar() != EOF){
		++c;
		printf("��%ld���ַ�",c);
	}
}
