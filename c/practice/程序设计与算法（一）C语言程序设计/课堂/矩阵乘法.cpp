#include<iostream>
using namespace std;
#define rows 10
#define cols 10
int a [rows][cols];
int b [rows][cols];
int c [rows][cols];
int main()
{		
	int m, n, p, q;
	cin >> m >> n;//读入a矩阵 
	for (int i = 0; i < m; ++ i)
		for (int j = 0; j < n; ++ j)
			cin >> a[i][j];
	cin >> p >> q;//读入b矩阵 
	for (int i = 0; i < p; ++ i)
		for (int j = 0; j < q; ++ j)
			cin >> b[i][j];
	for (int i = 0; i < m; ++ i){
		for (int j = 0; j < q; ++ j){
			c[i][j] = 0;
			for (int k = 0; k < n; ++ k)
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	for (int i = 0; i < m; ++ i){
		for (int j = 0; j < q; ++ j){
			cout << c [i][j] << " ";
		}
		cout << endl;
	}
	return 0;	
}

	
 
/*请统计某个给定范围[L, R]的所有整数中，数字2出现的次数。
比如给定范围[2, 22]，数字2在数2中出现了1次，在数12中出现1次，在数20中出现1次，在数21中出现1次，在数22中出现2次，所以数字2在该范围内一共出现了6次。  */
