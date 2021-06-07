#include <iostream>
#include <cstring>
using namespace std;
struct stu 
	{
		char name[30];
		int s;
	};
stu student[20];

int main()
{
	int n;
	cin >> n;
	for (int k = 0; k < n; k ++)
	{
		cin >> student[k].name >> student[k].s;
	}
	for (int i = 0; i < n - 1; i ++)
	{	
		int max = i;
		for (int j = i + 1; j < n; j++)
		{
			if (student[max].s < student[j].s || 
				student[max].s == student[j].s &&
				strcmp(student[j].name, student[max].name) < 0)
			{
				max = j;
			}
		}
		stu p = student[i];
		student[i] = student[max];
		student[max] = p;
	}
	for (int i = 0; student[i].s; i ++)
	{
		cout << student[i].name << " " << student[i].s << endl;
	}
	return 0;
}
