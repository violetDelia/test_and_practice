#include<iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

#define num 100 
#define zore 0
#define one 18
#define two 35
#define three 60
int a[num] = {0,};
int main()
{	
	int n;
	double teen, young, mid, old;
	teen = young = mid = old =0.0;
	cin >> n;
	for (int i = 0; i < n; i ++){
		cin >> a[i];
	} 	
	for (int i = 0; i <n; i ++){
		if (a[i] >= zore&& a[i] <= one)
			teen ++;
		if (a[i] > one && a[i] <= two)
			young ++;
		if (a[i] > two && a[i] <=three)
			mid ++;
		if (a[i] > three)
			old ++;
	}
	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << teen * 100.0 / n << "%" <<endl;
	cout << young * 100.0 / n << "%" <<endl;
	cout << mid * 100.0 / n << "%" <<endl;
	cout << old * 100.0 / n << "%" <<endl;
	return 0;	
}
/*某医院想统计一下某项疾病的获得与否与年龄是否有关，需要对以前的诊断记录进行整理，按照0-18、19-35、36-60、61以上（含61）四个年龄段统计的患病人数占总患病人数的比例。 
