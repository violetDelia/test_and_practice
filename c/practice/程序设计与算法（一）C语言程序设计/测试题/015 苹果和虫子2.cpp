#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
int main()
{
	int n, x, y;
	cin >> n >> x >> y;
	for (;y >= x; n --){
		if (n == 0){
			break;
		}else{
			y -= x;
		}
		}
	if (y != 0 && n > 0)
		n --;
	cout << n;
	
	return 0;
} 
/* ������һ��n��ƻ�����ܲ��ҵ�������ʱ��������
��һ�����ӡ�����ÿxСʱ�ܳԵ�һ��ƻ�������������
����һ��ƻ��֮ǰ�������һ������ô����yСʱ�㻹��
���ٸ�������ƻ����*/ 
