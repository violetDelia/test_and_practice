#include <iostream>
#include <cstring>
using namespace std;
void Func(int m)
{
	for( int i = 0; i < 4;++i ) {
		if( m <= 0 ) {
			int k = 3;
			m = m *( k ++ );
		}else {
			k = 0; //�������k�޶���
			int m = 4;
			cout << m;
		} 
	}
	i= 2; //�������i�޶���
}
