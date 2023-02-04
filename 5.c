/*5. Write a program for evaluation of postfix expression.*/
#include <stdio.h>
#include <ctype.h>
#define SIZE 10
typedef struct
{
    int arr[10];
    int top;
} stack;
void push(stack *s, int no)
{
    if (s->top == SIZE - 1)
    {
        printf("\nOverflow");
    }
    else
    {
        s->top++;
        s->arr[s->top] = no;
    }
}
int pop(stack *s)
{
    if (s->top == -1)
    {
        return 0;
    }
    else
    {
        int tmp = s->arr[s->top];
        s->top--;
        return tmp;
    }
}
int peep(stack *s)
{
    if (s->top == -1)
    {
        return 0;
    }
    else
    {
        return s->arr[s->top];
    }
}

int main()
{
    char exp[20];
    char *e;
    stack op;
    op.top =
        -1;
    int n1, n2, n3, num;
    printf("Enter the expression :: ");
    scanf("%s", exp);
    e = exp;
    while (*e != '\0')
    {
        if (isdigit(*e))
        {
            num = *e - 48;
            push(&op, num);
        }
        else
        {
            n2 = pop(&op);
            n1 = pop(&op);
            switch (*e)
            {
            case '+':
            {
                n3 = n1 + n2;
                break;
            }
            case '-':
            {
                n3 = n1 - n2;
                break;
            }
            case '*':
            {
                n3 = n1 * n2;
                break;
            }
            case '/':
            {

                n3 = n1 / n2;
                break;
            }
            }
            push(&op, n3);
        }
        e++;
    }
    printf("\nThe result of expression %s = %d\n\n", exp, pop(&op));
    return 0;
}