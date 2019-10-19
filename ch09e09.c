#include <stdio.h>
int power(int n, int m);
int main(void)
{
    int n, m, a;
    printf("Input a number:\n");
    scanf("%d", &n);
    printf("Input another number:\n");
    scanf("%d", &m);
    a = power(n, m);
    printf("%d", a);
    getchar();
    getchar();
    return 0;
}
int power(int n, int m)
{
    if(m > 1)
    {
        return n * power(n, m - 1);
    } else{
        return n;
    }
}