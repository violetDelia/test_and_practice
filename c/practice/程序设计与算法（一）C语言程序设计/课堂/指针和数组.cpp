#include <iostream>
using namespace std;
int main() {
	int a[200]; int * p ;
	p = a; // p指向数组a的起始地址，亦即p指向了a[0]
	* p = 10; //使得a[0] = 10
	*( p + 1 ) = 20; //使得 a[1] = 20
	p[0] = 30; //p[i] 和 *(p+i) 是等效的，使得a[0] = 30
	p[4] = 40; //使得 a[4] = 40
	for( int i = 0;i < 10; ++i) //对数组a的前10个元素进行赋值
		*( p + i) = i;
	++p; // p指向 a[1]
	cout << p[0] << endl; //输出1 p[0]等效于*p, p[0]即是a[1]
	p = a + 6; // p指向a[6]
	cout << * p << endl;// 输出 6
	return 0;
}
