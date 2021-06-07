//By Guo Wei
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
//const double PI = 3.1415927;   PI取3.1415926都不行，结果偏小， PI取3.1415927可以 
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
/*我的生日要到了！根据习俗，我需要将一些派分给大家。我有N个不同口味、不同大小的派。有F个朋友会来参加我的派对，每个人会拿到一块派（必须一个派的一块，不能由几个派的小块拼成；可以是一整个派）。
我的朋友们都特别小气，如果有人拿到更大的一块，就会开始抱怨。因此所有人拿到的派是同样大小的（但不需要是同样形状的），虽然这样有些派会被浪费，但总比搞砸整个派对好。当然，我也要给自己留一块，而这一块也要和其他人的同样大小。

请问我们每个人拿到的派最大是多少？每个派都是一个高为1，半径不等的圆柱体。*/
