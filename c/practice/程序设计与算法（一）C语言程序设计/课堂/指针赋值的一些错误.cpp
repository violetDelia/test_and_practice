#include <iostream>
using namespace std;
int main() {
	int * pn, char * pc, char c = 0x65;
	pn = pc; //���Ͳ�ƥ�䣬�������
	pn = & c; //���Ͳ�ƥ�䣬�������
	pn = (int * ) & c;
	int n = * pn; //nֵ��ȷ��
	* pn = 0x12345678; //�����ܹ������п��ܳ���
///////////////////////////////////////// 
	int a;
	char * p = (char * ) &a; // &a�� int *����
	--p;
	printf("%c", * p); //���ܵ������д���
	* p = 'A'; //���ܵ������д���
}
