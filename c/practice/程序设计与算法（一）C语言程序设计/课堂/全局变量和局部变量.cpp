#include <iostream>
using namespace std;
int n1 = 5, n2 = 10; //全局变量
void Function1()
{
	int n3 =4;
	n2 = 3;
}
void Function2()
{
	int n4;
	n1 = 4;
	n3 = 5; //编译出错，n3无定义
}
