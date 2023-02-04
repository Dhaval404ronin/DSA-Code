/*3. Write a program of stack that performs following operations
using array. (a) PUSH (b) POP (c) PEEP (d) CHANGE (e)
DISPLAY*/
#include <stdio.h>
#define SIZE 10
typedef struct
{
    int arr[SIZE];
    int top;
} stack;
void PUSH(stack *s, int no)
{
    if (s->top == SIZE - 1)
    {
        printf("\n stack is overflow ");
    }
    else
    {
        s->top++;
        s->arr[s->top] = no;
    }
}
int POP(stack *s)
{
    if (s->top == -1)
    {
        printf("\n stack is empty ");
        return -1;
    }
    else
    {
        s->top--;
        return s->arr[s->top + 1];
    }
}
int PEEP(stack *s)
{
    if (s->top == -1)
    {
        printf("\n stack is empty ");
        return -1;
    }
    else
    {
        return s->arr[s->top];
    }
}
void DISPLAY(stack *s)
{
    for (int i = s->top; i >= 0; i--)
    {
        printf("\n %d", s->arr[i]);
    }
}
void CHANGE(stack *s, int no, int new)
{
    for (int i = s->top; i >= 0; i--)
    {
        if (i == no - 1)
        {
            s->arr[no - 1] = new;
        }
    }
}
void main()
{
    stack s;
    int no, ch, new;
    s.top = -1;
    do
    {
        printf("\n1. Push\t2. Pop\t3. Peep\t4. Display\t5. Change\t6. Exit ");
        printf("\nEnter Choice ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter Number : ");
            scanf("%d", &no);
            PUSH(&s, no);
            break;
        case 2:
            no = POP(&s);
            printf("\nPop %d : ", no);
            break;
        case 3:
            no = PEEP(&s);
            printf("\nPeep %d : ", no);
            break;
        case 4:
            DISPLAY(&s);
            break;
        case 5:
            printf("\nEnter possition : ");
            scanf("%d", &no);
            printf("\nEnter new Number : ");
            scanf("%d", &new);

            CHANGE(&s, no, new);
            break;
        }
    } while (ch != 6);
}