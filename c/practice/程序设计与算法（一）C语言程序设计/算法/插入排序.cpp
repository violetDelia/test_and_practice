#include <iostream>
#include <cstring>
using namespace std;
void InsertionSort(int a[] ,int size)
{
	for(int i = 1;i < size; ++i ) { 
		//a[i]�����������Ԫ�أ�ÿ��ѭ����a[i]�ŵ�����λ��
		for(int j = 0; j < i; ++j) 
			if( a[j]>a[i]) { 
				//Ҫ��a[i]�ŵ�λ��j��ԭ�±�j�� i-1��Ԫ�ض�������һ��λ��
				int tmp = a[i];
				for(int k = i; k > j; --k)
					a[k] = a[k-1];
			a[j] = tmp;
			break;
		} 
	} 
}
