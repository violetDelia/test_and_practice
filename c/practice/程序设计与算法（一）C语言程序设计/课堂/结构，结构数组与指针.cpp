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

struct StudentEx //一个结构的成员变量可以是任何类型的，包括可以是另一个结构类型: 
{
	unsigned ID;
	char szName[20];
	float fGPA;
	Date birthday;
};
struct Employee //结构的成员变量可以是指向本结构类型的变量的指针
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
	unsigned int * p = & stu.ID; //p指向stu中的ID成员变量 
	/////////next//////// 
	StudentEx stu = { 1234,"Tom",3.78,{ 1984,12,28 }};//结构变量可以在定义时进行初始化:
	/////////结构数组///////
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
	/////////////定义指向结构变量的指针//////
	StudentEx * pStudent;
	StudentEx Stu1;
	pStudent = & Stu1;
	StudentEx Stu2 = * pStudent;
	////////通过指针，访问其指向的结构变量的成员变量：////
	StudentEx Stu;
	StudentEx * pStu;
	pStu = & Stu;
	pStu->ID = 12345;
	(*pStu).fGPA = 3.48;
	cout << Stu.ID << endl; //输出 12345
	cout << Stu.fGPA << endl; //输出 3.48
}
