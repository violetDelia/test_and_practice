#include <iostream>
using namespace std;
struct A {
	int nouse1;
	int nouse2;
	int n;
};
int mysort(void * a,int n,int w,
	int (* compare)(const void * e1,const void * e2)) {



	char * s = (char * ) a;
	for(int i = n-1;i >= 0; -- i)
		for(int j = 0; j < i; ++ j) {
			char * p1 = (char*)a + j * w;
			char * p2 = (char*)a + j * w + w;
			if( compare(p1,p2) > 0 ) {
				for(int k = 0; k < w; ++k) {
					char tmp = p1[k];
					p1[k] = p2[k];
					p2[k] = tmp;
				}
			}
		}

}
// �ڴ˴�������Ĵ���
int MyCompare1( const void * e1,const void * e2) 
{
	int * p1 = (int * ) e1;
	int * p2 = (int * ) e2;
	return * p1 - * p2;
}
int MyCompare2( const void * e1,const void * e2) 
{
	int * p1 = (int * ) e1;
	int * p2 = (int * ) e2;
	if( (* p1 %10) - (* p2 % 10))
		return (* p1 %10) - (* p2 % 10);
	else
		return * p1 - * p2;
}
int MyCompare3( const void * e1,const void * e2) 
{
	A * p1 = (A*) e1;
	A * p2 = (A*) e2;
	return p1->n - p2->n;
}
int a[20];
A b[20];
int main ()
{	
	int n;
	while(cin >> n) {
		for(int i = 0;i < n; ++i) {
			cin >> a[i];
			b[i].n = a[i];
		}
		mysort(a,n,sizeof(int),MyCompare1);
		for(int i = 0;i < n; ++i) 
			cout << a[i] << "," ;
		cout << endl;
		mysort(a,n,sizeof(int),MyCompare2);
		for(int i = 0;i < n; ++i) 
			cout << a[i] << "," ;
		cout << endl;
		mysort(b,n,sizeof(A),MyCompare3);
		for(int i = 0;i < n; ++i) 
			cout << b[i].n << "," ;
		cout << endl;
	}
	return 0;
}
