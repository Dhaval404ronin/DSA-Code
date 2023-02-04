/*6. Write a program to implement QUEUE using array that
performs following operations.
(a) INSERT (b) DELETE (c) DISPLAY*/
#include <stdio.h>
#define SIZE 10
typedef struct
{
    int arr[SIZE];
    int rear, front;
} Queue;
void enQueue(Queue *q, int no)
{
    if (q->rear >= SIZE - 1)
    {
        printf("\n Overflow");
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = no;
        if (q->front == -1)
        {
            q->front = 0;
        }
    }
}
int deQueue(Queue *q)
{
    int no;
    if (q->front == -1)
    {
        printf("\n Underflow");
    }
    else
    {
        no = q->arr[q->front];
        if (q->front == q->rear)
        {
            q->front = -1;
            q->rear = -1;
        }
        else
        {
            if (q->front == SIZE - 1)
                q->front = 0;
            else
                q->front++;
        }
    }

    return no;
}
void display(Queue *q)
{
    int f = q->front;
    int r = q->rear;
    if (f > r)
        r = r + SIZE;
    printf("\nQueue : ");
    for (int i = f; i <= r; i++)
    {
        printf("%d\t", q->arr[i % SIZE]);
    }
}
void main()
{
    Queue q;
    int x, op;
    q.front = -1;
    q.rear = -1;
    do
    {
        printf("\nQueue :1.Enqueue\t2.Dequeue\t3.Diplay\t4.Exit\t\nEnter your choice :");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\nEnter element :");
            scanf("%d", &x);
            enQueue(&q, x);
            break;
        case 2:
            x = deQueue(&q);
            printf("\nElement deleted is %d", x);
            break;
        case 3:
            display(&q);
            break;
        }
    } while (op != 4);
}