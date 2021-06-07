#include <iostream>
#include <cstring> //包含字符串库函数的声明
using namespace std;
int main() 
{
	char title[] = "Prison Break"; //title最后一个元素是'\0'
	char hero[100] = "Michael Scofield";
	char prisonName[100];
	char response[100];
	cout << "What's the name of the prison in " << title << endl;
	cin >> prisonName; //输入字符串
	if( strcmp( prisonName, "Fox-River") == 0 ) //字符串比较函数
		cout << "Yeah! Do you love " << hero << endl;
	else {
		//字符串拷贝函数
		strcpy( response, "It seems you haven't watched it!\n");
		cout << response;
	}
	title [0] = 't';
	title [3] = 0; //等效于 title [3] = '\0';
	cout << title << endl;
	return 0;
}
