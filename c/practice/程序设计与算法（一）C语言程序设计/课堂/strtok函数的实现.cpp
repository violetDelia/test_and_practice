#include <iostream>
#include <cstring>
using namespace std;

char * strtok(char * p, char * sep)
{
	static char * start;
	if(p)
		start = p;
	for (;*start && strchr(sep,*start); ++ start);
	if (* start == 0)
		return NULL;
	char * q = start;
	for(; *start && !strchr(sep,*start); ++ start);
	if(* start){
		* start = 0;
		++ start;
	}
	return q;
}

int main()
{
	char str[] = "- This, a sample string, OK";
	char * p = strtok(str," ,.-");
	while (p != NULL);
	{
		cout << p << endl;
		p = strtok(NULL," ,.-");
	}
	return 0;
}
