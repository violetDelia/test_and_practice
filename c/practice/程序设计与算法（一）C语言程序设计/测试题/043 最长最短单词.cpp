#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char a[20201];
char word[200];
bool isword(char c){
	return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}
int main() 
{	
	cin.getline(a,20200);
	int longest = 0;
	int shortest = 0;
	int l = 0;
	int s = 1 << 10;
	int len = 0;
	int c = 0;
	char last = 0;
	int sl = strlen(a);
	for (int i = 0; i < sl; i ++){
		if (isword(a[i])){
			if (isword(last)){
				len ++;
			}else {
				c = i;
				len = 1;
			}
			last = a[i];
		} else {
			if (isword(last)){
				if (len > l){
					l = len;
					longest = c;
					}
				if (len < s){
					s = len;
					shortest = c;
				}
			}
			last = a[i];
		}
	}
	if (len > l){
		l = len;
		longest = c;
	}
	if (len < s){
		s = len;
		shortest = c;
	}
	for (int i = longest; isword(a[i]); i++)
		cout << a[i];
	cout << endl;
	for (int i = shortest; isword(a[i]); i++)
		cout << a[i];
	cout << endl;
	return 0;
}
