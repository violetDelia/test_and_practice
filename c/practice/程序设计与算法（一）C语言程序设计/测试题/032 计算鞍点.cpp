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
/*给定一个5*5的矩阵，每行只有一个最大值，每列只有一个最小值，寻找这个矩阵的鞍点。
鞍点指的是矩阵中的一个元素，它是所在行的最大值，并且是所在列的最小值。*/
