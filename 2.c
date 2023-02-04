/*2. Introduction to Dynamic Memory Allocation. DMA functions
malloc(), calloc(), realloc(), free().*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *a, *b, *ans;
    int n, i, addn;
    printf("Enter Number of element :");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    b = (int *)calloc(n, sizeof(int));
    ans = (int *)calloc(n, sizeof(int));
    for (i = 0; i < n; i++)
    {
        a[i] = i + 5;
        *(b + i) = i + 7;
        ans[i] = a[i] + *(b + i);
        printf("N%d = %d\n", (i + 1), ans[i]);
    }
    free(a);
    free(b);
    printf("Enter no of Addn :");
    scanf("%d", &addn);
    ans = (void *)realloc(ans, (n + addn) * sizeof(int));
    for (i = 0; i < addn; i++)
    {
        ans[n + i] = i + 100;
    }
    ans[n + i];

    for (i = 0; i < n + 2; i++)
    {
        printf("N[%d] = %d\n", (i + 1), ans[i]);
    }
    return 0;
}