#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
char in[81];

bool isword(char c){
	return (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z');
}

int main() 
{	
	cin.getline(in,80);
	for (int i = 0; in[i]; i ++){
		if (isword(in[i])){
			if (in[i] == 'z')
				in[i] = 'a';
			else if (in[i] == 'Z')
				in[i] = 'A';
			else
				in[i] += 1;//in[i] ++;
		} 
	}
	for (int i = 0; in[i]; i ++){
		cout << in[i];
	}
	return 0;
}
/*在情报传递过程中，为了防止情报被截获，往往需要对情报用一定的方式加密，简单的加密算法虽然不足以完全避免情报被破译，但仍然能防止情报被轻易的识别。我们给出一种最简的的加密方法，对给定的一个字符串，把其中从a-y，A-Y的字母用其后继字母替代，把z和Z用a和A替代，其他非字母字符不变，则可得到一个简单的加密字符串。*/
