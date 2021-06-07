#include <iostream>
#include <cstring>
using namespace std;
void BubbleSort(int a[] ,int size)
{
	for(int i = size-1;i > 0; --i ) { 
		//每次要将未排序部分的最大值移动到下标i的位置
		for(int j = 0; j < i; ++j) //依次比较相邻的两个元素
			if( a[j] > a[j+1]) {
				int tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			} 
	}
}
