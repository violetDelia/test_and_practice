#include <iostream>
#include <cstring>
using namespace std;
void SelectionSort(int a[] ,int size)
{
	for( int i = 0; i < size - 1; ++i )
	{//ÿ��ѭ���󽫵�iС��Ԫ�طź�
		int tmpMin = i; 
		//������¼�ӵ�i������size-1��Ԫ���У���С���Ǹ�Ԫ�ص��±�
		for( int j = i+1; j < size ; ++j) 
		{
			if( a[j] < a[tmpMin] ) 
				tmpMin = j;
		}
	//���潫��iС��Ԫ�ط��ڵ�i��λ���ϣ�����ԭ��ռ�ŵ�i��λ�ӵ�Ԫ��Ų������
		int tmp = a[i];
		a[i] = a[tmpMin]; 
		a[tmpMin] = tmp; 
	} 
} 
