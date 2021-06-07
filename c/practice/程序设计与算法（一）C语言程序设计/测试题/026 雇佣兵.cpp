#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
int main()
{
	int Mmax, m, n, x, c, d, b;
	m = b = 0;
	cin >> Mmax >> n >> x;

	while (x >= 0){
		
		c = Mmax / n;
		c = c + (c * n < Mmax);
		if (c > x)
			break;
		x -= c;
		for (d = Mmax; d ; d --){
			b ++;
			if (b == n){
				n ++;
				b = 0;
			}
		}
	b = 0;		
	}
	cout << n;
		
}
	
 
/* 雇佣兵的体力最大值为M，初始体力值为0、战斗力为N、拥有X个能量元素。
当雇佣兵的体力值恰好为M时，才可以参加一个为期M天的战斗期，战斗期结束体力值将为0。在同一个战斗期内，雇佣兵每连续战斗n天，战斗力就会上升1点，n为当前战斗期开始时的战斗力。
一个战斗期结束后，雇佣兵需要用若干个能量元素使其体力恢复到最大值M，从而参加下一个战斗期。每个能量元素恢复的体力值不超过当前的战斗力。每个能量元素只能使用一次。
请问：雇佣兵的战斗力最大可以到达多少。*/
