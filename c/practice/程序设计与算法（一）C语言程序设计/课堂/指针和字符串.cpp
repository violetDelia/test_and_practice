#include <iostream>
using namespace std;
int main() 
{
	char * p = "Please input your name:\n";
	cout << p ; // Èô²»ÓÃcout, printf(p) Òà¿É
	char name[20];
	char * pName = name;
	cin >> pName; 
	cout << "Your name is " << pName;
	return 0;
}

