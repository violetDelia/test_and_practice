#include <iostream>
#include <limits.h>
#include <malloc.h>
#include <stdio.h>

using namespace std;

#define ture true
//基本元素类型
#define Elemtype int

/******************************************************************/
/****************************通用函数*******************************/
/******************************************************************/

//A，B是否相等
bool compare_equal(Elemtype A, Elemtype B)
{
    if (A == B)
        return ture;
    return false;
}
//访问输出元素e
bool visit(Elemtype e)
{
    printf("%d\t", e);
    return ture;
}
//返回最大值
int Max(int a, int b)
{
    return a > b ? a : b;
}
/*****************************************************************/
/****************************顺序表********************************/
/*****************************************************************/

//线性表结构
typedef struct LinerList
{
    Elemtype *elem;
    int length;
    int listsize;
} MaxHeap, Heap, MinHeap;
//初始化线性表长度
#define _initial_list_size 100
//线性表内存分配增量
#define _increase_list 20
//初始化线性表
bool InitLinerlist(LinerList &newlist)
{
    newlist.elem = (Elemtype *)malloc(_initial_list_size * sizeof(Elemtype));
    if (!newlist.elem)
    {
        printf("分配空间失败\n");
        return false;
    }
    newlist.length = 0;
    newlist.listsize = _initial_list_size;
    return true;
}
//清空线性表占用的动态空间
void DestroyLinerList(LinerList &list)
{
    free(list.elem);
    list.elem = NULL;
    list.length = 0;
    list.listsize = 0;
    return;
}
//表空或不存在
bool EmptyLinerList(LinerList list)
{
    if (!list.elem)
    {
        printf("表不存在\n");
        return ture;
    }
    if (!list.length)
    {
        printf("表空\n");
        return ture;
    }
    return false;
}
//表长重置为0
bool ClearLinerList(LinerList list)
{
    if (EmptyLinerList(list))
        return false;
    list.length = 0;
    return ture;
}
// 将list第i个元素赋值给v
bool GetLinerList(LinerList list, int n, Elemtype &v)
{
    if (EmptyLinerList(list))
        return false;
    if (n < 1 || n > list.length)
    {
        printf("无此位置\n");
        return false;
    }
    v = list.elem[n - 1];
    return ture;
}
//寻找list中和date满足compare（）的第一个元素，返回这个元素的位置
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
    // printf("未找到合适的元素\n");
    return 0;
}
//第一个date的前驱
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
//第一个date的后继
bool NextLinerList(LinerList list, Elemtype date, Elemtype &pre_date)
{
    int p = LocateLinerList(list, date, compare_equal);
    if (p && p < list.length)
    {
        pre_date = list.elem[p];
        return ture;
    }
    printf("数据不存在\n");
    return false;
}
//将date插入第n个位置
bool InsertLinerList_direct(LinerList &list, int n, Elemtype date)
{
    if (!list.elem)
    {
        printf("表不存在\n");
        return false;
    }
    if (n < 1 || n > list.length + 1)
    {
        printf("无此位置\n");
        return false;
    }
    if (list.length == list.listsize)
    {
        printf("表已满!\n");
        //Elemtype *newbase;
        //newbase = (Elemtype *)realloc(list.elem, (list.listsize + _increase_list) * sizeof(Elemtype));
        //if (!newbase)
        //{
        //    printf("扩充空间失败\n");
        return false;
        // }
        //list.elem = newbase;
        //list.listsize += _increase_list;
        //printf("扩充%d个空间\n", _increase_list);
    }
    for (int i = list.length; i >= n; i--)
    {
        list.elem[i] = list.elem[i - 1];
    }
    list.elem[n - 1] = date;
    list.length++;
    return ture;
}
//删除list第n个元素，并将值赋给date
bool DeleteLinerList_direct(LinerList list, int n, Elemtype &date)
{
    if (EmptyLinerList(list))
        return false;
    if (n < 1 || n > list.length)
    {
        printf("无此位置\n");
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
//打印线性表的元素
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
//在newlist依次写入list1，list2
bool MergeLinerList(LinerList list1, LinerList list2, LinerList &newlist)
{
    if (!list1.elem && !list2.elem && !newlist.elem)
    {
        printf("表不存在\n");
        return false;
    }
    if (newlist.length)
    {
        printf("新表中有数据\n");
        return false;
    }
    newlist.elem = (Elemtype *)malloc((list2.length + list1.length + _initial_list_size) * sizeof(Elemtype));
    if (!newlist.elem)
    {
        printf("分配空间失败\n");
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
//将listA中list没有的的数据写入list之后
bool unionLinerLisy(LinerList &list, LinerList listA)
{
    if (listA.length + list.length > list.listsize)
    {
        printf("表空间不足\n");
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
/**************堆*****************/
/*********************************/

//创建数组空间为s的最大堆
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
//堆是否满
bool HeapIsFull(Heap H)
{
    if (H.length == H.listsize)
        return ture;
    return false;
}
//插入e到MaxHeap
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
//堆空
bool HeapIsEmpty(Heap H)
{
    return (H.listsize == 1);
}
//删除最大堆的最大值，赋值给e
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
//创建数组空间为s的最小堆
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
//插入e到MinHeap
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
//删除最小堆的最小值，赋值给e
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
/**************森林***************/
/*********************************/

//森林结构
typedef struct ForestNode
{
    Elemtype Date;
    int root;
} * ForestP;
//森林头结点
typedef struct ForestHead
{
    ForestP F;
    int size;
} * ForestNodeP;
//在森林中查找元素e的父结点
int FindRoots(ForestHead &p, Elemtype e)
{
    int i = 0;
    for (; i < p.size || p.F[i].Date != e; i++)
        if (i >= p.size)
            return 0;
    for (; p.F[i].root > 0; i = p.F[i].root)
        return i;
}
//森林并运算
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

//测试线性表
void testLinerList()
{
    LinerList l;
    InitLinerlist(l);
    for (int i = 1; i < 10; i++)
        InsertLinerList_direct(l, i, i);
    PrintLinerList(l);
}

/*******************************************************************/
/*************************带有头结点的线性链表************************/
/*******************************************************************/

//链表结点
typedef struct LinkListNode
{
    Elemtype elem;
    LinkListNode *next;
} * LinkListNodeP;
//链表头结点
typedef struct LinkListHead
{
    int elem; //链表元素个数
    LinkListNodeP next;
    LinkListNodeP tail;
} * LinkListHeadP;
//判断表是否存在
bool ExistLinkList(LinkListHeadP list)
{
    if (list)
        return ture;
    printf("表不存在\n");
    return false;
}
//销毁线性表
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
//将线性表重置为空表，并释放原链表空间
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
//将p所指的结点插入list（头插法）
bool InsertFirstLinkList(LinkListHeadP head, LinkListNodeP p)
{
    p->next = head->next;
    head->next = p;
    head->elem++;
    return ture;
}
//删除head的第一个结点并以q返回
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
    printf("无元素\n");
    return false;
}
//将list第i个结点的值赋给e
bool GetLinkList(LinkListHeadP list, int i, Elemtype &e)
{

    if (i > list->elem)
    {
        printf("超出链表个数\n");
        return false;
    }
    if (i < 1)
    {
        printf("位置不能为负数或0\n");
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
//初始化链表
bool InitLinkList(LinkListHeadP &newlist)
{
    if (newlist = (LinkListHeadP)malloc(sizeof(LinkListHead)))
    {
        newlist->elem = 0;
        newlist->next = NULL;
        newlist->tail = NULL;
        return ture;
    }
    printf("分配空间失败\n");
    return false;
}
//返回p的前驱
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
//返回p的后继
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
//从前到后输出链表元素
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
//输出链表详细信息
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
//将date插入链表的第i个位置
bool InsertLinkList_direct(LinkListHeadP list, int i, Elemtype date)
{

    if (i > list->elem + 1)
    {
        printf("位置超出链表个数+1\n");
        return false;
    }
    if (i < 1)
    {
        printf("位置不能为负数或0\n");
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
        printf("分配空间失败\n");
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
    printf("分配空间失败\n");
    return false;
}
//删除链表第i个位置，将值赋给e
bool DeleteLinkList_direct(LinkListHeadP list, int i, Elemtype &e)
{
    if (i > list->elem)
    {
        printf("超出链表个数\n");
        return false;
    }
    if (i < 1)
    {
        printf("位置不能为负数或0\n");
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
//输出链表中第一个值为e的元素，没有输出0
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
//将p所指的一串链表接到head的最后一个结点之后
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
//删除线性表list的尾结点，并以q返回
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
    printf("无元素\n");
    return false;
}
//将s插入p指向的结点之前，并将p指向s
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
    printf("无此结点\n");
    return false;
}
//将s插入p指向的结点之后，并将p指向s
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
    printf("无此结点\n");
    return false;
}
//将链表中结点p的元素改为e
bool SetCurElemLinkList(LinkListNodeP p, Elemtype e)
{
    p->elem = e;
    return ture;
}
//返回p指向的元素
Elemtype GetCurElemLinkList(LinkListNodeP p)
{
    return p->elem;
}
//链表是否为空
bool LinkListEmpty(LinkListHeadP list)
{
    if (list)
        if (list->elem)
            return false;
    return ture;
}
//返回表的长度
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
//返回链表最后一个结点的位置
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
//将p指向链表的第i个位置
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
//返回指向第一个满足函数关系的元素的指针
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
//测试链表
void testLinkList()
{
}

/*******************************************************************/
/**********************************栈*******************************/
/*******************************************************************/

//栈结构
struct Stack
{
    Elemtype *base;
    Elemtype *top;
    int stacksize;
    int Maxstacksize;
};
//初始化栈长度
#define _initial_stack_size 100
//栈内存分配增量
#define _increase_stack 20
//初始化栈
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
    printf("初始化失败\n");
    return false;
}
//用e返回栈顶元素
bool GettopStack(Stack stack, Elemtype &e)
{
    if (stack.top == stack.base)
        return false;
    e = stack.top[-1];
    return ture;
}
//插入元素e
bool PushStack(Stack &stack, Elemtype e)
{
    if (stack.stacksize == stack.Maxstacksize)
    {
        printf("空间满\n");
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
//打印栈s
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
//删除栈元素，将值赋值到e
bool PopStack(Stack &s, Elemtype &e)
{
    if (!s.stacksize)
    {
        printf("栈空\n");
        return false;
    }
    e = *--s.top;
    s.stacksize--;
    return ture;
}
//置为空栈
bool ClearStack(Stack &s)
{
    s.top = s.base;
    s.stacksize = 0;
    return ture;
}
//摧毁栈
bool DestroyStack(Stack &s)
{
    free(s.base);
    s.top = NULL;
    s.base = NULL;
    s.Maxstacksize = 0;
    s.stacksize = 0;
    return ture;
}
//将10进制数A转换为X进制
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
//测试栈
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
/***************************链式队列********************************/
/******************************************************************/

//队列结点
typedef struct QueueNode
{
    Elemtype elem;
    QueueNode *next;
} * QueueNodeP;
//队列结构
struct Queue
{
    QueueNodeP front;
    QueueNodeP rear;
    int size;
};
//初始化队列
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
//毁灭队列
bool DestoryQueue(Queue &q)
{
    if (q.size)
    {
        printf("队列不空\n");
        return false;
    }
    free(q.front);
    q.front = q.rear = NULL;
    return ture;
}
//队列为空
bool QueueEmpty(Queue q)
{
    if (q.size)
        return false;
    return ture;
}
//若q不空，用e返回队头
bool GetHeadQueue(Queue q, Elemtype &e)
{
    if (QueueEmpty(q))
        return false;
    e = q.front->elem;
    return ture;
}
//e插入队列q
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
    printf("分配空间失败\n");
    return false;
}
//删除队列头元素
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
    printf("队列空\n");
    return false;
}
//清空队列
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
//打印队列
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
//测试队列
void testQueue()
{
}

/***************************************************************/
/******************链式搜索二叉树********************************/
/***************************************************************/

//树节点
typedef struct TreeNode
{
    Elemtype elem;
    int hight; //AVL树
    TreeNode *leftfater;
    TreeNode *rightchild;
} * TreeP, *TreeHeadP;
//构造一个的二叉树结点,值为e
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
//插入e
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
//中序遍历二叉树
bool MidOrderTree(TreeHeadP tree)
{
    if (tree)
    {
        if (MidOrderTree(tree->leftfater))
            if (visit(tree->elem))
                if (MidOrderTree(tree->rightchild))
                    return ture;
        printf("节点信息出错\n");
        return false;
    }
    return ture;
}
//先序遍历二叉树
bool PreOrderTree(TreeHeadP tree)
{
    if (tree)
    {
        if (visit(tree->elem))
            if (PreOrderTree(tree->leftfater))
                if (PreOrderTree(tree->rightchild))
                    return ture;
        printf("节点信息出错\n");
        return false;
    }
    return ture;
}
//后序遍历二叉树
bool PostOrderTree(TreeHeadP tree)
{
    if (tree)
    {
        if (PostOrderTree(tree->leftfater))
            if (PostOrderTree(tree->rightchild))
                if (visit(tree->elem))
                    return ture;
        printf("节点信息出错\n");
        return false;
    }
    return ture;
}
//搜索结点e,返回e的地址
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
//找出子树中最小的结点
TreeP FindTreeMin(TreeP subtree)
{
    while (subtree->leftfater)
    {
        subtree = subtree->leftfater;
    }
    return subtree;
}
//找出树最小结点的父结点
TreeP FindTreeMInFater(TreeP tree)
{
    while (tree->leftfater->leftfater)
    {
        tree = tree->leftfater;
    }
    return tree;
}
//删除结点e
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

/*************栈*****************/
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
    printf("初始化失败\n");
    return false;
}
bool PushTreeStack(TreeStack &stack, TreeP e)
{
    if (stack.stacksize == stack.Maxstacksize)
    {
        printf("空间满\n");
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
        printf("栈空\n");
        return NULL;
    }
    --s.top;
    s.stacksize--;
    return *s.top;
}
//用栈遍历二叉树
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

/*************队列***************/
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
        printf("队列不空\n");
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
            printf("分配空间失败\n");
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
    printf("队列空\n");
    return false;
}
//用队列遍历二叉树
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
            printf("数据错误\n");
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
/************AVL树***************/
/********************************/

//返回结点的高度
int GetHight(TreeP tree)
{
    if (tree)
        return tree->hight;
    return 0;
}
//左旋转
TreeP TreeLeft(TreeP tree)
{
    TreeP A = tree->leftfater;
    tree->leftfater = A->rightchild;
    A->rightchild = tree;
    tree->hight = Max(GetHight(tree->leftfater), GetHight(tree->rightchild)) + 1;
    A->hight = Max(GetHight(A->leftfater), A->hight) + 1;
    return A;
}
//右旋转
TreeP TreeRight(TreeP tree)
{
    TreeP A = tree->rightchild;
    tree->rightchild = A->leftfater;
    A->leftfater = tree;
    tree->hight = Max(GetHight(tree->leftfater), GetHight(tree->rightchild)) + 1;
    A->hight = Max(GetHight(A->rightchild), A->hight) + 1;
    return A;
}
//左右旋转
TreeP TreeLeft_Right(TreeP tree)
{
    tree->leftfater = TreeRight(tree->leftfater);
    return TreeLeft(tree);
}
//右左旋转
TreeP TreeRight_Left(TreeP tree)
{
    tree->rightchild = TreeLeft(tree->rightchild);
    return TreeRight(tree);
}
//插入e到平衡二叉树
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
/*********哈夫曼树***未实现*******/
/********************************/

//最小堆树结点
struct MinHeapTree
{
    TreeP *elem;
    int length;
    int listsize;
};
//初始化最小树堆
bool InitMinTreeHeap(MinHeapTree &H, int s)
{
    H.elem = (TreeP *)malloc(s * sizeof(TreeP));
    if (!H.elem)
    {
        printf("分配空间失败\n");
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
//堆是否满
bool TreeHeapIsFull(MinHeapTree H)
{
    if (H.length == H.listsize)
        return ture;
    return false;
}
//插入e到MaxHeap
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
//堆空
bool TreeHeapIsEmpty(MinHeapTree H)
{
    return (H.listsize == 1);
}
//删除最小值，返回删除的元素
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
//将堆转化为huffman树
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

//测试树
void testTree()
{
}

/***************************************************************/
/****************************图*********************************/
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