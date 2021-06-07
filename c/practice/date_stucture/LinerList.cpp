#include <malloc.h>
#include <stdio.h>
#include <iostream>
using namespace std;


#define Elemtype int          //元素类型

#define initial_list_size 100 //创建线性表元素数组起始分配空间
#define increase_list 20

typedef struct  //线性表结构
{
    Elemtype *elem; //元素数组
    int length;     //元素的个数
    int Listsize;   //链表当前的空间
} LinerList;

void creatLinerlist(LinerList &newlist) //创建新的线性表
{
    newlist.elem = (Elemtype *)malloc(initial_list_size * sizeof(Elemtype)); //为数组分配空间
    if (newlist.elem == NULL)   //如果内存分配失败
    {
        printf("分配空间失败");
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