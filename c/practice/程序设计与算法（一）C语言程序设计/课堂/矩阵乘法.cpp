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
	cin >> m >> n;//����a���� 
	for (int i = 0; i < m; ++ i)
		for (int j = 0; j < n; ++ j)
			cin >> a[i][j];
	cin >> p >> q;//����b���� 
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

	
 
/*��ͳ��ĳ��������Χ[L, R]�����������У�����2���ֵĴ�����
���������Χ[2, 22]������2����2�г�����1�Σ�����12�г���1�Σ�����20�г���1�Σ�����21�г���1�Σ�����22�г���2�Σ���������2�ڸ÷�Χ��һ��������6�Ρ�  */
