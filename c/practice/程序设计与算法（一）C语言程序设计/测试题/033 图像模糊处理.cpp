#include<iostream>
#include <iomanip>
#include <cstdio>
using namespace std;
#define rows 100
#define cels 100
int a[rows][cels] = {0,};
int b[rows][cels] = {0,};
int main()
{	
	int row, cel;
	cin >> row >> cel;
	for (int i = 0; i < row; i ++)
		for (int j = 0; j < cel; j ++)
			cin >> a[i][j];
	for (int i = 0; i < row; i ++)
		for (int j = 0; j < cel; j ++){
			if (i == 0 || i == row -1)
				b[i][j] = a[i][j];
			else if (j == 0 || j == cel - 1)
				b[i][j] = a[i][j];
			else{
				b[i][j] = (a[i][j] + a[i][j-1] + a[i][j+1] + a[i+1][j] + a[i-1][j]) / 5;
				if (double(a[i][j] + a[i][j-1] + a[i][j+1] + a[i+1][j] + a[i-1][j]) / 5 - b[i][j] >= 0.5)
					b[i][j] += 1;
			}
		}
	for (int i = 0; i < row; i ++){
		for (int j = 0; j < cel; j ++){
			if (j == cel - 1){
				cout << b[i][j];
				continue;
			}
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
}

