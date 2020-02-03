#include <stdio.h>
void to_base_n(int n, int m);
int main(void)
{
    int n, m, o;
    printf("Input a number:\n");
    scanf("%d", &n);
    printf("Input base number:\n");
    scanf("%d", &m);
    to_base_n(n, m);
    getchar();
    getchar();
    return 0;
}
void to_base_n(int n, int m)
{
    int r;
    r = n % m;
    if(n >= m)
    {
        to_base_n(n / m, m);
    }
    printf("%d", r);
}