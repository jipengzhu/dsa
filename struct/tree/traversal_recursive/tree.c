#include <stdio.h>
#include "queue.h"
#include "tree.h"

void visit(PTreeNode n)
{
    printf("%c\t", n->data);
}

void preOrder(PTreeNode n)
{
    if (n)
    {
        visit(n);
        preOrder(n->lchild);
        preOrder(n->rchild);
    }
}

void midOrder(PTreeNode n)
{
    if (n)
    {
        midOrder(n->lchild);
        visit(n);
        midOrder(n->rchild);
    }
}

void postOrder(PTreeNode n)
{
    if (n)
    {
        postOrder(n->lchild);
        postOrder(n->rchild);
        visit(n);
    }
}
