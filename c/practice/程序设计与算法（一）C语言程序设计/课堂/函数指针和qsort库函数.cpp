#include <cstdio>
#include <cstdlib>
using namespace std;
int MyCompare( const void * elem1, const void * elem2 )
{
	unsigned int * p1, * p2;
	p1 = (unsigned int *) elem1; // ��* elem1�� �Ƿ�
	p2 = (unsigned int *) elem2; // ��* elem2�� �Ƿ�
	return (* p1 % 10) - (* p2 % 10 ); 
}
#define NUM 5
int main() 
{
	unsigned int an[NUM] = { 8,123,11,10,4 };
	qsort( an,NUM,sizeof(unsigned int),MyCompare); 
	for( int i = 0;i < NUM; i ++ )
		printf("%d ",an[i]);
	return 0;
}

