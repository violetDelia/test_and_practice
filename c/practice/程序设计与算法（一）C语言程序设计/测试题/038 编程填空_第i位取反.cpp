#include <iostream>
using namespace std;

int bitManipulation2(int n, int i) {
// 写出函数中缺失的部分，使得函数返回值为一个整数,该整数的第i位是n的第i位取反，其余位和n相同
	return (n ^ (1 << i));
}

int main() {
	int t, n, i;
	cin >> t;
	while (t--) {
		cin >> n >> i;
		cout << bitManipulation2(n, i) << endl;
	}
	return 0;
}
