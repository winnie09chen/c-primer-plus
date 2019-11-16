#include <stdio.h>
int biggest(int * begin, int * end);
int main(void)
{
    int big;
    int ppc[8] = {1, 5, 6, 23, 45, 12, 434, 21};
    big = biggest(ppc, ppc + 8);
    printf("%d", big);
    getchar();
    getchar();
    return 0;
}
int biggest(int * begin, int * end)
{
    int u;
    u = *begin;
    while(begin < end)
    {
        if(*begin > u)
        {
            u = *begin;
        }
        begin++;
    }
    return u;
}