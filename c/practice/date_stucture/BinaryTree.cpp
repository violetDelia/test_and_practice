#include <malloc.h>
#include <stdio.h>

#include <iostream>
using namespace std;

#define Elemtype int

typedef struct BinaryTreeNode
{
    Elemtype elem;
    BinaryTreeNode *rightchild;
    BinaryTreeNode *leftchild;
} BinaryTree;

void CreatBinaryTree(BinaryTreeNode *&newtree, Elemtype a)
{
    newtree = (BinaryTree *)malloc(sizeof(BinaryTree));
    if (newtree)
    {
        newtree->rightchild = NULL;
        newtree->leftchild = NULL;
        newtree->elem = a;
        printf("创建成功\n");
    }
    printf("创建失败\n");
    return;
}

bool visit(Elemtype Date)
{
    if (Date == '\0')
        return false;
    printf("%d", Date);
    return true;
}

bool PreOrderTree(BinaryTree *tree, bool (*visit)(Elemtype))
{
    if (tree)
    {
        if (visit(tree->elem))
            if (PreOrderTree(tree->rightchild, visit))
                if (PreOrderTree(tree->leftchild, visit))
                    return true;
        return false;
    }
    else
        return true;
}

bool MidOrderTree(BinaryTree *tree, bool (*visit)(Elemtype))
{
    if (tree)
    {
        if (MidOrderTree(tree->rightchild, visit))
            if (visit(tree->elem))
                if (MidOrderTree(tree->leftchild, visit))
                    return true;
        return false;
    }
    else
        return true;
}

bool PostOrderTree(BinaryTree *tree, bool (*visit)(Elemtype))
{
    if (tree)
    {
        if (PostOrderTree(tree->rightchild, visit))
            if (PostOrderTree(tree->leftchild, visit))
                if (visit(tree->elem))
                    return true;
        return false;
    }
    else
        return true;
}

void preOrder(BinaryTree *tree)
{
    printf("%d", tree->elem);
    preOrder(tree->rightchild);
    preOrder(tree->leftchild);
    return;
}

void MidOrder(BinaryTree *tree)
{
    MidOrder(tree->rightchild);
    printf("%d", tree->elem);
    MidOrder(tree->leftchild);
    return;
}

void postOrder(BinaryTree *tree)
{
    postOrder(tree->rightchild);
    postOrder(tree->leftchild);
    printf("%d", tree->elem);
    return;
}

int main()
{

    std::system("pause");
    return 0;
}