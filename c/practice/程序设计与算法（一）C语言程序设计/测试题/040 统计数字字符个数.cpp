#include <iostream>
#include <cstring>

using namespace std;

char a[256];
int main() 
{
	int i = 0;
	int n = 0;
	cin.getline(a, 256);
	while (a[i]){
		if (a[i] >= '0' && a[i] <= '9')
			n ++;
		i ++;
	}
	cout << n;
}
