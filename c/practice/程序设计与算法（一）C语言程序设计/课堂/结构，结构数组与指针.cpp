#include <iostream>
#include <cstring>
using namespace std;

struct Student 
{
	unsigned ID;
	char szName[20];
	float fGPA;
};

struct Date 
{
	int year;
	int month;
	int day;
};

struct StudentEx //һ���ṹ�ĳ�Ա�����������κ����͵ģ�������������һ���ṹ����: 
{
	unsigned ID;
	char szName[20];
	float fGPA;
	Date birthday;
};
struct Employee //�ṹ�ĳ�Ա����������ָ�򱾽ṹ���͵ı�����ָ��
{
	string name;
	int age;
	int salary;
	Employee * next; 
};


int main(){
	StudentEx stu;
	cin >> stu.fGPA;
	stu.ID = 12345;
	strcpy(stu.szName, "Tom");
	cout << stu.fGPA;
	stu.birthday.year = 1984;
	unsigned int * p = & stu.ID; //pָ��stu�е�ID��Ա���� 
	/////////next//////// 
	StudentEx stu = { 1234,"Tom",3.78,{ 1984,12,28 }};//�ṹ���������ڶ���ʱ���г�ʼ��:
	/////////�ṹ����///////
	StudentEx MyClass [50];
	StudentEx MyClass2[50] = { 
	{ 1234,"Tom",3.78,{ 1984,12,28 }},
	{ 1235,"Jack",3.25,{ 1985,12,23 }},
	{ 1236,"Mary",4.00,{ 1984,12,21 }},
	{ 1237,"Jone",2.78,{ 1985,2,28 }}
	};
	MyClass[1].ID = 1267;
	MyClass[2].birthday.year = 1986;
	int n = MyClass[2].birthday.month;
	cin >> MyClass[0].szName;
	/////////////����ָ��ṹ������ָ��//////
	StudentEx * pStudent;
	StudentEx Stu1;
	pStudent = & Stu1;
	StudentEx Stu2 = * pStudent;
	////////ͨ��ָ�룬������ָ��Ľṹ�����ĳ�Ա������////
	StudentEx Stu;
	StudentEx * pStu;
	pStu = & Stu;
	pStu->ID = 12345;
	(*pStu).fGPA = 3.48;
	cout << Stu.ID << endl; //��� 12345
	cout << Stu.fGPA << endl; //��� 3.48
}
