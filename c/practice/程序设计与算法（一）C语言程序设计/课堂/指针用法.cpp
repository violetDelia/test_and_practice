#include <iostream>
using namespace std;
int main() {
	char ch1 = 'A';
	char * pc = &ch1; // ʹ��pc ָ�����ch1
	* pc = 'B'; // ʹ��ch1 = 'B'
	char ch2 = * pc; // ʹ��ch2 = ch1
	pc = & ch2; // ʹ��pc ָ�����ch2
	* pc = 'D'; // ʹ��ch2 = 'D'
	return 0;
}
