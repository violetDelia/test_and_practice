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
/*ĳҽԺ��ͳ��һ��ĳ����Ļ������������Ƿ��йأ���Ҫ����ǰ����ϼ�¼������������0-18��19-35��36-60��61���ϣ���61���ĸ������ͳ�ƵĻ�������ռ�ܻ��������ı����� 
