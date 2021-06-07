#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
int main()
{
	int a, n, r;
	cin >> a >> n;
	r = 1;
		while(n != 0){
			r *= a;
			n --; 
		}
	cout << r;
	return 0;
} 
