#include<stdio.h> 

int main()
{
	float C, F, span, maxmum ,minimum;
	
	span = 20.0;
	maxmum = 300.0;
	minimum = 0.0;
	
	C = minimum;
	
	printf ("»ªÊÏÎÂ¶È  ÉãÊÏÎÂ¶È\n\n");
	while (C<=maxmum) {
	F = C*9.0/5.0+32.0;
	printf("%5.0f  %8.0f\n",F,C);
	C = C+span;
	}
	
	return 0;
}
