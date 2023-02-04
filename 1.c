#include <stdio.h>
// Call by Value
void swap(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
// Call by reference
void swapref(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int a = 5, b = 10;
    swap(a, b);
    printf("\n call by val : %d, %d", a, b);
    swapref(&a, &b);
    printf("\n call by ref : %d, %d", a, b);
    return 0;
}