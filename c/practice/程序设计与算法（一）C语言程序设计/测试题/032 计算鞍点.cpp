#include<iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

#define rows 5
#define cols 5 
int a[rows][cols] = {0,};
int main()
{	
	int row, col, colmax, rowmum, odd1, odd2;
	int p = 0;
	for (int i = 0; i < rows; i ++)
		for(int j = 0; j < cols; j ++)
			cin >> a[i][j];
	for (int i = 0; i < rows; i ++){
		odd1 = a[i][0];
		for (int j = 0; j < cols; j ++){
			if (a[i][j] >= odd1){
				odd1 = a[i][j];
				colmax = j;
				}
		}
		odd2 = a[0][colmax];
		for (int k =0; k < rows; k ++){
			if (a[k][colmax] <= odd2){
				odd2 = a[k][colmax];
				rowmum = k;
			}
		}
		if (odd1 == odd2){
		cout << rowmum + 1 << " " << colmax + 1 << " " << a[rowmum][colmax] << endl;
		p ++;
		}
	}
	if (p == 0)
		cout << "not found";
	return 0;	
} 
/*����һ��5*5�ľ���ÿ��ֻ��һ�����ֵ��ÿ��ֻ��һ����Сֵ��Ѱ���������İ��㡣
����ָ���Ǿ����е�һ��Ԫ�أ����������е����ֵ�������������е���Сֵ��*/
