/*8. Write a menu driven program to implement following
operations on the singly linked list.
(a) Insert a node at the front of the linked list.
(b) Insert a node at the end of the linked list.
(c) Insert a node after a given element (value)
(d) Insert a node at a given position
(e) Delete a first node of the linked list.
(f) Delete a last node of the linked list.
(g) Delete a node at specified position.
(h) Delete a specified node (based on value).*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
node *InsertFront(node *head, int data)
{
    node *t;
    t = (node *)malloc(sizeof(node));
    t->data = data;
    t->next = head;
    head = t;
    return head;
}
node *InsertEnd(node *head, int data)
{
    node *new, *ptr;
    new = (node *)malloc(sizeof(node));
    new->data = data;
    new->next = NULL;
    if (head == NULL)
    {
        head = new;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = new;
    }

    return head;
}
node *InsertAfter(node *head, int data, int x)
{
    node *new, *preptr, *ptr;
    preptr = head;
    ptr = preptr->next;
    new = (node *)malloc(sizeof(node));
    new->data = data;
    while (preptr->data != x)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = new;
    new->next = ptr;
    return head;
}
node *InsertPos(node *head, int data, int pos)
{
    node *new, *ptr;
    ptr = head;
    new = (node *)malloc(sizeof(node));
    new->data = data;
    for (int i = 1; i < pos; i++)
    {
        ptr = ptr->next;
    }
    new->next = ptr->next;
    ptr->next = new;
    return head;
}
node *DeleteFirt(node *head)
{
    node *ptr;
    if (head = NULL)
        return NULL;
    else
    {
        ptr = head;
        head = head->next;
        free(ptr);
    }
    return head;
}
node *DeleteLast(node
                     *head)
{
    node *preptr, *ptr;
    preptr = head;
    ptr = preptr->next;
    if (head == NULL)
        return NULL;
    else
    {
        while (ptr -> next !=NULL)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next == NULL;
        free(ptr);
    }
    return head;
}
node *DeletePos(node *head,int pos)
{
    node
        *preptr,
        *ptr;
    if (head == NULL)
        return NULL;
    else
    {
        preptr = head;
        ptr = head->next;
        for (int i = 1; i < pos; i++)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
    }
    return head;
}
node *DeleteNode(node *head,int x)
{
    node*preptr,*ptr;
    if (head == NULL)
        return NULL;
    else
       
        {
            preptr = head;
            ptr = head->next;
            while (ptr->data != x)
            {
                preptr = ptr;
                ptr = ptr->next;
            }
            preptr->next = ptr->next;
            free(ptr);
            return head;
        }
}
void Display(node *head)
{
    node *ptr = head;
    if (head == NULL)
    {
        printf("Empty List");
    }
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}
void main()
{
    node *head = NULL;
    int no, choice, x;
printf("Enter 1.Insert front \t2.Insert end \t3.Insert After given element \t4.Insert given position \n \t5.Delete firt \t6.Delete last \t7.Delete at position \t8.Delete node(value) \n \t 9.Display \t10.break");
do
{
        printf("\n Enter Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            scanf("%d", &no);
            head = InsertFront(head, no);
            break;
        case 2:
            scanf("%d", &no);
            head = InsertEnd(head, no);
            break;
        case 3:
            scanf("%d", &no);
            scanf("%d", &x);
            head = InsertAfter(head, no, x);
            break;
        case 4:
            scanf("%d", &no);
            scanf("%d", &x);
            head = InsertPos(head, no, x);
            break;
        case 5:
            head = DeleteFirt(head);
            break;
        case 6:
            head = DeleteLast(head);
            break;
        case 7:
            scanf("%d", &x);
            head = DeletePos(head, x);
            break;
        case 8:
            scanf("%d", &x);
            head = DeleteNode(head, x);
            break;
        case 9:
            Display(head);
            break;
        }
}while(choice != 10);
}