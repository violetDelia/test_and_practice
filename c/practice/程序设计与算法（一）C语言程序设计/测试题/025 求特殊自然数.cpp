#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
int main()
{
#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
int main()
{
	int a, b, c, x;
	int n = 81;
	while (n < 7*7*7+7*7+7){
		x = n;
		c = x % 9;
		x = x / 9;
		b = x % 9;
		x = x / 9;
		a = x;
		if (a + b * 7 + c * 49 == n && a < 7 && b < 7 && c < 7 )
			break;
		n ++;
	}
	cout << n << endl;
	x = n;
	c = x % 9;
	x = x / 9;
	b = x % 9;
	x = x / 9;
	a = x;
	cout << c * 100 + b * 10 + a << endl;
	cout << a * 100 + b * 10 + c << endl;
		
}
} 
/* */
