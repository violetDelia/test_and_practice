#include<iostream>
using namespace std;
int monthday[13] = {-1,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{		
	int year, month, date;
	int days = 0;
	cin >> year >> month >> date;
	for (int y = 2010; y < year; ++ y){
		if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
			days += 366;
		else
			days += 365;
	}
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		monthday[2] = 29;
	for (int m = 1; m < month; ++ m)
		days += monthday[m];
	days += date;
	days -= 24;
	cout << days % 7 << endl;
	return 0;	
}

	
 
/*��ͳ��ĳ��������Χ[L, R]�����������У�����2���ֵĴ�����
���������Χ[2, 22]������2����2�г�����1�Σ�����12�г���1�Σ�����20�г���1�Σ�����21�г���1�Σ�����22�г���2�Σ���������2�ڸ÷�Χ��һ��������6�Ρ�  */
