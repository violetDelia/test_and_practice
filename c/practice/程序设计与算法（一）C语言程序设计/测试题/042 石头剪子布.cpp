#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char p1[10];
char p2[10];
char player1[] = {"Player1"};
char player2[] = {"Player2"};
char Tie[] = {"Tie"};
int all[100];

int main() 
{	
	int n;
	cin >> n;
	for (int i = 0; i < n; i ++){
		cin >> p1 >> p2;
		if (p1[0] == p2[0]) 
			all [i] = 2;
		else if (p1[0] == 'R'){
			if (p2[0] == 'S')
				all[i] = 0;
			else
				all[i] = 1;
		}else if(p1[0] == 'P')
			if (p2[0] == 'R')
				all[i] = 0;
			else
				all[i] = 1;
		else if (p1[0] == 'S')
			if (p2[0] == 'R')
				all[i] = 1;
			else
				all[i] = 0;		
	}
	for (int i = 0; i < n; i ++){
		if (all[i] == 1)
			cout << player2 << endl;
		else if (all[i] == 0)
			cout << player1 << endl;
		else if (all[i] == 2)
			cout << Tie << endl;
	}
	return 0;
}
