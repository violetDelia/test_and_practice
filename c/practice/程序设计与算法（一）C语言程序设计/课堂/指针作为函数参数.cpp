#include <iostream>
using namespace std;
void Swap( int *p1, int * p2) {
	int tmp = *p1; // 将p1指向的变量的值，赋给tmp
	*p1 = *p2; // 将p2指向的变量的值，赋给p1指向的变量
	*p2 = tmp; // 将tmp 的值赋给p2指向的变量。
}
int main() 
{
	int m = 3,n = 4;
	Swap( &m, &n); //使得p1指向m,p2指向n
	cout << m << " " << n << endl; //输出 4 3
	return 0;
}
