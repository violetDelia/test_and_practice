#include <iostream>
using namespace std;

int bitManipulation3(int n, int i) {
// ʹ�ú�������ֵΪһ������,�����������iλ��n�����iλȡ��������λ��n��ͬ
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
