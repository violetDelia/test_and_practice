#include <iostream>
#include <malloc.h>
#include <stdio.h>
using namespace std;

#define ture true

#define Elemtype char //Ԫ������
#define Elemtype_Max CHAR_MAX
#define Elemtype_Min CHAR_MIN
//
//���Ա�
//
#define initial_list_size 100 //�������Ա�Ԫ��������ʼ����ռ�
#define increase_list 20

struct LinerList //���Ա�ṹ
{
    Elemtype *elem; //Ԫ������
    int length;     //Ԫ�صĸ���
    int Listsize;   //����ǰ�Ŀռ�
};

bool creatLinerlist(LinerList &newlist) //�����µ����Ա�
{
    newlist.elem = (Elemtype *)malloc(initial_list_size * sizeof(Elemtype)); //Ϊ�������ռ�
    if (newlist.elem == NULL)                                                //����ڴ����ʧ��
    {
        printf("����ռ�ʧ��");
        return false;
    }
    newlist.length = 0;
    newlist.Listsize = initial_list_size;
    return true;
}

void testLinerList() {}
//
///����
//
typedef struct LinkListNode
{
    Elemtype elem;
    struct LinkListNode *next;
} LinkList;

bool CreatLinkList(LinkList *&newlist, int num) //����һ����num��Ԫ�ص��±�,ͷ�巨
{
    newlist = (LinkList *)malloc(sizeof(LinkList));
    if (newlist == NULL)
    {
        printf("����ͷ���ʧ��\n");
        return false;
    }
    newlist->elem = 0;
    newlist->next = newlist;
    printf("����%d������ͷ��������\n", num);
    for (int i = 1; i <= num; i++)
    {
        LinkList *Node = (LinkList *)malloc(sizeof(LinkList));
        if (Node == NULL)
        {
            printf("��%d��Ԫ�ط���ռ�ʧ��\n", i);
            return false;
        }
        scanf("%d", &Node->elem);
        Node->next = newlist->next;
        newlist->next = Node;
        (int)newlist->elem++;
    }
    return true;
}

void PrintLinkList(LinkList *list) //��ǰ�����������Ԫ��
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

void ReplaceLinklistNode(LinkList *list, int i, Elemtype &Date) //��Date��ֵ����list�ĵ�i��Ԫ��
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

void InsertLinkList(LinkList *list, int i, Elemtype &Date) //��Date����list��i��Ԫ��֮ǰ
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

void DeleteLinkList(LinkList *list, int i) //ɾ�������е�i��Ԫ��
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

void MergeLinkList(LinkList *list1, LinkList *list2) //��list2�ӵ�list1����
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

bool SortList(LinkList *list, bool (*compare)(Elemtype, Elemtype)) { return true; }

bool Compare(Elemtype, Elemtype) { return true; }

void testLinkList()
{
    LinkList *list;
    CreatLinkList(list, 4);
    PrintLinkList(list);
    Elemtype a = 5;
    ReplaceLinklistNode(list, 5, a);
    ReplaceLinklistNode(list, 4, a);
    PrintLinkList(list);
    Elemtype b = 4;
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
    return;
}
//
//��̬����
//
#define SLinkList_MaxSize

typedef struct SLinkListNode
{
    Elemtype elem;
    int position;
} SLinkList;

void testSLinkList() {}
//
//ջ
//
#define initial_stack_size 100
#define increase_stack 10

struct Stack
{
    Elemtype *base;
    Elemtype *top;
    int stacksize;
};

void CreactStack(Stack &newstack)
{
    newstack.base = (Elemtype *)malloc(initial_stack_size * sizeof(Elemtype));
    if (newstack.base == NULL || &newstack.stacksize == NULL)
    {
        printf("�ڴ����ʧ��\n");
        return;
    }
    newstack.top = newstack.base;
    newstack.stacksize = 0;
    printf("����ջ�ɹ�\n");
    return;
}

bool PushStack(Stack stack, Elemtype Date)
{
    if (stack.stacksize >= sizeof(stack.base))
    {
        printf("�ռ���\n");
        Elemtype *newbase = (Elemtype *)realloc(stack.base, (stack.stacksize + increase_stack) * sizeof(Elemtype));
        if (newbase == NULL)
        {
            printf("�ռ����ʧ��\n");
            return false;
        }
        stack.base = newbase;
        printf("���·���ռ䣬����%d����������", increase_stack);
    }

    stack.top[0] = Date;
    stack.top++;
    stack.stacksize++;
    printf("����%d�ɹ�\n", Date);
    return true;
}

void PushStackDates(Stack stack, Elemtype *Date, int num) {}

void PrintStack(Stack stack)
{
    if (stack.stacksize > 0)
    {
        printf("����%d��Ԫ��\n", stack.stacksize);
    }
    else
    {
        printf("������\n");
        return;
    }
    for (int i = 0; i < stack.stacksize; i++)
    {
        printf("%d ", stack.base[i]);
    }
    printf("\n");
}

Elemtype PopStack(Stack stack)
{
    if (stack.top == stack.base)
    {
        printf("ջ����Ԫ��");
        return '\0';
    }
    //stack.base[stack.stacksize - 2] += stack.base[stack.stacksize - 1];
    stack.top--;
    stack.stacksize--;
    if (stack.stacksize)
    {
        printf("ɾ��%d�ɹ���ջ��Ԫ��Ϊ%d��ջ�л���%d��Ԫ��\n",
               stack.top[0], stack.top[-1], stack.stacksize);
        return stack.top[0];
    }
    printf("ɾ��%d�ɹ�,ջ������Ԫ��\n", stack.top[0]);
    return stack.top[0];
}

void testStack()
{
    Stack stack;
    CreactStack(stack);
    PrintStack(stack);
    PushStack(stack, 1);
    PrintStack(stack);
    PushStack(stack, 2);
    PushStack(stack, 3);
    PushStack(stack, 5);
    PushStack(stack, 6);
    PrintStack(stack);
    PrintStack(stack);
    PopStack(stack);
    PrintStack(stack);
    PopStack(stack);
    PrintStack(stack);
    PopStack(stack);
    PopStack(stack);
    PrintStack(stack);
    return;
}
//
//��ʽ����
//
struct LinkQueueNode
{
    Elemtype elem;
    LinkQueueNode *next;
};

struct HeadLinkQueue
{
    LinkQueueNode *front;
    LinkQueueNode *rear;
};

void CreatLinkQueue(HeadLinkQueue &newqueue)
{
    newqueue.front = newqueue.rear = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    if (newqueue.front == NULL)
    {
        printf("����ʧ��\n");
        return;
    }
    newqueue.front->next = NULL;
    printf("���������гɹ�\n");
    return;
}

void PrintLinkQueue(HeadLinkQueue queue)
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
        printf("\t����%d������\n", i);
        return;
    }
    printf("������Ԫ��\n");
    return;
}

void InsertLinkQuere(HeadLinkQueue queue, Elemtype Date)
{
    LinkQueueNode *Node = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    if (Node)
    {
        Node->next = NULL;
        Node->elem = Date;
        queue.rear->next = Node;
        queue.rear = Node;
        printf("����ɹ�\n");
        return;
    }
    printf("����ռ���󣬲���ʧ��\n");
    return;
}

Elemtype DeleteLinkQuere(HeadLinkQueue &queue)
{
    LinkQueueNode *Node = queue.front;
    queue.front = queue.front->next;
    free(Node);
    printf("ɾ��%c�ɹ�\n", queue.front->elem);
    return queue.front->elem;
}

void testLinkQueue()
{
    HeadLinkQueue queue;
    CreatLinkQueue(queue);
    PrintLinkQueue(queue);
    InsertLinkQuere(queue, 's');
    InsertLinkQuere(queue, 'l');
    InsertLinkQuere(queue, 'a');
    InsertLinkQuere(queue, 'v');
    InsertLinkQuere(queue, 'e');
    PrintLinkQueue(queue);
    DeleteLinkQuere(queue);
    DeleteLinkQuere(queue);
    PrintLinkQueue(queue);
    return;
}
//
//������
//
typedef struct BinaryTreeNode
{
    Elemtype elem;
    int layer;
    int order;
    BinaryTreeNode *father;
    BinaryTreeNode *rightchild;
    BinaryTreeNode *leftchild;
} BinaryTree;

typedef struct BinaryTreeStack
{
    BinaryTreeNode *base;
    BinaryTreeNode *top;
    int size;
} TreeStack;

typedef struct BinaryTreeLinkQueueNode
{
    BinaryTree *elem;
    BinaryTreeLinkQueueNode *next;
} TreeQueue;

typedef struct BinaryTreeLinkQueueHead
{
    BinaryTreeLinkQueueNode *front;
    BinaryTreeLinkQueueNode *rear;
} TreeQueueHead;

bool visit(BinaryTree *tree)
{
    if (tree)
    {
        printf("%d ", tree->elem);
        return true;
    }
    return false;
}

bool CreactTreeQueue(BinaryTreeLinkQueueHead *&newqueue)
{
    newqueue->front = newqueue->rear = (BinaryTreeLinkQueueNode *)malloc(sizeof(BinaryTreeLinkQueueNode));
    if (newqueue->front || newqueue->rear)
    {
        newqueue->front->next = NULL;
        //printf("���������гɹ�\n");
        return true;
    }
    printf("����ռ�ʧ��\n");
    return false;
}

bool InsertTreeQuere(BinaryTreeLinkQueueHead *queue, BinaryTree *Date)
{
    BinaryTreeLinkQueueNode *Node = (BinaryTreeLinkQueueNode *)malloc(sizeof(BinaryTreeLinkQueueNode));
    if (Node)
    {
        Node->next = NULL;
        Node->elem = Date;
        queue->rear->next = Node;
        queue->rear = Node;
        //printf("����ɹ�\n");
        return true;
    }
    printf("����ռ���󣬲���ʧ��\n");
    return false;
}

bool EmptyTreeQuere(BinaryTreeLinkQueueHead *queue)
{
    if (queue->front == queue->rear)
        return true;
    return false;
}

BinaryTree *DeleteTreeQuere(BinaryTreeLinkQueueHead *&queue)
{
    BinaryTreeLinkQueueNode *Node = queue->front;
    queue->front = queue->front->next;
    free(Node);
    if (queue->front->elem != NULL)
        return queue->front->elem;
    return queue->rear->elem;
}

bool QueueTree(BinaryTree *tree)
{
    if (!tree)
    {
        printf("����\n");
        return false;
    }
    BinaryTreeLinkQueueHead *queue;
    CreactTreeQueue(queue);
    InsertTreeQuere(queue, tree);
    while (!EmptyTreeQuere(queue))
    {
        tree = DeleteTreeQuere(queue);
        if (!visit(tree))
        {
            printf("���ݴ���\n");
            return false;
        }
        if (tree->leftchild)
            InsertTreeQuere(queue, tree->leftchild);
        if (tree->rightchild)
            InsertTreeQuere(queue, tree->rightchild);
    }
    return true;
}

bool CreactTreeStack(TreeStack &newstack)
{
    newstack.base = (BinaryTree *)malloc(sizeof(BinaryTree) * initial_stack_size);
    if (&newstack.size == NULL || newstack.base == NULL)
    {
        printf("�ռ����ʧ��\n");
        return false;
    }
    newstack.size = 0;
    newstack.top = newstack.base;
    //printf("����ջ�ɹ�\n");
    return true;
}

bool PushTreeStack(TreeStack stack, BinaryTree *Date)
{
    if (stack.size >= sizeof(stack.base))
    {
        printf("�ռ���\n");
        BinaryTree *newbase = (BinaryTree *)realloc(stack.base, (stack.size + increase_stack) * sizeof(BinaryTree));
        if (newbase == NULL)
        {
            printf("�ռ����ʧ��\n");
            return false;
        }
        stack.base = newbase;
        //printf("���·���ռ䣬����%d����������", increase_stack);
    }

    stack.top->elem = Date->elem;
    stack.top->father = Date->father;
    stack.top->layer = Date->layer;
    stack.top->leftchild = Date->leftchild;
    stack.top->order = Date->order;
    stack.top->rightchild = Date->rightchild;
    stack.top++;
    stack.size++;
    //printf("����%d�ɹ�\n", Date->elem);
    return true;
}

BinaryTree *PopTreeStack(TreeStack stack)
{
    if (stack.top == stack.base)
    {
        //printf("ջ����Ԫ��");
        return NULL;
    }
    //stack.base[stack.stacksize - 2] += stack.base[stack.stacksize - 1];
    stack.top--;
    stack.size--;
    if (stack.size)
    {
        //printf("ɾ��%d�ɹ���ջ��Ԫ��Ϊ%d��ջ�л���%d��Ԫ��\n",
        //       stack.top->elem, (stack.top-1)->elem, stack.size);
        return stack.top;
    }
    //printf("ɾ��%d�ɹ�,ջ������Ԫ��\n", stack.top->elem);
    return stack.top;
}

bool MidStackTree(BinaryTree *tree)
{
    if (!tree)
    {
        printf("����\n");
        return false;
    }
    TreeStack treestcak;
    CreactTreeStack(treestcak);
    while (tree || treestcak.size)
    {
        if (tree)
        {
            PushTreeStack(treestcak, tree);
            tree = tree->leftchild;
        }
        else
        {
            tree = PopTreeStack(treestcak);
            if (!visit(tree))
                return false;
            //printf("%d " ,tree->elem);
            tree = tree->rightchild;
        }
    }
    printf("\n");
    return true;
}

bool CreatTreeHead(BinaryTreeNode *&newtree, Elemtype Date)
{
    newtree = (BinaryTree *)malloc(sizeof(BinaryTree));
    if (newtree)
    {
        newtree->father = NULL;
        newtree->layer = 1;
        newtree->order = 1;
        newtree->rightchild = NULL;
        newtree->leftchild = NULL;
        newtree->elem = Date;
        printf("�������ɹ�\n");
        return false;
    }
    printf("����ʧ��\n");
    return true;
}

bool InsertBinaryTree(BinaryTree *tree, Elemtype Date, int L, int O)
{
    BinaryTree *Node = (BinaryTree *)malloc(sizeof(BinaryTree));
    if (Node)
    {
        BinaryTree *location = tree;
        Stack position;
        CreactStack(position);
        int o = O;
        for (int i = L - 1; i; i--)
        {
            PushStack(position, O % 2);
            O = (O > 1) + O % 2;
        }
        Node->father = location;
        for (int i = 0; i < L - 2; i++)
        {
            if (PopStack(position))
            {
                location = location->rightchild;
                if (location == NULL)
                {
                    free(Node);
                    printf("�޴�λ��\n");
                    return false;
                }
            }
            else
            {
                location = location->leftchild;
                if (location == NULL)
                {
                    free(Node);
                    printf("�޴�λ��\n");
                    return false;
                }
            }
        }
        if (PopStack(position))
        {
            if (location->rightchild == NULL)
            {
                location->rightchild = Node;
            }
            else
            {
                location->rightchild->elem = Date;
                printf("����%d�滻�ɹ�,���ݴ���%d���%d�����\n",
                       Date, location->rightchild->layer, location->rightchild->order);
                free(Node);
                return true;
            }
        }
        else
        {
            if (location->leftchild == NULL)
            {
                location->leftchild = Node;
            }
            else
            {
                location->leftchild->elem = Date;
                free(Node);
                printf("����%d�滻�ɹ�,���ݴ���%d���%d�����\n",
                       Date, location->leftchild->layer, location->leftchild->order);
                return true;
            }
        }
        Node->leftchild = NULL;
        Node->rightchild = NULL;
        Node->elem = Date;
        Node->layer = L;
        Node->order = o;
        printf("���ݷ���%d�ɹ������ݴ��ڵ�%d���%d�����\n",
               Node->elem, Node->layer, Node->order);
        return true;
    }
    printf("�ռ����ʧ��\n");
    return false;
}

bool PreOrderTree(BinaryTree *tree)
{
    if (tree)
    {
        if (visit(tree))
            if (PreOrderTree(tree->rightchild))
                if (PreOrderTree(tree->leftchild))
                    return true;
        return false;
    }
    else
        return true;
}

bool MidOrderTree(BinaryTree *tree)
{
    if (tree)
    {
        if (MidOrderTree(tree->rightchild))
            if (visit(tree))
                if (MidOrderTree(tree->leftchild))
                    return true;
        return false;
    }
    else
        return true;
}

bool PostOrderTree(BinaryTree *tree)
{
    if (tree)
    {
        if (PostOrderTree(tree->rightchild))
            if (PostOrderTree(tree->leftchild))
                if (visit(tree))
                    return true;
        return false;
    }
    else
        return true;
}

void preOrder(BinaryTree *tree)
{
    if (tree)
    {
        printf("%d ", tree->elem);
        preOrder(tree->rightchild);
        preOrder(tree->leftchild);
        return;
    }
    return;
}

void MidOrder(BinaryTree *tree)
{
    if (tree)
    {
        MidOrder(tree->rightchild);
        printf("%d ", tree->elem);
        MidOrder(tree->leftchild);
        return;
    }
    return;
}

void postOrder(BinaryTree *tree)
{
    if (tree)
    {
        postOrder(tree->rightchild);
        postOrder(tree->leftchild);
        printf("%d ", tree->elem);
        return;
    }
    return;
}

bool freeTreeNode(BinaryTree *Node)
{
    if (Node)
    {
        free(Node);
        return true;
    }
    return false;
}

bool freeTree(BinaryTree *tree)
{
    if (tree)
    {
        if (freeTree(tree->rightchild))
            if (freeTree(tree->leftchild))
                if (freeTreeNode(tree))
                    return true;
        return false;
    }
    else
        return true;
}

void InsertTree(BinaryTree *tree, Elemtype Date)
{
    BinaryTree *position = NULL;
    do
    {
        if (tree->elem > Date)
        {
            position = tree;
            tree = tree->leftchild;
        }
        else if (tree->elem < Date)
        {
            position = tree;
            tree = tree->rightchild;
        }
        else
        {
            if (tree->elem == Date)
            {
                printf("�����Ѵ���\n");
                return;
            }
        }
    } while (tree);
    BinaryTree *Node = (BinaryTree *)malloc(sizeof(BinaryTree));
    if (position->elem > Date)
    {
        position->leftchild = Node;
        Node->elem = Date;
        Node->father = position;
        Node->layer = position->layer + 1;
        Node->order = position->order * 2 - 1;
        Node->leftchild = Node->rightchild = NULL;
        printf("���ݲ���%d�ɹ������ݴ��ڵ�%d���%d�����\n",
               Node->elem, Node->layer, Node->order);
        return;
    }
    position->rightchild = Node;
    Node->elem = Date;
    Node->father = position;
    Node->layer = position->layer + 1;
    Node->order = position->order * 2;
    Node->leftchild = Node->rightchild = NULL;
    printf("���ݲ���%d�ɹ������ݴ��ڵ�%d���%d�����\n",
           Node->elem, Node->layer, Node->order);
    return;
}

bool SearchTreeNode(BinaryTree *tree, Elemtype Date)
{
    BinaryTree *position = NULL;
    while (tree)
    {
        if (tree->elem > Date)
        {
            position = tree;
            tree = tree->leftchild;
        }
        else if (tree->elem < Date)
        {
            position = tree;
            tree = tree->rightchild;
        }
        else
        {
            if (tree->elem == Date)
            {
                printf("���ݴ���\n");
                return true;
            }
        }
    }
    printf("���ݲ�����\n");
    return false;
}

void testBinaryTree()
{
    BinaryTree *tree;
    CreatTreeHead(tree, 1);
    InsertBinaryTree(tree, 2, 2, 1);
    InsertBinaryTree(tree, 3, 2, 2);
    InsertBinaryTree(tree, 4, 3, 1);
    InsertBinaryTree(tree, 5, 3, 2);
    InsertBinaryTree(tree, 6, 3, 3);
    InsertBinaryTree(tree, 5, 3, 3);
    InsertBinaryTree(tree, 0, 5, 5);
    InsertBinaryTree(tree, 0, 2, 2);
    preOrder(tree);
    printf("\n");
    MidOrder(tree);
    printf("\n");
    postOrder(tree);
    printf("\n");
    PreOrderTree(tree);
    printf("\n");
    MidOrderTree(tree);
    printf("\n");
    PostOrderTree(tree);
    printf("\n");
    freeTree(tree);
    CreatTreeHead(tree, 10);
    InsertTree(tree, 5);
    InsertTree(tree, 15);
    InsertTree(tree, 7);
    InsertTree(tree, 30);
    InsertTree(tree, 30);
    InsertTree(tree, 3);
    SearchTreeNode(tree, 3);
    SearchTreeNode(tree, 4);
    MidStackTree(tree);
    QueueTree(tree);
    return;
}

int main()
{
    //testLinkList();
    //testLinkQueue();
    //testStack();
    testBinaryTree();
    std::system("pause");
    return 0;
}