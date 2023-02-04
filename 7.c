/*7. Write a program to implement Circular Queue using array
that performs following operations.
(a) INSERT (b) DELETE (c) DISPLAY*/
#include <stdio.h>
#define SIZE 10
typedef struct
{
    int arr[SIZE];
    int rear, front;
} CQueue;
void CQinsert(CQueue *cq, int no)
{
    if ((cq->rear + 1) % SIZE == cq->front)
    {
        printf("\n Queue is Overflow");
    }
    else
    {
        if (cq->rear == SIZE - 1)
        {
            cq->rear = 0;
        }
        else
        {
            cq->rear++;
        }
        cq->arr[cq->rear] = no;
        // If first time inserting the element
        if (cq->front == -1)
        {
            cq->front = 0;
        }
    }
}
int CQdelete(CQueue *cq)
{
    int no;
    if (cq->front == -1)
    {
        printf("\n Overflow");
        return -1;
    }
    else
    {
        no = cq->arr[cq->front];
        if (cq->front == cq->rear)
        {
            cq->front = cq->rear = -1;
        }
        else
        {
            if (cq->front == SIZE - 1)
                cq->front = 0;
            else
                cq->front++;
        }
        return no;
    }
}
void Display(CQueue *cq)
{
    int i;
    int f = cq->front;
    int r = cq->rear;
    if (f > r)
        r = r + SIZE;
    printf("\nQueue : ");
    for (i = f; i <= r; i++)
    {
        printf("%d\t", cq->arr[i % SIZE]);
    }
}
int main(int argc, char const *argv[])
{
    CQueue cq;
    int no, op;
    cq.front = -1;
    cq.rear = -1;
    do
    {
        printf("\n CQueue :1.Enqueue\t2.Dequeue\t3.Diplay\t4.Exit\n\nEnter your choice :");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\nEnter Element:");
            scanf("%d", &no);
            CQinsert(&cq, no);
            break;
        case 2:
            printf("\n Element Deleted is %d.", CQdelete(&cq));
            break;
        case 3:
            Display(&cq);
            break;
        }
    } while (op != 4);
    return 0;
}