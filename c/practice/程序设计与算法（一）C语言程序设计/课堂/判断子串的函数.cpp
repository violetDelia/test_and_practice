#include <iostream>
#include <cstring> //要使用字符串库函数需要包含此头文件
using namespace std;
int Strstr(char s1[],char s2[]) {
	if(s2[0] == 0)
		return 0;
	for (int i = 0; s1[i]; ++ i) { //枚举比较起点
		int k = i, j = 0;
		for(; s2[j]; ++ j,++ k) {
			if(s1[k] != s2[j])
				break;
	}
		if( s2[j] == 0)
			return i;
	}
	return -1;
}
