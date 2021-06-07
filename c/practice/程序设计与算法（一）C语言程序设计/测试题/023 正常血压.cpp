#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
int main()
{
	int n, h, l, t, max;
	t = max = 0;
	//freopen ("C:\\Users\\17335\\Desktop\\in.txt","r",stdin);
	cin >> n;
	while(n != 0){
		cin >> h >> l;
		if ( h >= 90 && h <= 140 && l >= 60 && l <= 90 ){
			t ++;
			if (t > max)
				max = t;
		}else 
			t = 0;
		n --;	
	}
	cout << max;
	return 0;
} 
/* 监护室每小时测量一次病人的血压，若收缩压在90 - 140之间并且舒张压在60 - 90之间
（包含端点值）则称之为正常，现给出某病人若干次测量的血压值，计算病人保持正常血压的最长小时数。*/
