#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
int main()
{
	double a,b,c,x1,x2,f;
	scanf("%lf %lf %lf",&a,&b,&c);
	if(b*b==4*a*c){
		x2=x1=(-b+sqrt(b*b-4*a*c))/(2*a);
		printf("x1=x2=%.5lf",x1);
	}else if(b*b>4*a*c){
		x1=(-b+sqrt(b*b-4*a*c))/(2*a);
		x2=(-b-sqrt(b*b-4*a*c))/(2*a);
		printf("x1=%.5lf;x2=%.5lf",x1,x2);
	}else{
		x1=x2=(b/(2*a))*-1;
		if(x1==-0)
			x1=x2=0;
		f=sqrt(4*a*c-b*b)/(2*a);
		printf("x1=%.5lf+%.5lfi;x2=%.5lf-%.5lfi",x1,f,x2,f);
	}
	return 0;
} 
