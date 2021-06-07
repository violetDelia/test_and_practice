#include<iostream>
#include<cstdio>
#include<math.h>
#define num 1000
using namespace std;
char a[num+1];
int main()
{
	for (int i = 2; i <= num; i++)
		a[i] = 1;
	for (int i = 2; i <= num; i ++){
		if (a[i])
			for (int j = 2 * i; j <= num; j += i)
				a[j] = 0;
	}
	for (int i = 1; i <= num; i++)
		if (a[i])
			cout << i << endl;
	return 0;
		
	
}

	
 
/*请统计某个给定范围[L, R]的所有整数中，数字2出现的次数。
比如给定范围[2, 22]，数字2在数2中出现了1次，在数12中出现1次，在数20中出现1次，在数21中出现1次，在数22中出现2次，所以数字2在该范围内一共出现了6次。  */
