#include <iostream>
using namespace std;

int bitManipulation1(int n, int m, int i) {
// 写出函数中缺失的部分，使得函数返回值为一个整数,该整数的第i位和m的第i位相同，其他位和n相同。
	return (n & (~(1 << i))|((m >> i) & 1) <<i);
}

int main() {
	int n, m, i, t;
	cin >> t;
	while (t--) { 
		cin >> n >> m >> i;
		cout << bitManipulation1(n, m, i) << endl;
	}
	return 0;
}
