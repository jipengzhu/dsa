#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "tree.h"

typedef struct PosTNode
{
    PTreeNode node;
    int pos;
    int level;
} PosTreeNode, *PPosTreeNode;

PPosTreeNode genPosnode(PTreeNode n, int pos, int level)
{
    PPosTreeNode pn = (PPosTreeNode)malloc(sizeof(PosTreeNode));
    pn->node = n;
    pn->pos = pos;
    pn->level = level;

    return pn;
}

void printChar(char ch, int start, int pos)
{
    for (int i = start; i < pos; i++)
    {
        printf(" ");
    }

    printf("%c", ch);
}

void printTree(PTreeNode t, int root_pos)
{
    Queue *q = initQueue();
    enqueue(q, genPosnode(t, root_pos, 1));

    int pre_level = 1;
    int pre_pos = 0;
    while (!isQueueEmpty(q))
    {
        ElemType e;
        dequeue(q, &e);

        PPosTreeNode pn = e;
        PTreeNode n = pn->node;

        int pos = pn->pos;
        int level = pn->level;

        if (level != pre_level)
        {
            printf("\n");
            pre_level = level;
            pre_pos = 0;
        }

        printChar(n->data, pre_pos + 1, pos);
        pre_pos = pos;

        if (n->lchild)
        {
            PTreeNode l;
            if (level % 2 == 1)
            {
                l = (PTreeNode)malloc(sizeof(TreeNode));
                l->data = '/';
                l->lchild = n->lchild;
                l->rchild = NULL;
            }
            else
            {
                l = n->lchild;
            }

            enqueue(q, genPosnode(l, pos - 1, level + 1));
        }

        if (n->rchild)
        {
            PTreeNode r;
            if (level % 2 == 1)
            {
                r = (PTreeNode)malloc(sizeof(TreeNode));
                r->data = '\\';
                r->lchild = NULL;
                r->rchild = n->rchild;
            }
            else
            {
                r = n->rchild;
            }

            enqueue(q, genPosnode(r, pos + 1, level + 1));
        }
    }

    printf("\n");
}

void showTree(PTreeNode t)
{
    printf("\n");
    int depth = getDepth(t);
    printf("the tree depth is %i\n", depth);

    printf("the tree is\n");
    int root_pos = 2 * (depth - 1) + 1;
    printTree(t, root_pos);
    printf("\n");
}
