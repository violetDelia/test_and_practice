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
/*���鱨���ݹ����У�Ϊ�˷�ֹ�鱨���ػ�������Ҫ���鱨��һ���ķ�ʽ���ܣ��򵥵ļ����㷨��Ȼ��������ȫ�����鱨�����룬����Ȼ�ܷ�ֹ�鱨�����׵�ʶ�����Ǹ���һ�����ĵļ��ܷ������Ը�����һ���ַ����������д�a-y��A-Y����ĸ��������ĸ�������z��Z��a��A�������������ĸ�ַ����䣬��ɵõ�һ���򵥵ļ����ַ�����*/
