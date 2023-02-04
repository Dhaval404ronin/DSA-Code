/*11. Write a program to implement following operations on
    the circular linked list.
    (a)Insert a node at the front of the linked list.
    (b)Insert a node at the end of the linked list.
    (c)Insert a node at specified position.
    (d)Delete a first node of the linked list.
    (e)Delete a last node of the linked list.
    (f)Delete a node at specified position.*/
#include <stdio.h>
#include <stdlib.h>
    typedef struct node
{
    int data;
    struct node *next;
} node;
node *insertfront(node *head, int data)
{
    node *new, *ptr;
    new = (node *)malloc(sizeof(node));
    new->data = data;
    new->next = head;
    if (head == NULL)
    {
        head = new;
        head->next = head;
    }
    else
    {
        ptr = head;
        while (ptr->next != head)
            ptr = ptr->next;
        ptr->next = new;
        head = new;
    }
    return head;
}
node *insertend(node *head, int data)
{
    node *new, *ptr;
    new = (node *)malloc(sizeof(node));
    new->data = data;
    new->next = head;
    if (head == NULL)
    {
        head = new;
        head->next = head;
    }
    else
    {
        ptr = head;
        while (ptr->next != head)
            ptr = ptr->next;
        ptr->next = new;
    }
    return head;
}
node *insertpos(node *head, int data, int pos)
{
    node *new, *ptr, *preptr;
    int i;
    new = (node *)malloc(sizeof(node));
    new->data = data;
    preptr = head;
    ptr = head->next;
    for (i = 0; i < pos; i++)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = new;
    new->next = ptr;
    return head;
}
node *deletefront(node *head)
{
    node *ptr;
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        ptr = head;
        while (ptr->next != head)
            ptr = ptr->next;
            ptr -> next = head -> next;
        free(head);
        head = ptr -> next;
    }
    return head;
}
node *deleteend(node
                    *head)
{
    node *ptr,*preptr;
    if (head == NULL)
        return NULL;
    else if (head -> next == head)
    {
        ptr = head;
        head = NULL;
        free(ptr);
    }
    else
    {
        preptr = head;
        ptr = head -> next;
        while (ptr -> next !=
               head)
        {
            preptr = ptr;
            ptr = ptr -> next;
        }
        preptr -> next = head;
        free(ptr);
    }
    return head;
}
node *deletepos(node *head,int pos)
{
    node *ptr,*preptr;
    int i;
    if (head == NULL)
        return NULL;
    else
    {
        preptr = head;
        ptr = head -> next;
        for (
            i =
                0;
            i < pos;
            i++)
        {
            preptr = ptr;
            ptr = ptr -> next;
        }

        preptr->next = ptr->next;
        free(ptr);
        return head;
    }
}
void display(node *head)
{
    node *ptr = head;
    if (head != NULL)
    {
        printf("\n List : ");
        do
        {
            printf("%d \t", ptr->data);
            ptr = ptr->next;
        } while (ptr != head);
    }
}
int main()
{
    int ch, no, pos;
    node *head = NULL;
    do
    {
        printf("\nEnter Choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            scanf("%d", &no);
            head = insertfront(head, no);
            break;
        case 2:
            scanf("%d", &no);
            head = insertend(head, no);
            break;
        case 3:
            scanf("%d", &no);
            scanf("%d", &pos);
            head = insertpos(head, no, pos);
            break;
        case 4:
            head = deletefront(head);
            break;
         case 5:
            head = deleteend(head);
            break;
        case 6:
            scanf("%d", &pos);
            head = deletepos(head, pos);
            break;
        case 7:
            display(head);
            break;
        }
    } while (ch != 8);
    return 0;
}