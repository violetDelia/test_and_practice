#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
int main()
{
	int n, h, l, t, max;
	t = max = 0;
	//freopen ("C:\\Users\\17335\\Desktop\\in.txt","r",stdin);
	cin >> n;
	while(n != 0){
		cin >> h >> l;
		if ( h >= 90 && h <= 140 && l >= 60 && l <= 90 ){
			t ++;
			if (t > max)
				max = t;
		}else 
			t = 0;
		n --;	
	}
	cout << max;
	return 0;
} 
/* �໤��ÿСʱ����һ�β��˵�Ѫѹ��������ѹ��90 - 140֮�䲢������ѹ��60 - 90֮��
�������˵�ֵ�����֮Ϊ�������ָ���ĳ�������ɴβ�����Ѫѹֵ�����㲡�˱�������Ѫѹ���Сʱ����*/
