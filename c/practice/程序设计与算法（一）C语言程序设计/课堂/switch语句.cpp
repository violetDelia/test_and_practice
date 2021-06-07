#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	switch (n%6){
		case 0:
			printf ("case 0\n");
			break;
		case 1:
			printf ("case 1\n");
		case 2:
		case 3:
			printf ("case 2 or 3\n");
			break;
		case 4:
			printf("case 4\n");
			break;
	}
		
	return 0;
}
