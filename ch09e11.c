#include <stdio.h>

void fib(int n);

int main(void)
{
    int n;
    printf("Print a number:\n");
    scanf("%d", &n);
    fib(n);
    getchar();
    getchar();
    return 0;
}

void fib(int n) 
{
    int a = 1, b = 1, temp = 0;
    if (n >= 1)
    {
        printf("%d", a);
    }
    if (n >= 2)
    {
        printf(", %d", b);
    }
    for (int i = 2; i < n; i++) 
    {
        temp = a;
        a = b;
        b = temp + a;
        printf(", %d", b);
    }
}