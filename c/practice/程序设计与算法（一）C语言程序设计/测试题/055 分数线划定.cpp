#include <iostream>
#include <cstring>
using namespace std;
#define num 9000
struct student 
	{
		int sq;
		int s;
	}st[num];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i ++)
	{
		cin >> st[i].sq >> st[i].s;
	}
	for (int i = 0; i < n - 1; i ++)
	{
		int max = i;
		for (int j = i + 1; j < n; j ++)
		{
			if (st[j].s > st[max].s ||
				st[j].s == st[max].s &&
				st[j].sq < st[max].sq)
				{
					max = j;
				}
		}
		student p = st[i];
		st [i] = st [max];
		st [max] = p;
	}
	int k = m * 1.5;
	int x = st[k - 1].s;
	while (st[k].s == x)
	{
		k ++;
	}
	cout << x << " " << k << endl;
	for (int i = 0; i < k ; i ++)
	{
		cout << st[i].sq << " " << st[i].s << endl;
	}

	return 0;
}
