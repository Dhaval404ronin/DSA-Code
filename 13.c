/*13. Write a program which create binary search tree.*/
#include <stdio.h>
#include <stdlib.h>
    struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL;
struct Node *RInsert(struct Node *p, int key)
{
    struct Node *t;
    if (p == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else
        p->rchild = RInsert(p->rchild, key);
    return p;
}
void Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}
void main()
{
    struct Node *temp;
    root = RInsert(root, 50);
    RInsert(root, 10);
    RInsert(root, 40);
    RInsert(root, 20);
    RInsert(root, 30);
    Inorder(root);
    printf("\n");
}