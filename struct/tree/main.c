#include "queue.c"
#include "stack.c"
#include "tree.c"
#include "help.c"

int main()
{
    printf("please input abcd###e##f#gh### and press enter or return key\n");

    PTreeNode t;
    createTree(&t);

    showTree(t);

    printf("pre order traversal\n");
    preOrder(t);
    printf("\n");

    printf("mid order traversal\n");
    midOrder(t);
    printf("\n");

    printf("post order traversal\n");
    postOrder(t);
    printf("\n");

    printf("level order traversal\n");
    levelOrder(t);
    printf("\n");
}
