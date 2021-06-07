#include <iostream>
using namespace std;
int main()
{
	int **pp; //指向int*类型指针的指针
	int * p; 
	int n = 1234;
	p = &n; // p指向n
	pp = & p; //pp指向p
	cout << *(*pp) << endl; // *pp是p, 所以*(*pp)就是n
	return 0;
}
