#include<stdio.h> 

int main()
{
	float C, F, span, maxmum ,minimum;
	
	span = 20.0;
	maxmum = 300.0;
	minimum = 0.0;
	
	F = minimum;
	
	printf ("»ªÊÏÎÂ¶È  ÉãÊÏÎÂ¶È\n\n");
	while (F<=maxmum) {
	C = (F-32.0)*5.0/9.0;
	printf("%3.0f  %11.2f\n",F,C);
	F = F+span;
	}
	
	return 0;
}
