#include <stdio.h>
int fib(int n);
int main(void)
{
    int n, m, a;
    printf("Input a number:\n");
    scanf("%d", &n);
    a = fib(n);
    printf("%d", a);
    getchar();
    getchar();
    return 0;
}
int fib(int n)
{
    if(n <= 2)
    {
        return 1;
    }
    else
    { 
        return fib(n - 1) + fib(n - 2);
    }
}