#include <malloc.h>
#include <stdio.h>

#include <iostream>
using namespace std;

#define Elemtype char

#define initial_stack_size 100
#define increase_stack 10

typedef struct
{
    Elemtype *base;
    Elemtype *top;
    int stacksize;
} Stack;

void CreactStack(Stack &newstack)
{
    newstack.base = (Elemtype *)malloc(initial_stack_size * sizeof(Elemtype));
    if (newstack.base == NULL)
    {
        printf("内存分配失败\n");
        return;
    }
    newstack.top = newstack.base;
    newstack.stacksize = 0;
    printf("创建成功\n");
    return;
}

void PushStack(Stack &stack, Elemtype Date)
{
    if (stack.stacksize >= sizeof(stack.base))
    {
        printf("空间满\n");
        Elemtype *newbase = (Elemtype *)realloc(stack.base, (stack.stacksize + increase_stack) * sizeof(Elemtype));
        if (newbase == NULL)
        {
            printf("空间分配失败\n");
            return;
        }
        stack.base = newbase;
        printf("重新分配空间，增加%d个数据容量", increase_stack);
    }

    stack.top[0] = Date;
    stack.top++;
    stack.stacksize++;
    printf("插入%d成功\n", Date);
    return;
}

void PushStackDates(Stack &stack, Elemtype *Date, int num) {}

void PrintStack(Stack &stack)
{
    if (stack.stacksize > 0)
    {
        printf("共有%d个元素\n", stack.stacksize);
    }
    else
    {
        printf("无数据\n");
        return;
    }
    for (int i = 0; i < stack.stacksize; i++)
    {
        printf("%d ", stack.base[i]);
    }
    printf("\n");
}

void PopStack(Stack &stack)
{
    if (stack.top == stack.base)
    {
        printf("栈中无元素");
        return;
    }
    //stack.base[stack.stacksize - 2] += stack.base[stack.stacksize - 1];
    stack.top--;
    stack.stacksize--;
    printf("栈顶元素为%d，栈中还有%d个元素\n", stack.top[0], stack.stacksize);
    return;
}

int main()
{
    Stack stack;
    CreactStack(stack);
    PrintStack(stack);
    PushStack(stack, 5);
    PrintStack(stack);
    PushStack(stack, 5);
    PushStack(stack, 5);
    PushStack(stack, 5);
    PushStack(stack, 6);
    PrintStack(stack);
    PopStack(stack);
    PrintStack(stack);
    std::system("pause");
    return 0;
}