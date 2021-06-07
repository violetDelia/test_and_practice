#include <iostream>
using namespace std;
int main() {
	char ch1 = 'A';
	char * pc = &ch1; // 使得pc 指向变量ch1
	* pc = 'B'; // 使得ch1 = 'B'
	char ch2 = * pc; // 使得ch2 = ch1
	pc = & ch2; // 使得pc 指向变量ch2
	* pc = 'D'; // 使得ch2 = 'D'
	return 0;
}
