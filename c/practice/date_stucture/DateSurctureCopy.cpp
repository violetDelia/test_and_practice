#include <iostream>
#include <limits.h>
#include <malloc.h>
#include <stdio.h>

using namespace std;

#define ture true
//����Ԫ������
#define Elemtype int

/******************************************************************/
/****************************ͨ�ú���*******************************/
/******************************************************************/

//A��B�Ƿ����
bool compare_equal(Elemtype A, Elemtype B)
{
    if (A == B)
        return ture;
    return false;
}
//�������Ԫ��e
bool visit(Elemtype e)
{
    printf("%d\t", e);
    return ture;
}
//�������ֵ
int Max(int a, int b)
{
    return a > b ? a : b;
}
/*****************************************************************/
/****************************˳���********************************/
/*****************************************************************/

//���Ա�ṹ
typedef struct LinerList
{
    Elemtype *elem;
    int length;
    int listsize;
} MaxHeap, Heap, MinHeap;
//��ʼ�����Ա���
#define _initial_list_size 100
//���Ա��ڴ��������
#define _increase_list 20
//��ʼ�����Ա�
bool InitLinerlist(LinerList &newlist)
{
    newlist.elem = (Elemtype *)malloc(_initial_list_size * sizeof(Elemtype));
    if (!newlist.elem)
    {
        printf("����ռ�ʧ��\n");
        return false;
    }
    newlist.length = 0;
    newlist.listsize = _initial_list_size;
    return true;
}
//������Ա�ռ�õĶ�̬�ռ�
void DestroyLinerList(LinerList &list)
{
    free(list.elem);
    list.elem = NULL;
    list.length = 0;
    list.listsize = 0;
    return;
}
//��ջ򲻴���
bool EmptyLinerList(LinerList list)
{
    if (!list.elem)
    {
        printf("������\n");
        return ture;
    }
    if (!list.length)
    {
        printf("���\n");
        return ture;
    }
    return false;
}
//������Ϊ0
bool ClearLinerList(LinerList list)
{
    if (EmptyLinerList(list))
        return false;
    list.length = 0;
    return ture;
}
// ��list��i��Ԫ�ظ�ֵ��v
bool GetLinerList(LinerList list, int n, Elemtype &v)
{
    if (EmptyLinerList(list))
        return false;
    if (n < 1 || n > list.length)
    {
        printf("�޴�λ��\n");
        return false;
    }
    v = list.elem[n - 1];
    return ture;
}
//Ѱ��list�к�date����compare�����ĵ�һ��Ԫ�أ��������Ԫ�ص�λ��
int LocateLinerList(LinerList list,
                    Elemtype date, bool (*compare)(Elemtype, Elemtype))
{
    if (EmptyLinerList(list))
        return false;
    for (int i = 0; i < list.length; i++)
    {
        if (compare(list.elem[i], date))
            return i + 1;
    }
    // printf("δ�ҵ����ʵ�Ԫ��\n");
    return 0;
}
//��һ��date��ǰ��
bool PriorLinerList(LinerList list, Elemtype date, Elemtype &pre_date)
{
    int p = LocateLinerList(list, date, compare_equal);
    if (p > 1)
    {
        pre_date = list.elem[p - 2];
        return ture;
    }
    return false;
}
//��һ��date�ĺ��
bool NextLinerList(LinerList list, Elemtype date, Elemtype &pre_date)
{
    int p = LocateLinerList(list, date, compare_equal);
    if (p && p < list.length)
    {
        pre_date = list.elem[p];
        return ture;
    }
    printf("���ݲ�����\n");
    return false;
}
//��date�����n��λ��
bool InsertLinerList_direct(LinerList &list, int n, Elemtype date)
{
    if (!list.elem)
    {
        printf("������\n");
        return false;
    }
    if (n < 1 || n > list.length + 1)
    {
        printf("�޴�λ��\n");
        return false;
    }
    if (list.length == list.listsize)
    {
        printf("������!\n");
        //Elemtype *newbase;
        //newbase = (Elemtype *)realloc(list.elem, (list.listsize + _increase_list) * sizeof(Elemtype));
        //if (!newbase)
        //{
        //    printf("����ռ�ʧ��\n");
        return false;
        // }
        //list.elem = newbase;
        //list.listsize += _increase_list;
        //printf("����%d���ռ�\n", _increase_list);
    }
    for (int i = list.length; i >= n; i--)
    {
        list.elem[i] = list.elem[i - 1];
    }
    list.elem[n - 1] = date;
    list.length++;
    return ture;
}
//ɾ��list��n��Ԫ�أ�����ֵ����date
bool DeleteLinerList_direct(LinerList list, int n, Elemtype &date)
{
    if (EmptyLinerList(list))
        return false;
    if (n < 1 || n > list.length)
    {
        printf("�޴�λ��\n");
        return false;
    }
    date = list.elem[n - 1];
    for (int i = n; i < list.listsize; i++)
    {
        list.elem[i - 1] = list.elem[i];
    }
    list.length--;
    return ture;
}
//��ӡ���Ա��Ԫ��
bool PrintLinerList(LinerList list)
{
    if (EmptyLinerList(list))
        return false;
    for (int i = 0; i < list.length;)
    {
        visit(list.elem[i]);
        if (!(++i) % 10)
            printf("\n");
    }
    printf("\n\n");
    return ture;
}
//��newlist����д��list1��list2
bool MergeLinerList(LinerList list1, LinerList list2, LinerList &newlist)
{
    if (!list1.elem && !list2.elem && !newlist.elem)
    {
        printf("������\n");
        return false;
    }
    if (newlist.length)
    {
        printf("�±���������\n");
        return false;
    }
    newlist.elem = (Elemtype *)malloc((list2.length + list1.length + _initial_list_size) * sizeof(Elemtype));
    if (!newlist.elem)
    {
        printf("����ռ�ʧ��\n");
        return false;
    }
    newlist.listsize = list1.length + list2.length + _initial_list_size;
    for (int i = 0; i < list1.length; i++)
    {
        newlist.elem[newlist.length++] = list1.elem[i];
    }
    for (int i = 0; i < list2.length; i++)
    {
        newlist.elem[newlist.length++] = list2.elem[i];
    }
    return ture;
}
//��listA��listû�еĵ�����д��list֮��
bool unionLinerLisy(LinerList &list, LinerList listA)
{
    if (listA.length + list.length > list.listsize)
    {
        printf("��ռ䲻��\n");
        return false;
    }
    int e;
    for (int i = 1; i <= listA.length; i++)
    {
        GetLinerList(listA, i, e);
        if (!LocateLinerList(list, e, compare_equal))
        {
            InsertLinerList_direct(list, list.length + 1, e);
        }
    }
    return ture;
}

/*********************************/
/**************��*****************/
/*********************************/

//��������ռ�Ϊs������
bool CreateMaxHeap(MaxHeap &H, int s)
{
    if (H.elem = (Elemtype *)malloc(sizeof(Elemtype) * (++s)))
    {
        H.listsize = s;
        H.length = 1;
        H.elem[0] = INT_MAX;
        return ture;
    }
    return false;
}
//���Ƿ���
bool HeapIsFull(Heap H)
{
    if (H.length == H.listsize)
        return ture;
    return false;
}
//����e��MaxHeap
bool InsertMaxHeap(MaxHeap &H, Elemtype e)
{
    if (HeapIsFull(H))
        return false;
    int i = H.length++;
    for (; e > H.elem[i / 2]; i = i / 2)
        H.elem[i] = H.elem[i / 2];
    H.elem[i] = e;
    return ture;
}
//�ѿ�
bool HeapIsEmpty(Heap H)
{
    return (H.listsize == 1);
}
//ɾ�����ѵ����ֵ����ֵ��e
bool DeleteMaxHeap(MaxHeap &H, Elemtype &e)
{
    if (HeapIsEmpty(H))
        return 0;
    e = H.elem[1];
    int min = H.elem[--H.length];
    int f, c;
    for (f = 1; f * 2 <= H.length; f = c)
    {
        c = f * 2;
        if (c == H.length)
        {
            if (H.elem[c] > min)
            {
                H.elem[f] = H.elem[c];
                H.elem[c] = min;
                return ture;
            }
            return ture;
        }
        else
        {
            if (H.elem[c] < H.elem[c + 1])
                c++;
            H.elem[f] = H.elem[c];
            H.elem[c] = min;
        }
    }
    return ture;
}
//��������ռ�Ϊs����С��
bool CreateMinHeap(MinHeap &H, int s)
{
    if (H.elem = (Elemtype *)malloc(sizeof(Elemtype) * (++s)))
    {
        H.listsize = s;
        H.length = 1;
        H.elem[0] = INT_MIN;
        return ture;
    }
    return false;
}
//����e��MinHeap
bool InsertMinHeap(MinHeap &H, Elemtype e)
{
    if (HeapIsFull(H))
        return false;
    int i = H.length++;
    for (; e < H.elem[i / 2]; i = i / 2)
        H.elem[i] = H.elem[i / 2];
    H.elem[i] = e;
    return ture;
}
//ɾ����С�ѵ���Сֵ����ֵ��e
bool DeleteMinHeap(MinHeap &H, Elemtype &e)
{
    if (HeapIsEmpty(H))
        return 0;
    e = H.elem[1];
    int min = H.elem[--H.length];
    int f, c;
    for (f = 1; f * 2 <= H.length; f = c)
    {
        c = f * 2;
        if (c == H.length)
        {
            if (H.elem[c] < min)
            {
                H.elem[f] = H.elem[c];
                H.elem[c] = min;
                return ture;
            }
            return ture;
        }
        else
        {
            if (H.elem[c] > H.elem[c + 1])
                c++;
            H.elem[f] = H.elem[c];
            H.elem[c] = min;
        }
    }
    return ture;
}
/*********************************/

/*********************************/
/**************ɭ��***************/
/*********************************/

//ɭ�ֽṹ
typedef struct ForestNode
{
    Elemtype Date;
    int root;
} * ForestP;
//ɭ��ͷ���
typedef struct ForestHead
{
    ForestP F;
    int size;
} * ForestNodeP;
//��ɭ���в���Ԫ��e�ĸ����
int FindRoots(ForestHead &p, Elemtype e)
{
    int i = 0;
    for (; i < p.size || p.F[i].Date != e; i++)
        if (i >= p.size)
            return 0;
    for (; p.F[i].root > 0; i = p.F[i].root)
        return i;
}
//ɭ�ֲ�����
bool unionTree(ForestHead &p, Elemtype a, Elemtype b)
{
    int A = FindRoots(p, a);
    int B = FindRoots(p, b);
    if (A == B)
        return false;
    if (p.F[A].root > p.F[B].root)
    {
        p.F[B].root += p.F[A].root;
        p.F[A].root = p.F[B].Date;
    }
    else
    {
        p.F[A].root += p.F[B].root;
        p.F[B].root = p.F[A].Date;
    }
    return ture;
}
/*********************************/

//�������Ա�
void testLinerList()
{
    LinerList l;
    InitLinerlist(l);
    for (int i = 1; i < 10; i++)
        InsertLinerList_direct(l, i, i);
    PrintLinerList(l);
}

/*******************************************************************/
/*************************����ͷ������������************************/
/*******************************************************************/

//������
typedef struct LinkListNode
{
    Elemtype elem;
    LinkListNode *next;
} * LinkListNodeP;
//����ͷ���
typedef struct LinkListHead
{
    int elem; //����Ԫ�ظ���
    LinkListNodeP next;
    LinkListNodeP tail;
} * LinkListHeadP;
//�жϱ��Ƿ����
bool ExistLinkList(LinkListHeadP list)
{
    if (list)
        return ture;
    printf("������\n");
    return false;
}
//�������Ա�
bool DestroyLinkList(LinkListHeadP &list)
{
    if (list->elem)
    {
        LinkListNodeP p = list->next;
        while (!p)
        {
            LinkListNodeP i = p;
            p = p->next;
            free(i);
        }
    }
    free(list);
    list = NULL;
    return ture;
}
//�����Ա�����Ϊ�ձ����ͷ�ԭ����ռ�
bool ClearLinkList(LinkListHeadP list)
{
    if (list->elem)
    {
        LinkListNodeP p = list->next;
        while (!p)
        {
            LinkListNodeP i = p;
            p = p->next;
            free(i);
        }
        list->elem = 0;
        list->next = list->tail = NULL;
    }
    return ture;
}
//��p��ָ�Ľ�����list��ͷ�巨��
bool InsertFirstLinkList(LinkListHeadP head, LinkListNodeP p)
{
    p->next = head->next;
    head->next = p;
    head->elem++;
    return ture;
}
//ɾ��head�ĵ�һ����㲢��q����
bool DeleteFirstLinkList(LinkListHeadP head, LinkListNodeP p)
{
    if (head->elem)
    {
        p = head->next;

        head->next = p->next;
        p->next = NULL;
        head->elem--;
        return ture;
    }
    printf("��Ԫ��\n");
    return false;
}
//��list��i������ֵ����e
bool GetLinkList(LinkListHeadP list, int i, Elemtype &e)
{

    if (i > list->elem)
    {
        printf("�����������\n");
        return false;
    }
    if (i < 1)
    {
        printf("λ�ò���Ϊ������0\n");
        return false;
    }
    LinkListNodeP p = list->next;
    int n = 1;
    while (n < i)
    {
        p = p->next;
        n++;
    }
    e = p->elem;
    return ture;
}
//��ʼ������
bool InitLinkList(LinkListHeadP &newlist)
{
    if (newlist = (LinkListHeadP)malloc(sizeof(LinkListHead)))
    {
        newlist->elem = 0;
        newlist->next = NULL;
        newlist->tail = NULL;
        return ture;
    }
    printf("����ռ�ʧ��\n");
    return false;
}
//����p��ǰ��
LinkListNodeP PriorPosLinkList(LinkListHeadP list, LinkListNodeP p)
{
    LinkListNodeP front = list->next;
    if (front == p)
        return NULL;
    while (front->next)
    {
        if (front->next == p)
            return front;
        front = front->next;
    }
    return NULL;
}
//����p�ĺ��
LinkListNodeP NextPosLinkList(LinkListHeadP list, LinkListNodeP p)
{
    LinkListNodeP next = list->next;
    while (next)
    {
        if (next == p)
        {
            return next->next;
        }
        next = next->next;
    }
    return NULL;
}
//��ǰ�����������Ԫ��
void PrintLinkList(LinkListHeadP list)
{
    if (ExistLinkList(list))
    {
        LinkListNodeP p = list->next;
        for (int i = 1; i <= list->elem; i++)
        {
            printf("%d\t", p->elem);
            if (i % 10 == 0)
                printf("\n");
            p = p->next;
        }
        printf("\n");
    }
    return;
}
//���������ϸ��Ϣ
void PrintLinkList_complete(LinkListHeadP list)
{
    if (ExistLinkList(list))
    {
        printf("%d\t%d\t%d\t%d\n", list->elem, list, list->next, list->tail);
        LinkListNodeP p = list->next;
        for (int i = 1; i <= list->elem; i++)
        {
            printf("%d\t%d\t%d\n", i, p->next, p->elem);
            p = p->next;
        }
        printf("\n");
        return;
    }
    return;
}
//��date��������ĵ�i��λ��
bool InsertLinkList_direct(LinkListHeadP list, int i, Elemtype date)
{

    if (i > list->elem + 1)
    {
        printf("λ�ó����������+1\n");
        return false;
    }
    if (i < 1)
    {
        printf("λ�ò���Ϊ������0\n");
        return false;
    }
    if (i == 1)
    {
        if (LinkListNodeP newnode = (LinkListNodeP)malloc(sizeof(LinkListNode)))
        {
            newnode->next = list->next;
            newnode->elem = date;
            list->next = newnode;
            if (!list->elem)
            {
                list->tail = newnode;
                list->tail->next = NULL;
            }
            list->elem++;
            return ture;
        }
        printf("����ռ�ʧ��\n");
        return false;
    }
    LinkListNodeP p = list->next;
    int n = i;
    i--;
    while (i - 1)
    {
        p = p->next;
        i--;
    }
    if (LinkListNodeP newnode = (LinkListNodeP)malloc(sizeof(LinkListNode)))
    {
        newnode->elem = date;
        newnode->next = p->next;
        p->next = newnode;
        if (n == list->elem + 1)
            list->tail = newnode;
        list->elem++;
        return ture;
    }
    printf("����ռ�ʧ��\n");
    return false;
}
//ɾ�������i��λ�ã���ֵ����e
bool DeleteLinkList_direct(LinkListHeadP list, int i, Elemtype &e)
{
    if (i > list->elem)
    {
        printf("�����������\n");
        return false;
    }
    if (i < 1)
    {
        printf("λ�ò���Ϊ������0\n");
        return false;
    }
    if (i == 1)
    {
        LinkListNodeP d = list->next;
        list->next = list->next->next;
        e = d->elem;
        free(d);
        list->elem--;
        return ture;
    }
    LinkListNodeP p = list->next;
    int n = i;
    i--;
    while (i - 1)
    {
        p = p->next;
        i--;
    }
    LinkListNodeP d = list->next;
    p->next = p->next->next;
    e = d->elem;
    free(p->next);
    list->elem--;
    if (n == list->elem)
        list->tail = p;
    return ture;
}
//��������е�һ��ֵΪe��Ԫ�أ�û�����0
int LocateLinkList(LinkListHeadP list, Elemtype date)
{
    if (!list->elem)
        return 0;
    LinkListNodeP p = list->next;
    for (int i = 1; i <= list->elem; i++)
    {
        if (p->elem == date)
            return i;
        p = p->next;
    }
    return 0;
}
//��p��ָ��һ������ӵ�head�����һ�����֮��
bool AppendLinkList(LinkListHeadP list, LinkListNodeP p)
{
    LinkListNodeP t = p;
    int n = 1;
    while (t->next)
    {
        t = t->next;
        n++;
    }
    list->tail->next = p;
    list->tail = t;
    list->elem += n;
    return ture;
}
//ɾ�����Ա�list��β��㣬����q����
bool RemoveLinkList(LinkListHeadP list, LinkListNodeP &q)
{
    if (list->elem)
    {
        q = list->tail;
        LinkListNodeP p = list->next;
        for (int i = 1; i < list->elem - 1; i++)
        {
            p = p->next;
        }
        list->tail = p;
        p->next = NULL;
        list->elem--;
        return ture;
    }
    printf("��Ԫ��\n");
    return false;
}
//��s����pָ��Ľ��֮ǰ������pָ��s
bool InsBeforeLinkList(LinkListHeadP list, LinkListNodeP &p, LinkListNodeP s)
{
    LinkListNodeP front = list->next;
    if (front == p)
    {
        s->next = p;
        list->next = s;
        p = s;
        list->elem++;
        return ture;
    }
    while (front->next)
    {
        if (front->next == p)
        {
            s->next = p;
            front->next = s;
            p = s;
            list->elem++;
            return ture;
        }
        front = front->next;
    }
    printf("�޴˽��\n");
    return false;
}
//��s����pָ��Ľ��֮�󣬲���pָ��s
bool InsAfterLinkList(LinkListHeadP list, LinkListNodeP &p, LinkListNodeP s)
{
    LinkListNodeP position = list->next;
    while (position)
    {
        if (position == p)
        {
            s->next = position->next;
            position->next = s;
            p = s;
            list->elem++;
            return ture;
        }
        position = position->next;
    }
    printf("�޴˽��\n");
    return false;
}
//�������н��p��Ԫ�ظ�Ϊe
bool SetCurElemLinkList(LinkListNodeP p, Elemtype e)
{
    p->elem = e;
    return ture;
}
//����pָ���Ԫ��
Elemtype GetCurElemLinkList(LinkListNodeP p)
{
    return p->elem;
}
//�����Ƿ�Ϊ��
bool LinkListEmpty(LinkListHeadP list)
{
    if (list)
        if (list->elem)
            return false;
    return ture;
}
//���ر�ĳ���
int LinkListLength(LinkListHeadP list)
{
    if (list)
    {
        int n = 0;
        LinkListNodeP p = list->next;
        while (p)
        {
            n++;
            p = p->next;
        }
        return n;
    }
    return 0;
    //return list->elem;
}
//�����������һ������λ��
LinkListNodeP GetLastLinkList(LinkListHeadP list)
{
    if (list == NULL)
        return NULL;
    LinkListNodeP p = list->next;
    while (p->next)
        p = p->next;
    return p;
    //return list->tail;
}
//��pָ������ĵ�i��λ��
bool LocateposLinkList(LinkListHeadP list, int i, LinkListNodeP &p)
{
    if (i <= 0 || i > list->elem)
        return false;
    LinkListNodeP position = list->next;
    i--;
    while (i)
    {
        position = position->next;
        i--;
    }
    p = position;
    return ture;
}
//����ָ���һ�����㺯����ϵ��Ԫ�ص�ָ��
LinkListNodeP LocateElemLinkList(LinkListHeadP list, Elemtype e,
                                 bool (*compare)(Elemtype, Elemtype))
{
    LinkListNodeP p = list->next;
    while (p)
    {
        if (compare(e, p->elem))
            return p;
        p = p->next;
    }
    return NULL;
}
//��������
void testLinkList()
{
}

/*******************************************************************/
/**********************************ջ*******************************/
/*******************************************************************/

//ջ�ṹ
struct Stack
{
    Elemtype *base;
    Elemtype *top;
    int stacksize;
    int Maxstacksize;
};
//��ʼ��ջ����
#define _initial_stack_size 100
//ջ�ڴ��������
#define _increase_stack 20
//��ʼ��ջ
bool InitStack(Stack &newstack)
{
    if (newstack.base = (Elemtype *)
            malloc((_increase_stack + 1) * sizeof(Elemtype)))
    {
        newstack.top = newstack.base;
        newstack.Maxstacksize = _initial_stack_size;
        newstack.stacksize = 0;
        return ture;
    }
    printf("��ʼ��ʧ��\n");
    return false;
}
//��e����ջ��Ԫ��
bool GettopStack(Stack stack, Elemtype &e)
{
    if (stack.top == stack.base)
        return false;
    e = stack.top[-1];
    return ture;
}
//����Ԫ��e
bool PushStack(Stack &stack, Elemtype e)
{
    if (stack.stacksize == stack.Maxstacksize)
    {
        printf("�ռ���\n");
        //if (!(stack.base =
        //          (Elemtype *)realloc(stack.base,
        //                              (stack.stacksize + _increase_stack) * sizeof(Elemtype))))
        return false;
        //stack.Maxstacksize += _increase_stack;
    }
    *stack.top++ = e;
    stack.stacksize++;
    return ture;
}
//��ӡջs
bool PrintStack(Stack s)
{
    int i = 1;
    while (s.stacksize--)
    {
        visit(*s.base++);
        if (!(i++ % 10))
            printf("\n");
    }
    printf("\n");
    return ture;
}
//ɾ��ջԪ�أ���ֵ��ֵ��e
bool PopStack(Stack &s, Elemtype &e)
{
    if (!s.stacksize)
    {
        printf("ջ��\n");
        return false;
    }
    e = *--s.top;
    s.stacksize--;
    return ture;
}
//��Ϊ��ջ
bool ClearStack(Stack &s)
{
    s.top = s.base;
    s.stacksize = 0;
    return ture;
}
//�ݻ�ջ
bool DestroyStack(Stack &s)
{
    free(s.base);
    s.top = NULL;
    s.base = NULL;
    s.Maxstacksize = 0;
    s.stacksize = 0;
    return ture;
}
//��10������Aת��ΪX����
void conversion(int A, int X)
{
    Stack s;
    InitStack(s);
    if (A >= 0)
    {
        while (A)
        {
            PushStack(s, A % X);
            A /= X;
        }
        int e;
        while (s.stacksize)
        {
            PopStack(s, e);
            printf("%d", e);
        }
        printf("\n");
        return;
    }
    else
    {
        A = 0 - A;
        while (A)
        {
            PushStack(s, A % X);
            A /= X;
        }
        int e;
        printf("-");
        while (s.stacksize)
        {
            PopStack(s, e);
            printf("%d", e);
        }
        printf("\n");
        return;
    }
}
//����ջ
void testStack()
{
    Stack a;
    InitStack(a);
    /*std::cout << a.base << endl;
    std::cout << a.Maxstacksize << endl;
    std::cout << a.top << endl;
    std::cout << a.stacksize << endl;*/
    for (int i = 1; i < 60; i++)
        PushStack(a, i);
    /*std::cout<<a.top[-1]<<endl;
    std::cout<<a.Maxstacksize<<endl;std::cout << a.stacksize << endl;*/
    int s = 0;
    /*GettopStack(a, s);
    std::cout << s << endl;*/
    /*PrintStack(a, visit);
    std::cout << a.base << endl;
    std::cout << a.Maxstacksize << endl;
    std::cout << a.top << endl;
    std::cout << a.stacksize << endl;*/
    /*for (int i = 1; i < 61; i++)
    {
        PopStack(a, s);
        std::cout << s << " ";
        if (!(i % 10))
            std::cout << endl;
    }*/
    /*ClearStack(a);
    std::cout << a.base << endl;
    std::cout << a.Maxstacksize << endl;
    std::cout << a.top << endl;
    std::cout << a.stacksize << endl;*/
    /*DestroyStack(a);std::cout << a.base << endl;
    std::cout << a.Maxstacksize << endl;
    std::cout << a.top << endl;
    std::cout << a.stacksize << endl;*/
    /*conversion(100, 8);
    conversion(111, 10);
    conversion(-5, 2);*/
}

/******************************************************************/
/***************************��ʽ����********************************/
/******************************************************************/

//���н��
typedef struct QueueNode
{
    Elemtype elem;
    QueueNode *next;
} * QueueNodeP;
//���нṹ
struct Queue
{
    QueueNodeP front;
    QueueNodeP rear;
    int size;
};
//��ʼ������
bool InitQueue(Queue &q)
{
    if (q.front = (QueueNodeP)malloc(sizeof(QueueNode)))
    {
        q.rear = q.front;
        q.size = 0;
        q.front->next = NULL;
        return ture;
    }
    return false;
}
//�������
bool DestoryQueue(Queue &q)
{
    if (q.size)
    {
        printf("���в���\n");
        return false;
    }
    free(q.front);
    q.front = q.rear = NULL;
    return ture;
}
//����Ϊ��
bool QueueEmpty(Queue q)
{
    if (q.size)
        return false;
    return ture;
}
//��q���գ���e���ض�ͷ
bool GetHeadQueue(Queue q, Elemtype &e)
{
    if (QueueEmpty(q))
        return false;
    e = q.front->elem;
    return ture;
}
//e�������q
bool EnQueue(Queue &q, Elemtype e)
{
    QueueNodeP n;
    if (n = (QueueNodeP)malloc(sizeof(QueueNode)))
    {

        if (q.size)
        {
            n->elem = e;
            n->next = NULL;
            q.rear->next = n;
            q.rear = n;
            q.size++;
            return ture;
        }
        if (!q.front)
            InitQueue(q);
        q.front->elem = e;
        q.size++;
        return ture;
    }
    printf("����ռ�ʧ��\n");
    return false;
}
//ɾ������ͷԪ��
bool DeQueue(Queue &q)
{
    if (!QueueEmpty(q))
    {
        QueueNodeP s = q.front;
        q.front = q.front->next;
        free(s);
        q.size--;
        return ture;
    }
    printf("���п�\n");
    return false;
}
//��ն���
void ClearQueue(Queue &q)
{
    if (QueueEmpty(q))
        return;
    while (q.size != 1)
    {
        DeQueue(q);
    }
    q.front->elem = 0;
    q.size--;
    return;
}
//��ӡ����
void PrintQueue(Queue q)
{
    QueueNodeP p = q.front;
    int i = 1;
    while (p)
    {
        visit(p->elem);
        if (!(i++ % 10))
            printf("\n");
        p = p->next;
    }
    printf("\n");
    return;
}
//���Զ���
void testQueue()
{
}

/***************************************************************/
/******************��ʽ����������********************************/
/***************************************************************/

//���ڵ�
typedef struct TreeNode
{
    Elemtype elem;
    int hight; //AVL��
    TreeNode *leftfater;
    TreeNode *rightchild;
} * TreeP, *TreeHeadP;
//����һ���Ķ��������,ֵΪe
bool CreateTree(TreeP &newtree, Elemtype e)
{
    if (newtree = (TreeP)malloc(sizeof(TreeNode)))
    {
        newtree->elem = e;
        newtree->leftfater = newtree->rightchild = NULL;
        newtree->hight = 1;
        return ture;
    }
    return false;
}
//����e
bool InsertTree(TreeHeadP &tree, Elemtype e)
{
    if (!tree)
        CreateTree(tree, e);
    if (tree->elem > e)
    {
        if (!tree->leftfater)
        {
            TreeHeadP newnode;
            if (!CreateTree(newnode, e))
                return false;
            tree->leftfater = newnode;
            return ture;
        }
        InsertTree(tree->leftfater, e);
    }
    else if (tree->elem < e)
    {
        if (!tree->rightchild)
        {
            TreeHeadP newnode;
            if (!CreateTree(newnode, e))
                return false;
            tree->rightchild = newnode;
            return ture;
        }
        InsertTree(tree->rightchild, e);
    }
    else if (tree->elem == e)
    {
        return false;
    }
    return ture;
}
//�������������
bool MidOrderTree(TreeHeadP tree)
{
    if (tree)
    {
        if (MidOrderTree(tree->leftfater))
            if (visit(tree->elem))
                if (MidOrderTree(tree->rightchild))
                    return ture;
        printf("�ڵ���Ϣ����\n");
        return false;
    }
    return ture;
}
//�������������
bool PreOrderTree(TreeHeadP tree)
{
    if (tree)
    {
        if (visit(tree->elem))
            if (PreOrderTree(tree->leftfater))
                if (PreOrderTree(tree->rightchild))
                    return ture;
        printf("�ڵ���Ϣ����\n");
        return false;
    }
    return ture;
}
//�������������
bool PostOrderTree(TreeHeadP tree)
{
    if (tree)
    {
        if (PostOrderTree(tree->leftfater))
            if (PostOrderTree(tree->rightchild))
                if (visit(tree->elem))
                    return ture;
        printf("�ڵ���Ϣ����\n");
        return false;
    }
    return ture;
}
//�������e,����e�ĵ�ַ
TreeP SearchTreeNode(TreeHeadP tree, Elemtype e)
{
    while (tree)
    {
        if (tree->elem == e)
            return tree;
        if (tree->elem > e)
            tree = tree->leftfater;
        else
            tree = tree->rightchild;
    }
    return NULL;
}
//�ҳ���������С�Ľ��
TreeP FindTreeMin(TreeP subtree)
{
    while (subtree->leftfater)
    {
        subtree = subtree->leftfater;
    }
    return subtree;
}
//�ҳ�����С���ĸ����
TreeP FindTreeMInFater(TreeP tree)
{
    while (tree->leftfater->leftfater)
    {
        tree = tree->leftfater;
    }
    return tree;
}
//ɾ�����e
bool DeleteTree(TreeHeadP &tree, Elemtype e)
{
    TreeP t = SearchTreeNode(tree, e);
    if (t)
    {
        if (t->leftfater && t->rightchild)
        {
            TreeP min = FindTreeMin(t->rightchild);
            t->elem = min->elem;
            if ((min->rightchild))
            {
                min->elem = min->rightchild->elem;
                min->leftfater = min->rightchild->leftfater;
                min->rightchild = min->rightchild->rightchild;
                free(min->rightchild);
                return ture;
            }
            t->rightchild = NULL;
            free(min);
        }
        else if (t->rightchild)
        {
            TreeP position = t->rightchild;
            t->rightchild = position->rightchild;
            t->leftfater = position->leftfater;
            t->elem = position->elem;
            free(position);
        }
        else
        {
            TreeP position = t->leftfater;
            t->rightchild = position->rightchild;
            t->leftfater = position->leftfater;
            t->elem = position->elem;
            free(position);
        }
        return ture;
    }
    return false;
}

/*************ջ*****************/
struct TreeStack
{
    TreeP *base;
    TreeP *top;
    int stacksize;
    int Maxstacksize;
};
#define _initial_stack_size 100
bool InitTreeStack(TreeStack &newstack)
{
    if (newstack.base = (TreeP *)
            malloc((_increase_stack + 1) * sizeof(TreeP *)))
    {
        newstack.top = newstack.base;
        newstack.Maxstacksize = _initial_stack_size;
        newstack.stacksize = 0;
        return ture;
    }
    printf("��ʼ��ʧ��\n");
    return false;
}
bool PushTreeStack(TreeStack &stack, TreeP e)
{
    if (stack.stacksize == stack.Maxstacksize)
    {
        printf("�ռ���\n");
        //if (!(stack.base =
        //          (Elemtype *)realloc(stack.base,
        //                              (stack.stacksize + _increase_stack) * sizeof(Elemtype))))
        return false;
        //stack.Maxstacksize += _increase_stack;
    }
    *stack.top++ = e;
    stack.stacksize++;
    return ture;
}
bool DestroyTreeStack(TreeStack &s)
{
    free(s.base);
    s.top = NULL;
    s.base = NULL;
    s.Maxstacksize = 0;
    s.stacksize = 0;
    return ture;
}
TreeP PopTreeStack(TreeStack &s)
{
    if (!s.stacksize)
    {
        printf("ջ��\n");
        return NULL;
    }
    --s.top;
    s.stacksize--;
    return *s.top;
}
//��ջ����������
bool InOrderTree(TreeHeadP tree)
{
    TreeStack s;
    InitTreeStack(s);
    TreeP position = tree;
    while (position || s.stacksize)
    {
        if (position)
        {
            PushTreeStack(s, position);
            position = position->leftfater;
        }
        else
        {
            position = PopTreeStack(s);
            visit(position->elem);
            position = position->rightchild;
        }
    }
    DestroyTreeStack(s);
    return ture;
}
/********************************/

/*************����***************/
typedef struct TreeQueueNode
{
    TreeP elem;
    TreeQueueNode *next;
} * TreeQueueNodeP;
struct TreeQueue
{
    TreeQueueNodeP front;
    TreeQueueNodeP rear;
    int size;
};
bool InitTreeQueue(TreeQueue &q)
{
    if (q.front = (TreeQueueNodeP)malloc(sizeof(TreeQueueNode)))
    {
        q.rear = q.front;
        q.size = 0;
        q.front->next = NULL;
        return ture;
    }
    return false;
}
bool DestoryTreeQueue(TreeQueue &q)
{
    if (q.size)
    {
        printf("���в���\n");
        return false;
    }
    free(q.front);
    q.front = q.rear = NULL;
    return ture;
}
bool TreeQueueEmpty(TreeQueue q)
{
    if (q.size)
        return false;
    return ture;
}
bool EnTreeQueue(TreeQueue &q, TreeP e)
{
    if (q.size)
    {
        TreeQueueNodeP n = NULL;
        if (!(n = (TreeQueueNodeP)malloc(sizeof(TreeQueueNode))))
        {
            printf("����ռ�ʧ��\n");
            return false;
        }
        n->elem = e;
        n->next = NULL;
        q.rear->next = n;
        q.rear = n;
        q.size++;
        return ture;
    }
    else
    {
        if (!q.front)
            InitTreeQueue(q);
        q.front->elem = e;
        q.size++;
        return ture;
    }
}
bool DeTreeQueue(TreeQueue &q, TreeP &e)
{
    if (!TreeQueueEmpty(q))
    {
        TreeQueueNodeP s = q.front;
        e = q.front->elem;
        q.front = q.front->next;
        free(s);
        q.size--;
        return ture;
    }
    printf("���п�\n");
    return false;
}
//�ö��б���������
bool QueueTree(TreeHeadP tree)
{
    if (!tree)
        return false;
    TreeQueue q;
    TreeP t;
    InitTreeQueue(q);
    EnTreeQueue(q, tree);
    while (q.size)
    {
        DeTreeQueue(q, t);
        tree = t;
        if (!visit(t->elem))
        {
            printf("���ݴ���\n");
            return false;
        }
        if (tree->leftfater)
            EnTreeQueue(q, tree->leftfater);
        if (tree->rightchild)
            EnTreeQueue(q, tree->rightchild);
    }
    DestoryTreeQueue(q);
    return ture;
}
/********************************/

/********************************/
/************AVL��***************/
/********************************/

//���ؽ��ĸ߶�
int GetHight(TreeP tree)
{
    if (tree)
        return tree->hight;
    return 0;
}
//����ת
TreeP TreeLeft(TreeP tree)
{
    TreeP A = tree->leftfater;
    tree->leftfater = A->rightchild;
    A->rightchild = tree;
    tree->hight = Max(GetHight(tree->leftfater), GetHight(tree->rightchild)) + 1;
    A->hight = Max(GetHight(A->leftfater), A->hight) + 1;
    return A;
}
//����ת
TreeP TreeRight(TreeP tree)
{
    TreeP A = tree->rightchild;
    tree->rightchild = A->leftfater;
    A->leftfater = tree;
    tree->hight = Max(GetHight(tree->leftfater), GetHight(tree->rightchild)) + 1;
    A->hight = Max(GetHight(A->rightchild), A->hight) + 1;
    return A;
}
//������ת
TreeP TreeLeft_Right(TreeP tree)
{
    tree->leftfater = TreeRight(tree->leftfater);
    return TreeLeft(tree);
}
//������ת
TreeP TreeRight_Left(TreeP tree)
{
    tree->rightchild = TreeLeft(tree->rightchild);
    return TreeRight(tree);
}
//����e��ƽ�������
TreeP InsertAVLTree(TreeHeadP &tree, Elemtype e)
{
    if (!tree)
    {
        if (!CreateTree(tree, e))
            return NULL;
    }
    else if (tree->elem > e)
    {
        tree->leftfater = InsertAVLTree(tree->leftfater, e);
        if (GetHight(tree->leftfater) - GetHight(tree->rightchild) == 2)
            if (e < tree->leftfater->elem)
                tree = TreeLeft(tree);
            else
                tree = TreeLeft_Right(tree);
    }
    else if (tree->elem < e)
    {
        if (tree->rightchild = InsertAVLTree(tree->rightchild, e))
            if (GetHight(tree->rightchild) - GetHight(tree->leftfater) == 2)
                if (e > tree->rightchild->elem)
                    tree = TreeRight(tree);
                else
                    tree = TreeRight_Left(tree);
    }
    tree->hight = Max(GetHight(tree->leftfater), GetHight(tree->rightchild)) + 1;
    return tree;
}
/********************************/

/********************************/
/*********��������***δʵ��*******/
/********************************/

//��С�������
struct MinHeapTree
{
    TreeP *elem;
    int length;
    int listsize;
};
//��ʼ����С����
bool InitMinTreeHeap(MinHeapTree &H, int s)
{
    H.elem = (TreeP *)malloc(s * sizeof(TreeP));
    if (!H.elem)
    {
        printf("����ռ�ʧ��\n");
        return false;
    }

    for (int i = 0; i < s; i++)
    {
        if (!(H.elem[i] = (TreeP)malloc(sizeof(TreeNode))))
            return false;
        H.elem[i]->leftfater = H.elem[i]->rightchild = NULL;
    }
    H.elem[0]->elem = INT_MIN;
    H.length = 1;
    H.listsize = s;
    return true;
}
//���Ƿ���
bool TreeHeapIsFull(MinHeapTree H)
{
    if (H.length == H.listsize)
        return ture;
    return false;
}
//����e��MaxHeap
bool InsertMinTreeHeap(MinHeapTree &H, TreeP t)
{
    if (TreeHeapIsFull(H))
        return false;
    int i = H.length++;
    for (; t->elem < H.elem[i / 2]->elem; i = i / 2)
    {
        H.elem[i]->elem = H.elem[i / 2]->elem;
        H.elem[i]->rightchild = H.elem[i / 2]->rightchild;
        H.elem[i]->leftfater = H.elem[i / 2]->leftfater;
    }
    H.elem[i]->elem = t->elem;
    H.elem[i]->rightchild = t->rightchild;
    H.elem[i]->leftfater = t->leftfater;
    return ture;
}
//�ѿ�
bool TreeHeapIsEmpty(MinHeapTree H)
{
    return (H.listsize == 1);
}
//ɾ����Сֵ������ɾ����Ԫ��
TreeP DeleteMinTreeHeap(MinHeapTree &H)
{
    if (TreeHeapIsEmpty(H))
        return 0;
    int a = H.elem[1]->elem;
    TreeP e = H.elem[1];
    int max = H.elem[--H.length]->elem;
    int f, c;
    for (f = 1; f * 2 <= H.length; f = c)
    {
        c = f * 2;
        if (c == H.length)
        {
            if (H.elem[c]->elem < max)
            {
                H.elem[f]->elem = H.elem[c]->elem;
                H.elem[f]->rightchild = H.elem[c]->rightchild;
                H.elem[f]->leftfater = H.elem[c]->leftfater;
                H.elem[c]->elem = max;
            }
            H.elem[H.length]->elem = a;
            return H.elem[H.length];
        }
        else
        {
            if (H.elem[c]->elem > H.elem[c + 1]->elem)
                c++;
            H.elem[f]->elem = H.elem[c]->elem;
            H.elem[f]->rightchild = H.elem[c]->rightchild;
            H.elem[f]->leftfater = H.elem[c]->leftfater;
            H.elem[c]->elem = max;
        }
    }
    H.elem[H.length]->elem = a;
    return H.elem[H.length];
}
//����ת��Ϊhuffman��
TreeHeadP CreateHuffTree(MinHeapTree &h)
{
    TreeP T;
    if (TreeHeapIsEmpty(h))
        return NULL;

    while (h.length > 2)
    {
        if (!(T = (TreeP)malloc(sizeof(TreeNode))))
            return NULL;
        TreeP e;
        if (!(e = (TreeP)malloc(sizeof(TreeNode))))
            return NULL;
        T->leftfater = DeleteMinTreeHeap(h);
        T->rightchild = DeleteMinTreeHeap(h);
        e->elem = T->rightchild->elem;
        e->leftfater = T->rightchild->leftfater;
        e->rightchild = T->rightchild->rightchild;
        T->rightchild = e;
        T->elem = T->leftfater->elem + T->rightchild->elem;
        InsertMinTreeHeap(h, T);
    }

    return T;
}
/********************************/

//������
void testTree()
{
}

/***************************************************************/
/****************************ͼ*********************************/
/***************************************************************/

int main()
{

    testLinerList();
    //testLinkList();
    //testStack();
    //testQueue();
    //testTree();
    system("pause");
    return 0;
}