#include <iostream>
#include <cstring>
using namespace std;
void BubbleSort(int a[] ,int size)
{
	for(int i = size-1;i > 0; --i ) { 
		//ÿ��Ҫ��δ���򲿷ֵ����ֵ�ƶ����±�i��λ��
		for(int j = 0; j < i; ++j) //���αȽ����ڵ�����Ԫ��
			if( a[j] > a[j+1]) {
				int tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			} 
	}
}
