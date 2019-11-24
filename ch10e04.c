#include <stdio.h>
#define SIZE 5
int biggest(float * begin, float * end);
int main(void)
{
    float array[SIZE]= {12.3, 45.8, 2.9, 100.1, 45.7};
    int u;
    u = biggest(array, array + SIZE);
    printf("%d", u);
    getchar();
    getchar();
    return 0;
}
int biggest(float * begin, float * end)
{
    float * p = begin;
    float * mp = begin;
    while(p < end)
    {
        if(*p > *mp)
        {
            mp = p;
        }
        p++;
    }
    return mp - begin;
}