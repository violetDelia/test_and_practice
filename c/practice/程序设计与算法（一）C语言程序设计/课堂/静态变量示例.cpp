#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char str[] ="- This, a sample string, OK.";
	//����Ҫ��str�����ȡ����" ,.-"�⼸���ַ��ָ����ִ�
	char * p = strtok (str," ,.-"); 
	while ( p != NULL) //ֻҪp��ΪNULL����˵���ҵ���һ���Ӵ�
	{
	cout << p << endl;
	p = strtok(NULL, " ,.-");
	//�������ã���һ������������NULL
	}
	return 0;
}
char * Strtok(char * p,char * sep) 
{
	static char * start ; //���β����Ӵ������
	if(p)
		start = p;
	for(; *start && strchr(sep,*start); ++ start); //�����ָ�����
	if( * start == 0)
		return NULL; 
	char * q = start; 
	for(; *start && !strchr(sep,*start); ++ start); //�����Ƿָ�����
	if( * start) {
		* start = 0;
		++ start;
	}
	return q;
}

