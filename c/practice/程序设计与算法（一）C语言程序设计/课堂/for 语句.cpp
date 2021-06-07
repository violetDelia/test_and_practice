#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	for(int i=0;i<26;++i){
		cout << char('a'+i);
	}
	cout << endl;
	for( int i = 0; i<26; i += 2){
		cout << char ('A' + i);
	}
	cout << endl;
	for ( int i = 15, j = 0; i > j; i-=2, i -= 2, j += 3)
		cout << i << "," << j <<endl;
	
	return 0;
}
