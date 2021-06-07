#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
int main()
{
	long long a;
	cin >> a;
	
	while (a > 1){
		if (a % 2){
			cout << a << "*3+1=" << a*3+1 << endl;
			a = a * 3 + 1;
		}else{
			cout << a << "/2=" << a / 2 <<endl;
			a = a / 2;
		}		
	}
	cout << "End";
	return 0;
} 
/* 所谓角谷猜想，是指对于任意一个正整数，如果是奇数，则乘3加1，如果是偶数，则除以2，得到的结果再按照上述规则重复处理，最终总能够得到1。如，假定初始整数为5，计算过程分别为16、8、4、2、1。 
程序要求输入一个整数，将经过处理得到1的过程输出来。*/
