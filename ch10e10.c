#include <stdio.h>
void add_array(int * a, int * b, int * c, int * d);
int main(void)
{
    int a[4] = {2, 4, 5, 8};
    int b[4] = {1, 0, 4, 6};
    int c[4] = {0, 0, 0, 0};
    add_array(a, b, c, a + 4);
    getchar();
    getchar();
    return 0;
}
void add_array(int * a, int * b, int * c, int * d)
{
    while(a < d)
    {
        *c = *a + *b;
        printf("%d  ", *c);
        a++;
        b++;
        c++;
    }
}