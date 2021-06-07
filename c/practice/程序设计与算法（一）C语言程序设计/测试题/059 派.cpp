//By Guo Wei
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
//const double PI = 3.1415927;   PIȡ3.1415926�����У����ƫС�� PIȡ3.1415927���� 
const double PI=acos(-1.0); 
const double eps = 1e-6;
int r[10010];
int N,F;
bool Valid(double V)
{
	if( V < eps )
		return true;
	int total = 0;
	for(int i = 0;i < N; ++i) {
		double n =  r[i]*r[i] / V;
		total += n;
		if( total >= F)
			return true;
	}
	return false;
}
int main()
{
	cin >> N >> F;
	++F;
	double maxV = 0;
	for(int i = 0;i < N; ++i) {
		cin >> r[i];
		maxV = max(maxV,(double)r[i]*r[i]);
	}
	double L = 0,R = maxV;
	while( R - L > eps ) {
		double midV = L + (R-L )/2;
		if( Valid(midV) ) 
			L = midV;
		else 
			R = midV;
	}
	cout << fixed << setprecision(3) << PI * L ;
	return 0;
}
/*�ҵ�����Ҫ���ˣ�����ϰ�ף�����Ҫ��һЩ�ɷָ���ҡ�����N����ͬ��ζ����ͬ��С���ɡ���F�����ѻ����μ��ҵ��ɶԣ�ÿ���˻��õ�һ���ɣ�����һ���ɵ�һ�飬�����ɼ����ɵ�С��ƴ�ɣ�������һ�����ɣ���
�ҵ������Ƕ��ر�С������������õ������һ�飬�ͻῪʼ��Թ������������õ�������ͬ����С�ģ�������Ҫ��ͬ����״�ģ�����Ȼ������Щ�ɻᱻ�˷ѣ����ܱȸ��������ɶԺá���Ȼ����ҲҪ���Լ���һ�飬����һ��ҲҪ�������˵�ͬ����С��

��������ÿ�����õ���������Ƕ��٣�ÿ���ɶ���һ����Ϊ1���뾶���ȵ�Բ���塣*/
