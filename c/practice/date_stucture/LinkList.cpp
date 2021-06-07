#include <malloc.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#define Elemtype int //Ԫ������

typedef struct LinkListNode
{
    Elemtype elem;
    struct LinkListNode *next;
} LinkList;
void CreatLinkList(LinkList *&newlist, int num) //����һ����num��Ԫ�ص��±�,ͷ�巨
{
    newlist = (LinkList *)malloc(sizeof(LinkList));
    if (newlist == NULL)
    {
        printf("����ͷ���ʧ��\n");
        return;
    }
    newlist->elem = 0;
    newlist->next = newlist;
    printf("����%d������ͷ��������\n",num);
    for (int i = 1; i <= num; i++)
    {
        LinkList *Node = (LinkList *)malloc(sizeof(LinkList));
        if (Node == NULL)
        {
            printf("��%d��Ԫ�ط���ռ�ʧ��\n", i);
            return;
        }
        scanf("%d", &Node->elem);
        Node->next = newlist->next;
        newlist->next = Node;
        (int)newlist->elem++;
    }
}
void PrintLinkList(LinkList *&list) //��ǰ�����������Ԫ��
{
    LinkList *position = list;
    printf("����%d��Ԫ��\n", (int)position->elem);
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
void ReplaceLinklistNode(LinkList *&list, int i, Elemtype &Date) //��Date��ֵ����list�ĵ�i��Ԫ��
{
    LinkList *position = list;
    if ((i > (int)list->elem) && (int)list->elem != 0)
    {
        printf("������û�д�λ��\n");
        return;
    }
    for (int n = i; n; n--)
    {
        position = position->next;
    }
    position->elem = Date;
    printf("�ѽ���%d��Ԫ���滻Ϊ%d\n", i, (int)position->elem);
    return;
}
void InsertLinkList(LinkList *&list, int i, Elemtype &Date) //��Date����list��i��Ԫ��֮ǰ
{
    if ((i > (int)list->elem) && (int)list->elem != 0)
    {
        printf("������û�д�λ��\n");
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
    printf("�ѽ�%d������е�%d��λ��\n", Date, i);
    return;
}
void DeleteLinkList(LinkList *&list, int i) //ɾ�������е�i��Ԫ��
{
    if ((i > (int)list->elem) && (int)list->elem != 0)
    {
        printf("������û�д�λ��\n");
        return;
    }
    LinkList *position = list;
    for (int n = i - 1; n; n--)
    {
        position = position->next;
    }
    LinkList *DeleteNode = position->next;
    position->next = position->next->next;
    printf("��ɾ����%d��λ�õ�Ԫ��%d\n", i, (int)DeleteNode->elem);
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
    printf("�ϲ��ɹ�");
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