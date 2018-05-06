#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"
#include "tree.h"

void visit(PTreeNode n){
    printf("%c\t", n->data);
}

void preOrder(PTreeNode t)
{
    Stack *s = initStack();
    while(t || !isStackEmpty(s))
    {
        if(t)
        {
            // visit node
            visit(t);

            // save the visited node
            push(s, t);

            // prepare to visit the left tree
            t = t->lchild;
        }
        else
        {
            // pop the visited node
            ElemType e;
            pop(s, &e);
            t = e;

            // prepare to visit the right tree
            t = t->rchild;
        }
    }

}

void midOrder(PTreeNode t)
{
    Stack *s = initStack();
    while(t || !isStackEmpty(s))
    {
        if(t)
        {
            // save the node wating to visit
            push(s, t);

            // prepare to visit the left tree
            t = t->lchild;
        }
        else
        {
            // pop the node for visiting
            ElemType e;
            pop(s, &e);
            t = e;

            // visit node
            visit(t);

            // prepare to visit the right tree
            t = t->rchild;
        }
    }
}

typedef struct LTagNode
{
    PTreeNode node;

    // 0 mean to visit right tree
    // 1 mean to visit the node
    int tag;
}TagNode, *PTagNode;


PTagNode genTagNode(PTreeNode n) {
    if(!n)
        return NULL;

    PTagNode tn = (PTagNode)malloc(sizeof(TagNode));
    tn->node = n;
    tn->tag = 0;

    return tn;
}

void postOrder(PTreeNode t)
{
    PTagNode tn = genTagNode(t);

    Stack *s = initStack();
    while(tn || !isStackEmpty(s))
    {
        if(tn && tn->tag == 0)
        {
            push(s, tn);

            tn = genTagNode(tn->node->lchild);
        } else {
            // tn will point to the top of tree in the last
            if(isStackEmpty(s))
                return;

            ElemType e;
            pop(s, &e);
            tn = e;

            if(tn->tag == 0) {
                tn->tag = 1;
                push(s, tn);

                tn = genTagNode(tn->node->rchild);
            } else {
                visit(tn->node);

            }
        }
    }
}
