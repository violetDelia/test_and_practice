#include <malloc.h>
#include <stdio.h>
#include <iostream>
using namespace std;


#define Elemtype int          //Ԫ������

#define initial_list_size 100 //�������Ա�Ԫ��������ʼ����ռ�
#define increase_list 20

typedef struct  //���Ա�ṹ
{
    Elemtype *elem; //Ԫ������
    int length;     //Ԫ�صĸ���
    int Listsize;   //����ǰ�Ŀռ�
} LinerList;

void creatLinerlist(LinerList &newlist) //�����µ����Ա�
{
    newlist.elem = (Elemtype *)malloc(initial_list_size * sizeof(Elemtype)); //Ϊ�������ռ�
    if (newlist.elem == NULL)   //����ڴ����ʧ��
    {
        printf("����ռ�ʧ��");
        return;
    }
    newlist.length = 0;
    newlist.Listsize = initial_list_size;
    return;
}

int main()
{
    LinerList list;
    creatLinerlist(list);
    std::cout << list.elem << endl
              << list.length << endl
              << list.Listsize << endl;
    std::system("pause");
    return 0;
}