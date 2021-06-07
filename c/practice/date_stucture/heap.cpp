#include <iostream>
#include <limits.h>
#include <malloc.h>
#include <stdio.h>
using namespace std;

#define ture true

#define Elemtype char //????
#define Elemtype_Max CHAR_MAX
#define Elemtype_Min CHAR_MIN
#define initial_heap_size 100

#define increase_heap_size 10

struct Heap
{
    Elemtype *elem;
    int size;
    int maxsize;
};

bool CreatMaxHeap(Heap &newheap)
{
    newheap.elem = (Elemtype *)malloc(initial_heap_size * sizeof(Elemtype));
    if (newheap.elem && &newheap.size && &newheap.maxsize)
    {
        newheap.maxsize = initial_heap_size - 1;
        newheap.size = 0;
        newheap.elem[0] = Elemtype_Max;
        newheap.elem[1] = Elemtype_Min;
        printf("????\n");
        return true;
    }
    printf("??????\n");
    return false;
}

bool interchange(Elemtype A, Elemtype B)
{
    int date;
    date = A;
    A = B;
    B = date;
    return true;
}

bool InsertMaxHeap(Heap heap, Elemtype Date)
{
    if (heap.size == heap.maxsize)
    {
        printf("??\n");
        heap.elem = (Elemtype *)realloc(heap.elem, (heap.maxsize + 1 + increase_heap_size) * sizeof(Elemtype));
        if (heap.elem == NULL)
        {
            printf("??????,??????\n");
            return false;
        }
        printf("??%d?????\n", increase_heap_size);
        heap.maxsize += increase_heap_size;
    }
    int position = ++heap.size;
    for (; heap.elem[position / 2] < Date; position /= 2)
    {
        heap.elem[position] = heap.elem[position / 2];
        heap.elem[position] = Date;
    }
    return true;
}

bool PrintHeap(Heap heap)
{
    for (int i = 1; i > heap.size; i++)
    {
        printf("%d ", heap.elem[i]);
    }
    return ture;
}

void testHeap()
{
    Heap maxheap;
    CreatMaxHeap(maxheap);
    InsertMaxHeap(maxheap, 'a');
    InsertMaxHeap(maxheap, 'd');
    InsertMaxHeap(maxheap, 17);
    InsertMaxHeap(maxheap, 6);
    InsertMaxHeap(maxheap, 5);
    InsertMaxHeap(maxheap, 5);
    InsertMaxHeap(maxheap, 6);InsertMaxHeap(maxheap, 6);InsertMaxHeap(maxheap, 6);
    maxheap.size = 99;
    PrintHeap(maxheap);
    return;
}

int main()
{
    //testLinkList();
    //testLinkQueue();
    //testStack();
    //testBinaryTree();
    testHeap();
    std::system("pause");
    return 0;
}
