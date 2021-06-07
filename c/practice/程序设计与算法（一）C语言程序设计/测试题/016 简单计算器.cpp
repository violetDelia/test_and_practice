#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
int main()
{
	int a, b;
	char c;
	scanf ("%d %d %c", &a, &b, &c);// +43,-45,*42,/47
	if (c != '+' && c != '-' && c != '*' && c != '/'){
		printf ("Invalid operator!");
	}else{
		switch (int(c)){
			case 43 :
				printf("%d", a+b);
				break;
			case 45 :
				printf("%d", a-b);
				break;
			case 42 :
				printf("%d", a*b);
				break;
			case 47 :
				if (b == 0){
					printf ("Divided by zero!");
				}else{
					printf("%d", a/b);
				}
				break;
			}
	}
	return 0;
} 
