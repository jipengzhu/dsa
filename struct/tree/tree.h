#ifndef _H_TREE
#define _H_TREE

#include "queue.h"
#include "tree_elem.h"

void visit(PTreeNode n);
void preOrder(PTreeNode t);
void midOrder(PTreeNode t);
void postOrder(PTreeNode t);

void levelOrder(PTreeNode t)
{
    if (t)
    {
        Queue *q = initQueue();
        enqueue(q, t);

        while (!isQueueEmpty(q))
        {
            ElemType e;
            dequeue(q, &e);
            t = (PTreeNode)e;

            visit(t);

            if (t->lchild)
            {
                enqueue(q, t->lchild);
            }

            if (t->rchild)
            {
                enqueue(q, t->rchild);
            }
        }
    }
}

int getDepth(PTreeNode t)
{
    if (!t)
    {
        return 0;
    }
    else
    {
        int ldepth = getDepth(t->lchild);
        int rdepth = getDepth(t->rchild);

        int cdepth = ldepth > rdepth ? ldepth : rdepth;

        return cdepth + 1;
    }
}

void createTree(PTreeNode *t)
{
    char ch;

    scanf("%c", &ch);
    if (ch == '#')
    {
        *t = NULL;
    }
    else
    {
        *t = (PTreeNode)malloc(sizeof(TreeNode));
        if (!*t)
        {
            printf("malloc memory error");
            exit(-1);
        }

        (*t)->data = ch;

        createTree(&(*t)->lchild);
        createTree(&(*t)->rchild);
    }
}

#endif
