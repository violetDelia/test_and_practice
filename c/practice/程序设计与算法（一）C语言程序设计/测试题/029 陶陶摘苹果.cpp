#include<iostream>
using namespace std;

#define num 10
#define apple 10
#define chair 30 
int a[num] = {0,};
int main()
{	
	int n, m;
	m = 0;
	for (int i = 0; i < apple; i ++){
		cin >> a[i];
	}
	cin >> n;
	for (int i = 0; i < apple; i ++){
		if (a[i] <= n + chair){
			m ++; 
		}
	}
	cout << m;
	return 0;	
}
/* ���ռҵ�Ժ������һ��ƻ������ÿ���������Ͼͻ���10��ƻ����ƻ�������ʱ�����վͻ���ȥժƻ���������и�30���׸ߵİ�ʣ���������ֱ������ժ��ƻ����ʱ�򣬾ͻ�ȵ�����������ԡ�
������֪10��ƻ��������ĸ߶ȣ��Լ����հ�����ֱ��ʱ���ܹ��ﵽ�����߶ȣ����������һ�����ܹ�ժ����ƻ������Ŀ������������ƻ����ƻ���ͻ��������
