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
		for (int j = 0; j < cel; j ++)
			b[j][i] = a[i][j];
			
	for (int i = 0; i < cel; i ++){
		for (int j = 0; j < row; j ++){
			if (j == row - 1){
				cout << b[i][j];
				continue;
			}
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

