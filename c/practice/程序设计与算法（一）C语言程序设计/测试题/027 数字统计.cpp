#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
int main()
{
	int a, b, t;
	cin >> a >> b;
	for	(int i = a; i <= b ; i ++){
		for (int j = i; j; j /= 10){
			if (j % 10 == 2)
				t++;
		}
	}
	cout << t;
}
/*
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int L,R;
	int total = 0;
	cin >> L >> R; 

	for(int i = L; i <= R; ++i) {
		int n = i;
		while(n) {
			if( n % 10 == 2)
				++ total;
			n /= 10;				
		}
	}
	cout << total ;
	return 0;
}
*/
	
 
/*请统计某个给定范围[L, R]的所有整数中，数字2出现的次数。
比如给定范围[2, 22]，数字2在数2中出现了1次，在数12中出现1次，在数20中出现1次，在数21中出现1次，在数22中出现2次，所以数字2在该范围内一共出现了6次。  */
