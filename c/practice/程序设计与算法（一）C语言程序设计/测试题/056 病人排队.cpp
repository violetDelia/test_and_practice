#include <cstring>
#include <iostream>
using namespace std;
#define num 100
struct people
{
	int ID;
	int age;
} p[num];
int main()
{
	freopen("c:\\Users\\17335\\Desktop\\in.txt", "r", stdin);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i].ID >> p[i].age;
	}
	for (int i = 0; i < n - 1; i++)
	{
		int max = i;
		for (int j = i + 1; j < n; j++)
		{
			if (p[j].age >= 60 &&
				(p[j].age > p[max].age ||
				 p[j].age == p[max].age &&
					 p[j].ID > p[max].ID))
			{
				max = j;
			}
		}
		people tem = p[max];
		for (int k = max; k > i; k--)
		{
			p[k] = p[k - 1];
		}
		p[i] = tem;
	}
	for (int i = 0; i < n; i++)
	{
		cout << p[i].ID << endl;
	}
	return 0;
}
