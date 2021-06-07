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

	
 
/*请统计某个给定范围[L, R]的所有整数中，数字2出现的次数。
比如给定范围[2, 22]，数字2在数2中出现了1次，在数12中出现1次，在数20中出现1次，在数21中出现1次，在数22中出现2次，所以数字2在该范围内一共出现了6次。  */
