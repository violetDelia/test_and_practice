#include <malloc.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#define Elemtype int //元素类型

typedef struct LinkListNode
{
    Elemtype elem;
    struct LinkListNode *next;
} LinkList;
void CreatLinkList(LinkList *&newlist, int num) //建立一个有num个元素的新表,头插法
{
    newlist = (LinkList *)malloc(sizeof(LinkList));
    if (newlist == NULL)
    {
        printf("分配头结点失败\n");
        return;
    }
    newlist->elem = 0;
    newlist->next = newlist;
    printf("输入%d个数据头插入链表\n",num);
    for (int i = 1; i <= num; i++)
    {
        LinkList *Node = (LinkList *)malloc(sizeof(LinkList));
        if (Node == NULL)
        {
            printf("第%d个元素分配空间失败\n", i);
            return;
        }
        scanf("%d", &Node->elem);
        Node->next = newlist->next;
        newlist->next = Node;
        (int)newlist->elem++;
    }
}
void PrintLinkList(LinkList *&list) //从前到后输出链表元素
{
    LinkList *position = list;
    printf("共有%d个元素\n", (int)position->elem);
    int n = 0;
    while ((int)list->elem > n)
    {
        position = position->next;
        printf("%d ", position->elem);
        n++;
    }
    printf("\n");
    return;
}
void ReplaceLinklistNode(LinkList *&list, int i, Elemtype &Date) //将Date的值赋给list的第i个元素
{
    LinkList *position = list;
    if ((i > (int)list->elem) && (int)list->elem != 0)
    {
        printf("链表中没有此位置\n");
        return;
    }
    for (int n = i; n; n--)
    {
        position = position->next;
    }
    position->elem = Date;
    printf("已将第%d个元素替换为%d\n", i, (int)position->elem);
    return;
}
void InsertLinkList(LinkList *&list, int i, Elemtype &Date) //将Date插入list的i个元素之前
{
    if ((i > (int)list->elem) && (int)list->elem != 0)
    {
        printf("链表中没有此位置\n");
        return;
    }
    LinkList *position = list;
    for (int n = i - 1; n; n--)
    {
        position = position->next;
    }
    LinkList *Node = (LinkList *)malloc(sizeof(LinkList));
    Node->elem = Date;
    if (i == (int)list->elem)
    {
        Node->next = position->next;
    }
    position->next = Node;
    (int)list->elem++;
    printf("已将%d插入表中第%d个位置\n", Date, i);
    return;
}
void DeleteLinkList(LinkList *&list, int i) //删除链表中第i个元素
{
    if ((i > (int)list->elem) && (int)list->elem != 0)
    {
        printf("链表中没有此位置\n");
        return;
    }
    LinkList *position = list;
    for (int n = i - 1; n; n--)
    {
        position = position->next;
    }
    LinkList *DeleteNode = position->next;
    position->next = position->next->next;
    printf("已删除第%d个位置的元素%d\n", i, (int)DeleteNode->elem);
    free(DeleteNode);
    (int)list->elem--;
    return;
}
void MergeLinkList(LinkList *&list1, LinkList *&list2)
{
    LinkList *tail1 = list1;
    for (int i = (int)list1->elem; i; i--)
    {
        tail1 = tail1->next;
    }
    LinkList *tail2 = list2;
    for (int i = (int)list2->elem; i; i--)
    {
        tail2 = tail2->next;
    }
    tail1->next = list2->next;
    tail2->next = list1;
    int a = (int)list2->elem;
    list1->elem = list1->elem + a;
    free(list2);
    printf("合并成功");
    return;
}
void SortList(LinkList *&list, bool (*compare)(Elemtype, Elemtype))
{
}
bool Compare(Elemtype, Elemtype) {}
int main()
{
    LinkList *list;
    CreatLinkList(list, 4);
    PrintLinkList(list);
    int a = 5;
    ReplaceLinklistNode(list, 5, a);
    ReplaceLinklistNode(list, 4, a);
    PrintLinkList(list);
    int b = 4;
    InsertLinkList(list, 5, b);
    InsertLinkList(list, 4, b);
    PrintLinkList(list);
    DeleteLinkList(list, 6);
    DeleteLinkList(list, 5);
    PrintLinkList(list);
    LinkList *list1;
    CreatLinkList(list1, 1);
    MergeLinkList(list, list1);
    PrintLinkList(list);
    std::system("pause");
    return 0;
}