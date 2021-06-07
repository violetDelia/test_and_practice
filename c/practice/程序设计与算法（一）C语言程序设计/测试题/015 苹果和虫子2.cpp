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
/* 你买了一箱n个苹果，很不幸的是买完时箱子里混进
了一条虫子。虫子每x小时能吃掉一个苹果，假设虫子在
吃完一个苹果之前不会吃另一个，那么经过y小时你还有
多少个完整的苹果？*/ 
