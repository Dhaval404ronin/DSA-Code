/*4. Write a program to convert infix notation to postfix notation
using stack (with parenthesis)*/
#include <stdio.h>
#include<ctype.h>
#define SIZE 10
typedef struct
{
int arr[10];
int top;
}stack;
void push(stack *s, int no)
{
if(s->top==SIZE-1)
{
printf("\nOverflow");
}
else
{
s->top++;
s->arr[s->top]=no;
}
}
int pop(stack *s)
{
if(s->top==-1)
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
if(s->top==-1)
{
return 0;
}
else
{
return s->arr[s->top];
}
}
int priority(char op)
{

switch(op)
{
case '^':
return 3;
case '*':
case '/':
return 2;
case '+':
case '-':
return 1;
default:
return -1;
}
}
int main(int argc, char const *argv[])
{
char exp[100], *ch, t;
stack op;
op.top=-1;
printf("\nEnter Expression : ");
scanf("%s",exp);
ch=exp;
while(*ch!='\0')
{
if(isalnum(*ch))
{
printf("%c",*ch); 
}
else if(*ch=='(')
{
push(&op,*ch);
}
else if(*ch==')')
{
do
{
t=pop(&op);
if(t!='(')
printf("%c",t);
}while(t!='(');
}
else
{
while(priority(peep(&op)) >= priority(*ch))
{
printf("%c",pop(&op));
}

push(&op,*ch);
}
ch++;
}
while(op.top!=-1)
{
printf("%c",pop(&op));
}
printf("\n");
return 0;
}