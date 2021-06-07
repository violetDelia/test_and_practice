#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n, m;
	int total = 0;
	cin >> n >> m;
	for (int i = 0; i < n; ++ i){
		for (int j = i + 1; j <= n; ++j)
			if (m % (i + j) == 0)
				++ total;		
	}
	cout << total;
	return 0;
}
