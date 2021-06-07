#include <malloc.h>
#include <stdio.h>

#include <iostream>
using namespace std;

#define Elemtype char

typedef struct LinkQueueNode
{
    Elemtype elem;
    LinkQueueNode *next;
} Node;
typedef struct HeadLinkQueue
{
    LinkQueueNode *front;
    LinkQueueNode *rear;
} Head;

void CreatLinkQueue(HeadLinkQueue &newqueue)
{
    newqueue.front = newqueue.rear = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    if (newqueue.front == NULL)
    {
        printf("创建失败\n");
        return;
    }
    newqueue.front->next = NULL;
    printf("创建成功\n");
    return;
}

void PrintLinkQueue(HeadLinkQueue &queue)
{
    int i = 0;
    LinkQueueNode *position = queue.front->next;
    while (position)
    {
        printf("%c", position->elem);
        i++;
        position = position->next;
    }
    if (i)
    {
        printf("\t共有%d个数据\n", i);
        return;
    }
    printf("队列无元素\n");
    return;
}

void InsertQuere(HeadLinkQueue &queue, Elemtype Date)
{
    LinkQueueNode *Node = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));

    if (Node)                     
    {
        Node->next = NULL;
        Node->elem = Date;
        queue.rear->next = Node;
        queue.rear = Node;
        printf("插入成功\n");
        return;
    }
    printf("分配空间错误，插入失败\n");
    return;
}

int main()
{
    HeadLinkQueue queue;
    CreatLinkQueue(queue);
    PrintLinkQueue(queue);
    InsertQuere(queue, 's');
    InsertQuere(queue, 'l');
    InsertQuere(queue, 'a');
    InsertQuere(queue, 'v');
    InsertQuere(queue, 'e');
    PrintLinkQueue(queue);
    std::system("pause");
    return 0;
}
