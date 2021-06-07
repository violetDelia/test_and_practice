#include <iostream>
using namespace std;
int main() {
	int * pn, char * pc, char c = 0x65;
	pn = pc; //类型不匹配，编译出错
	pn = & c; //类型不匹配，编译出错
	pn = (int * ) & c;
	int n = * pn; //n值不确定
	* pn = 0x12345678; //编译能过但运行可能出错
///////////////////////////////////////// 
	int a;
	char * p = (char * ) &a; // &a是 int *类型
	--p;
	printf("%c", * p); //可能导致运行错误
	* p = 'A'; //可能导致运行错误
}
