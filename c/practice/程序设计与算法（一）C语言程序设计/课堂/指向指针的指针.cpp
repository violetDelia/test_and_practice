#include <iostream>
using namespace std;
int main()
{
	int **pp; //ָ��int*����ָ���ָ��
	int * p; 
	int n = 1234;
	p = &n; // pָ��n
	pp = & p; //ppָ��p
	cout << *(*pp) << endl; // *pp��p, ����*(*pp)����n
	return 0;
}
