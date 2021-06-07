#include <iostream>
using namespace std;

int bitManipulation3(int n, int i) {
// 使得函数返回值为一个整数,该整数的左边i位是n的左边i位取反，其余位和n相同
	return n ^ (~0 << (32 - i));
}

int main() {
	int t, n, i;
	cin >> t;
	while (t--) {
		cin >> n >> i;
		cout << bitManipulation3(n, i) << endl;
	}
	return 0;
}
