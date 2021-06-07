#include <iostream>
#include <cstring>
#define num 100000
using namespace std;

char a[num + 1];
int main() 
{	
	int n = 0;
	cin.getline(a, sizeof(a));
	for (int i = 0; a[i]; i ++){
		if (n == 1)
			break;
		for (int j = 0; j <= sizeof(a) + 1; j++){
			if (i == j)
				continue;
			if (a[i] == a[j])
				break;
			if (j == sizeof(a) + 1){
				cout << a[i];
				n ++;
				} 
		}
	}
	if (n == 0)
		cout << "no";
}
