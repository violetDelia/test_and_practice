#include<iostream>
using namespace std;

#define num 100
int a[num] = {0,};
int main()
{		
	int n, m, x;
	m = 0;
	scanf ("%d", &n);
	for (int i = 0; i < n; i ++){
		cin >> a[i];
	}
	scanf ("%d", &x);
	for (int i = 0; i < n; i ++){
		if (a[i] == x){
			m ++;
		}
	}
	printf ("%d\n", m);

	return 0;	
}

	
 
/*请统计某个给定范围[L, R]的所有整数中，数字2出现的次数。
比如给定范围[2, 22]，数字2在数2中出现了1次，在数12中出现1次，在数20中出现1次，在数21中出现1次，在数22中出现2次，所以数字2在该范围内一共出现了6次。  */
